import { Component, OnDestroy } from '@angular/core';
import { ApiService } from '../services/api.service';
import { RealtimeService } from '../services/realtime.service';

interface ContactRow { name?: string; email?: string; message?: string; createdAt?: string; }
type FieldType = 'text' | 'textarea' | 'number' | 'bool' | 'select' | 'lines' | 'tags' | 'urls' | 'creds' | 'images' | 'icon';
interface Field { key: string; label: string; type: FieldType; options?: string[]; }
type Col = 'contacts' | 'projects' | 'experience' | 'education' | 'certifications' | 'skills' | 'testimonials' | 'config' | 'analytics';

@Component({
  selector: 'app-admin',
  templateUrl: './admin.component.html',
  styleUrls: ['./admin.component.scss'],
})
export class AdminComponent implements OnDestroy {
  private rtDispose: (() => void) | null = null;
  liveOn = false;

  // ── Login ────────────────────────────────────────────────────────────────
  private readonly USER = 'root';
  private readonly PASS = 'raizz';
  user = '';
  pass = '';
  authed = false;
  loginError = '';

  // ── Datos ────────────────────────────────────────────────────────────────
  loading = false;
  error = '';
  contacts: ContactRow[] = [];
  projects: any[] = [];
  experience: any[] = [];
  education: any[] = [];
  certifications: any[] = [];
  skills: any[] = [];
  testimonials: any[] = [];
  config: any[] = [];
  analytics: any[] = [];
  active: Col = 'contacts';

  // ── Editor ───────────────────────────────────────────────────────────────
  editorOpen = false;
  editingCol: Col | null = null;
  editingId: string | null = null;
  form: any = {};
  text: Record<string, string> = {}; // buffers para lines/tags/urls
  saving = false;
  saveError = '';

  readonly schemas: Record<string, Field[]> = {
    projects: [
      { key: 'title', label: 'Título', type: 'text' },
      { key: 'subtitle', label: 'Subtítulo', type: 'text' },
      { key: 'desc', label: 'Descripción', type: 'textarea' },
      { key: 'why', label: '¿Por qué? (opcional)', type: 'textarea' },
      { key: 'highlights', label: 'Puntos clave (uno por línea)', type: 'lines' },
      { key: 'tags', label: 'Tecnologías (separadas por coma)', type: 'tags' },
      { key: 'repo', label: 'Repositorio (URL, opcional)', type: 'text' },
      { key: 'screenshots', label: 'Capturas', type: 'images' },
      { key: 'urls', label: 'Enlaces (formato: etiqueta | url | descripción)', type: 'urls' },
      { key: 'credentials', label: 'Credenciales demo', type: 'creds' },
      { key: 'order', label: 'Orden', type: 'number' },
      { key: 'active', label: 'Activo (visible en la CV)', type: 'bool' },
    ],
    skills: [
      { key: 'category', label: 'Categoría', type: 'select', options: ['front', 'back', 'hard'] },
      { key: 'name', label: 'Nombre', type: 'text' },
      { key: 'icon', label: 'Icono (sube uno o pega una URL)', type: 'icon' },
      { key: 'order', label: 'Orden', type: 'number' },
      { key: 'active', label: 'Activo', type: 'bool' },
    ],
    experience: [
      { key: 'role', label: 'Cargo', type: 'text' },
      { key: 'org', label: 'Organización', type: 'text' },
      { key: 'location', label: 'Ubicación', type: 'text' },
      { key: 'period', label: 'Periodo', type: 'text' },
      { key: 'current', label: 'Actual', type: 'bool' },
      { key: 'bullets', label: 'Detalles (uno por línea)', type: 'lines' },
      { key: 'order', label: 'Orden', type: 'number' },
      { key: 'active', label: 'Activo', type: 'bool' },
    ],
    education: [
      { key: 'degree', label: 'Título', type: 'text' },
      { key: 'institution', label: 'Institución', type: 'text' },
      { key: 'year', label: 'Año', type: 'text' },
      { key: 'icon', label: 'Icono (clase bi-*)', type: 'text' },
      { key: 'highlight', label: 'Destacado', type: 'bool' },
      { key: 'order', label: 'Orden', type: 'number' },
      { key: 'active', label: 'Activo', type: 'bool' },
    ],
    certifications: [
      { key: 'name', label: 'Nombre', type: 'text' },
      { key: 'detail', label: 'Detalle', type: 'text' },
      { key: 'year', label: 'Año', type: 'text' },
      { key: 'icon', label: 'Icono (clase bi-*)', type: 'text' },
      { key: 'order', label: 'Orden', type: 'number' },
      { key: 'active', label: 'Activo', type: 'bool' },
    ],
    testimonials: [
      { key: 'name', label: 'Nombre', type: 'text' },
      { key: 'role', label: 'Cargo / relación', type: 'text' },
      { key: 'text', label: 'Testimonio', type: 'textarea' },
      { key: 'avatar', label: 'Foto (sube una o pega URL)', type: 'icon' },
      { key: 'order', label: 'Orden', type: 'number' },
      { key: 'active', label: 'Activo', type: 'bool' },
    ],
    config: [
      { key: 'email', label: 'Email', type: 'text' },
      { key: 'whatsapp', label: 'WhatsApp — número internacional (ej. 573001234567)', type: 'text' },
      { key: 'whatsappLabel', label: 'WhatsApp — texto visible', type: 'text' },
      { key: 'github', label: 'GitHub (URL)', type: 'text' },
      { key: 'githubLabel', label: 'GitHub — texto visible', type: 'text' },
      { key: 'instagram', label: 'Instagram (URL)', type: 'text' },
      { key: 'instagramLabel', label: 'Instagram — texto visible', type: 'text' },
    ],
  };

  constructor(private api: ApiService, private rt: RealtimeService) {
    if (sessionStorage.getItem('cv_admin') === '1') {
      this.authed = true;
      this.loadAll();
      this.startRealtime();
    }
  }

  ngOnDestroy(): void { this.stopRealtime(); }

  // ── Auth ───────────────────────────────────────────────────────────────
  login(): void {
    if (this.user === this.USER && this.pass === this.PASS) {
      this.authed = true;
      this.loginError = '';
      sessionStorage.setItem('cv_admin', '1');
      this.loadAll();
      this.startRealtime();
    } else {
      this.loginError = 'Usuario o contraseña incorrectos';
    }
  }
  logout(): void {
    this.stopRealtime();
    this.authed = false;
    this.user = '';
    this.pass = '';
    sessionStorage.removeItem('cv_admin');
  }

  // ── Realtime ───────────────────────────────────────────────────────────
  private startRealtime(): void {
    if (this.rtDispose) return;
    this.rtDispose = this.rt.subscribe('contacts', (change) => {
      if (change.event === 'inserted' && change.data) {
        this.contacts = this.byDateDesc([change.data, ...this.contacts]);
      } else {
        this.api.list<ContactRow>('contacts').subscribe(d => this.contacts = this.byDateDesc(d));
      }
      this.liveOn = true;
    });
  }
  private stopRealtime(): void {
    if (this.rtDispose) { this.rtDispose(); this.rtDispose = null; }
    this.liveOn = false;
  }

  // ── Carga ──────────────────────────────────────────────────────────────
  private loadAll(): void {
    this.loading = true;
    this.error = '';
    this.api.list<ContactRow>('contacts').subscribe({
      next: d => { this.contacts = this.byDateDesc(d); this.loading = false; },
      error: () => { this.error = 'No se pudo conectar con la API'; this.loading = false; },
    });
    this.api.list('projects').subscribe(d => this.projects = this.byOrder(d));
    this.api.list('experience').subscribe(d => this.experience = this.byOrder(d));
    this.api.list('education').subscribe(d => this.education = this.byOrder(d));
    this.api.list('certifications').subscribe(d => this.certifications = this.byOrder(d));
    this.api.list('skills').subscribe(d => this.skills = this.byOrder(d));
    this.api.list('testimonials').subscribe(d => this.testimonials = this.byOrder(d));
    this.api.list('config').subscribe(d => this.config = d);
    this.api.list('analytics').subscribe(d => this.analytics = d);
  }

  // ── Agregaciones de analítica ──────────────────────────────────────────
  get totalVisits(): number { return this.analytics.filter(a => a.type === 'visit').length; }
  get visitsToday(): number {
    const today = new Date().toISOString().slice(0, 10);
    return this.analytics.filter(a => a.type === 'visit' && (a.createdAt || '').startsWith(today)).length;
  }
  get visits7d(): number {
    const cut = new Date(Date.now() - 7 * 864e5).toISOString();
    return this.analytics.filter(a => a.type === 'visit' && (a.createdAt || '') >= cut).length;
  }
  get topProjects(): { label: string; n: number }[] {
    const map: Record<string, number> = {};
    this.analytics.filter(a => a.type === 'project_open').forEach(a => {
      const k = a.label || '—'; map[k] = (map[k] || 0) + 1;
    });
    return Object.entries(map).map(([label, n]) => ({ label, n })).sort((a, b) => b.n - a.n).slice(0, 10);
  }
  get topReferrers(): { label: string; n: number }[] {
    const map: Record<string, number> = {};
    this.analytics.filter(a => a.type === 'visit').forEach(a => {
      let k = a.ref || 'directo';
      try { if (k.startsWith('http')) k = new URL(k).hostname; } catch { /* noop */ }
      map[k] = (map[k] || 0) + 1;
    });
    return Object.entries(map).map(([label, n]) => ({ label, n })).sort((a, b) => b.n - a.n).slice(0, 6);
  }
  refresh(): void { this.loadAll(); }
  private reloadCol(col: Col): void {
    this.api.list(col).subscribe(d => (this as any)[col] = col === 'contacts' ? this.byDateDesc(d as any) : this.byOrder(d));
  }

  private byOrder(rows: any[]): any[] { return [...rows].sort((a, b) => (a.order ?? 0) - (b.order ?? 0)); }
  private byDateDesc(rows: ContactRow[]): ContactRow[] {
    return [...rows].sort((a, b) => (b.createdAt || '').localeCompare(a.createdAt || ''));
  }
  fmtDate(iso?: string): string {
    if (!iso) return '—';
    const d = new Date(iso);
    return isNaN(d.getTime()) ? iso : d.toLocaleString('es-CO');
  }
  count(tab: string): number { return ((this as any)[tab] || []).length; }
  docId(item: any): string { return item?._id || item?.id || ''; }

  // ── Editor ─────────────────────────────────────────────────────────────
  get schema(): Field[] { return this.editingCol ? this.schemas[this.editingCol] : []; }

  openNew(col: Col): void {
    this.editingCol = col;
    this.editingId = null;
    this.form = { active: true, order: (this.count(col) + 1) };
    this.text = {};
    this.hydrateBuffers();
    this.saveError = '';
    this.editorOpen = true;
  }

  openEdit(col: Col, item: any): void {
    this.editingCol = col;
    this.editingId = this.docId(item) || null;
    this.form = JSON.parse(JSON.stringify(item));
    if (this.form.active === undefined) this.form.active = true;
    this.text = {};
    this.hydrateBuffers();
    this.saveError = '';
    this.editorOpen = true;
  }

  closeEditor(): void { this.editorOpen = false; this.editingCol = null; this.editingId = null; }

  private hydrateBuffers(): void {
    for (const f of this.schema) {
      if (f.type === 'lines') this.text[f.key] = (this.form[f.key] || []).join('\n');
      else if (f.type === 'tags') this.text[f.key] = (this.form[f.key] || []).join(', ');
      else if (f.type === 'urls') this.text[f.key] = (this.form[f.key] || [])
        .map((u: any) => [u.label, u.url, u.desc].filter(Boolean).join(' | ')).join('\n');
      else if (f.type === 'images' && !Array.isArray(this.form[f.key])) this.form[f.key] = [];
      else if (f.type === 'icon' && this.form[f.key] == null) this.form[f.key] = '';
    }
  }

  // ── Subida de imágenes ─────────────────────────────────────────────────
  uploadingField: string | null = null;
  uploadMsg = '';

  private currentSlug(): string {
    const base = this.form.title || this.form.name || this.editingCol || 'item';
    return (base || '').toLowerCase().normalize('NFD').replace(/[̀-ͯ]/g, '')
      .replace(/[^a-z0-9]+/g, '-').replace(/^-+|-+$/g, '').slice(0, 40) || 'item';
  }

  onPickImages(field: string, ev: Event): void {
    const input = ev.target as HTMLInputElement;
    if (!input.files || !input.files.length || !this.editingCol) return;
    const files = Array.from(input.files);
    this.uploadingField = field;
    this.uploadMsg = '';
    const cat = this.editingCol;
    const slug = this.currentSlug();
    if (!Array.isArray(this.form[field])) this.form[field] = [];
    let remaining = files.length;
    files.forEach(file => this.api.uploadImage(file, cat, slug).subscribe({
      next: res => { this.form[field] = [...(this.form[field] || []), res.url]; if (--remaining === 0) this.uploadingField = null; },
      error: () => { this.uploadMsg = 'Error al subir ' + file.name; if (--remaining === 0) this.uploadingField = null; },
    }));
    input.value = '';
  }

  onPickIcon(field: string, ev: Event): void {
    const input = ev.target as HTMLInputElement;
    if (!input.files || !input.files.length || !this.editingCol) return;
    const file = input.files[0];
    this.uploadingField = field;
    this.uploadMsg = '';
    this.api.uploadImage(file, this.editingCol, this.currentSlug()).subscribe({
      next: res => { this.form[field] = res.url; this.uploadingField = null; },
      error: () => { this.uploadMsg = 'Error al subir el icono'; this.uploadingField = null; },
    });
    input.value = '';
  }

  removeImage(field: string, i: number): void {
    this.form[field] = (this.form[field] || []).filter((_: any, idx: number) => idx !== i);
  }

  save(): void {
    if (!this.editingCol) return;
    const doc: any = {};
    for (const f of this.schema) {
      switch (f.type) {
        case 'lines':
          doc[f.key] = (this.text[f.key] || '').split('\n').map(s => s.trim()).filter(Boolean);
          break;
        case 'tags':
          doc[f.key] = (this.text[f.key] || '').split(',').map(s => s.trim()).filter(Boolean);
          break;
        case 'urls':
          doc[f.key] = (this.text[f.key] || '').split('\n').map(s => s.trim()).filter(Boolean).map(line => {
            const [label, url, desc] = line.split('|').map(p => p.trim());
            return { label: label || '', url: url || '', ...(desc ? { desc } : {}) };
          });
          break;
        case 'creds': {
          const u = this.form.cred_user || (this.form.credentials && this.form.credentials.user);
          const p = this.form.cred_pass || (this.form.credentials && this.form.credentials.pass);
          doc.credentials = (u || p) ? { user: u || '', pass: p || '' } : null;
          break;
        }
        case 'images':
          doc[f.key] = Array.isArray(this.form[f.key]) ? this.form[f.key] : [];
          break;
        case 'icon':
          doc[f.key] = this.form[f.key] || '';
          break;
        case 'number':
          doc[f.key] = Number(this.form[f.key] ?? 0);
          break;
        case 'bool':
          doc[f.key] = !!this.form[f.key];
          break;
        default:
          if (this.form[f.key] !== undefined && this.form[f.key] !== '') doc[f.key] = this.form[f.key];
      }
    }

    this.saving = true;
    this.saveError = '';
    const col = this.editingCol;
    const done = () => { this.saving = false; this.closeEditor(); this.reloadCol(col); };
    const fail = (e: any) => { this.saving = false; this.saveError = 'Error al guardar: ' + (e?.status || e?.message || 'desconocido'); };

    if (this.editingId) {
      this.api.update(col, this.editingId, doc).subscribe({ next: done, error: fail });
    } else {
      this.api.create(col, doc).subscribe({ next: done, error: fail });
    }
  }

  toggleActive(col: Col, item: any): void {
    const id = this.docId(item);
    if (!id) { this.saveError = 'Este elemento no tiene _id; recarga la página.'; return; }
    const next = item.active === false ? true : false;
    this.api.update(col, id, { active: next }).subscribe({
      next: () => { item.active = next; },
      error: () => { this.error = 'No se pudo cambiar el estado'; },
    });
  }

  isActive(item: any): boolean { return item?.active !== false; }

  deleteItem(col: Col, item: any): void {
    const id = this.docId(item);
    if (!id) return;
    const name = item.title || item.role || item.degree || item.name || 'este elemento';
    if (!confirm(`¿Eliminar "${name}"? Esta acción no se puede deshacer.`)) return;
    this.api.remove(col, id).subscribe({
      next: () => this.reloadCol(col),
      error: () => { this.error = 'No se pudo eliminar'; },
    });
  }

  /** Mueve un elemento arriba/abajo intercambiando su `order` con el vecino. */
  move(col: Col, item: any, dir: -1 | 1): void {
    const arr = (this as any)[col] as any[];
    const idx = arr.indexOf(item);
    const swapIdx = idx + dir;
    if (swapIdx < 0 || swapIdx >= arr.length) return;
    const other = arr[swapIdx];
    const oA = item.order ?? idx;
    const oB = other.order ?? swapIdx;
    // Intercambiar orders en la BD
    this.api.update(col, this.docId(item), { order: oB }).subscribe();
    this.api.update(col, this.docId(other), { order: oA }).subscribe({
      complete: () => this.reloadCol(col),
      next: () => this.reloadCol(col),
    });
  }

  // Para el editor de credenciales
  get credUser(): string { return this.form.cred_user ?? this.form.credentials?.user ?? ''; }
  set credUser(v: string) { this.form.cred_user = v; }
  get credPass(): string { return this.form.cred_pass ?? this.form.credentials?.pass ?? ''; }
  set credPass(v: string) { this.form.cred_pass = v; }
}
