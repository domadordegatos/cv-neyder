import { Injectable } from '@angular/core';
import { Observable, of } from 'rxjs';
import { catchError, map } from 'rxjs/operators';
import { ApiService } from './api.service';

// ── Tipos del contenido (deben coincidir con los documentos en Mongo) ──────────
export interface Skill { _id?: string; active?: boolean; category: 'front' | 'back' | 'hard'; name: string; icon: string; order?: number; }
export interface ExperienceItem { _id?: string; active?: boolean; role: string; org: string; location: string; period: string; current: boolean; bullets: string[]; order?: number; }
export interface EducationItem { _id?: string; active?: boolean; degree: string; institution: string; year: string; icon: string; highlight: boolean; order?: number; }
export interface CertItem { _id?: string; active?: boolean; name: string; detail: string; year: string; icon: string; order?: number; }
export interface ProjectUrl { label: string; url: string; desc?: string; }
export interface Project {
  _id?: string; active?: boolean;
  title: string; subtitle?: string; desc?: string; why?: string;
  highlights?: string[]; tags?: string[];
  repo?: string | null; demo?: string | null;
  screenshots?: string[]; urls?: ProjectUrl[];
  credentials?: { user: string; pass: string } | null;
  order?: number;
}
export interface ContactPayload { name: string; email: string; message: string; createdAt?: string; }
export interface Testimonial { _id?: string; active?: boolean; name: string; role: string; text: string; avatar?: string; order?: number; }
export interface Profile {
  _id?: string; key?: string;
  email?: string;
  github?: string; githubLabel?: string;
  instagram?: string; instagramLabel?: string;
  whatsapp?: string; whatsappLabel?: string;
}

@Injectable({ providedIn: 'root' })
export class ContentService {
  constructor(private api: ApiService) {}

  private sorted<T extends { order?: number }>(arr: T[]): T[] {
    return [...arr].sort((a, b) => (a.order ?? 0) - (b.order ?? 0));
  }

  /** Cada getter devuelve [] si la API falla → el componente conserva sus datos por defecto. */
  getProjects(): Observable<Project[]> {
    return this.api.list<Project>('projects').pipe(
      map((r) => this.sorted(r)),
      catchError(() => of<Project[]>([]))
    );
  }
  getExperience(): Observable<ExperienceItem[]> {
    return this.api.list<ExperienceItem>('experience').pipe(
      map((r) => this.sorted(r)), catchError(() => of<ExperienceItem[]>([]))
    );
  }
  getEducation(): Observable<EducationItem[]> {
    return this.api.list<EducationItem>('education').pipe(
      map((r) => this.sorted(r)), catchError(() => of<EducationItem[]>([]))
    );
  }
  getCertifications(): Observable<CertItem[]> {
    return this.api.list<CertItem>('certifications').pipe(
      map((r) => this.sorted(r)), catchError(() => of<CertItem[]>([]))
    );
  }
  getSkills(): Observable<Skill[]> {
    return this.api.list<Skill>('skills').pipe(
      map((r) => this.sorted(r)), catchError(() => of<Skill[]>([]))
    );
  }
  getTestimonials(): Observable<Testimonial[]> {
    return this.api.list<Testimonial>('testimonials').pipe(
      map((r) => this.sorted(r)), catchError(() => of<Testimonial[]>([]))
    );
  }

  /** Guarda un mensaje de contacto en la colección `contacts`. */
  saveContact(payload: ContactPayload): Observable<any> {
    return this.api.create('contacts', { ...payload, createdAt: new Date().toISOString() });
  }

  /** Registra un evento de analítica (solo en producción, no en localhost). */
  private trackingEnabled(): boolean {
    const h = window.location.hostname;
    return h !== 'localhost' && h !== '127.0.0.1' && !h.startsWith('192.168.');
  }
  trackVisit(): void {
    if (!this.trackingEnabled()) return;
    this.api.create('analytics', {
      type: 'visit',
      ref: document.referrer || 'directo',
      createdAt: new Date().toISOString(),
    }).subscribe({ error: () => {} });
  }
  trackEvent(type: string, label: string): void {
    if (!this.trackingEnabled()) return;
    this.api.create('analytics', { type, label, createdAt: new Date().toISOString() })
      .subscribe({ error: () => {} });
  }
  getAnalytics(): Observable<any[]> {
    return this.api.list<any>('analytics').pipe(catchError(() => of<any[]>([])));
  }

  /** Estado en vivo del ESP32 del Huerto (colección iot_status). */
  getIotStatus(): Observable<any | null> {
    return this.api.list<any>('iot_status').pipe(
      map(rows => rows.find(r => r.key === 'huerto') || rows[0] || null),
      catchError(() => of<any | null>(null))
    );
  }

  /** Perfil / info de contacto (colección `config`, primer documento). */
  getProfile(): Observable<Profile | null> {
    return this.api.list<Profile>('config').pipe(
      map(rows => rows.find(r => r.key === 'profile') || rows[0] || null),
      catchError(() => of<Profile | null>(null))
    );
  }
}
