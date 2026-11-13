import { Injectable } from '@angular/core';

type Lang = 'es' | 'en';

const DICT: Record<string, { es: string; en: string }> = {
  // Navbar
  nav_about:      { es: 'Sobre mí',     en: 'About' },
  nav_skills:     { es: 'Habilidades',  en: 'Skills' },
  nav_projects:   { es: 'Proyectos',    en: 'Projects' },
  nav_track:      { es: 'Trayectoria',  en: 'Experience' },
  nav_contact:    { es: 'Contacto',     en: 'Contact' },
  // Hero
  hero_greeting:  { es: '¡Hola! Soy',   en: "Hi! I'm" },
  hero_role:      { es: 'Desarrollador Web', en: 'Web Developer' },
  hero_desc:      { es: 'Construyo desde la interfaz hasta el hardware: aplicaciones web modernas, sistemas IoT y soluciones embebidas que resuelven problemas reales.', en: 'I build from the interface down to the hardware: modern web apps, IoT systems and embedded solutions that solve real problems.' },
  hero_cta_projects: { es: 'Ver proyectos', en: 'View projects' },
  hero_cta_contact:  { es: 'Contactar',     en: 'Contact' },
  hero_cta_pdf:      { es: 'CV PDF',        en: 'Resume PDF' },
  // Section labels
  lbl_about:      { es: 'SOBRE MÍ',      en: 'ABOUT ME' },
  lbl_skills:     { es: 'HABILIDADES',   en: 'SKILLS' },
  lbl_projects:   { es: 'PROYECTOS',     en: 'PROJECTS' },
  lbl_track:      { es: 'TRAYECTORIA',   en: 'EXPERIENCE' },
  lbl_contact:    { es: 'CONTACTO',      en: 'CONTACT' },
  lbl_alsowork:   { es: 'TAMBIÉN TRABAJO CON', en: 'ALSO WORKING WITH' },
  // Section titles
  title_about:    { es: 'Un desarrollador apasionado por el detalle', en: 'A developer passionate about detail' },
  title_skills:   { es: 'Tecnologías que uso a diario', en: 'Technologies I use daily' },
  title_projects: { es: 'Trabajo destacado', en: 'Featured work' },
  title_contact:  { es: '¿Tienes un proyecto en mente?', en: 'Got a project in mind?' },
  // Sobre mí (llevan <strong>, se pintan con [innerHTML])
  about_p1:       { es: 'Soy Neyder, desarrollador full-stack con experiencia en el ecosistema web moderno. Me especializo en <strong>Angular</strong>, <strong>Firebase</strong> y <strong>Node.js</strong> para construir aplicaciones rápidas y escalables.', en: "I'm Neyder, a full-stack developer working in the modern web ecosystem. I specialize in <strong>Angular</strong>, <strong>Firebase</strong> and <strong>Node.js</strong> to build fast, scalable applications." },
  about_p2:       { es: 'También me apasiona el hardware: he desarrollado proyectos IoT con <strong>Arduino</strong> que combinan software y electrónica para resolver problemas reales. Me encanta cuando el código hace cosas en el mundo físico.', en: "I'm just as passionate about hardware: I've built IoT projects with <strong>Arduino</strong> that combine software and electronics to solve real problems. I love it when code does things in the physical world." },
  // Tarjeta de datos
  info_name:      { es: 'Nombre', en: 'Name' },
  info_profile:   { es: 'Perfil', en: 'Profile' },
  info_avail:     { es: 'Disponibilidad', en: 'Availability' },
  info_avail_val: { es: 'Disponible', en: 'Available' },
  info_langs:     { es: 'Idiomas', en: 'Languages' },
  info_langs_val: { es: 'Español · Inglés', en: 'Spanish · English' },
  info_email:     { es: 'Email', en: 'Email' },
  stat_years:     { es: 'años de experiencia', en: 'years of experience' },
  stat_projects:  { es: 'proyectos terminados', en: 'completed projects' },
  // Trayectoria
  tray_exp:       { es: 'Experiencia Laboral', en: 'Work Experience' },
  tray_edu:       { es: 'Formación Académica', en: 'Education' },
  tray_certs:     { es: 'Certificaciones destacadas', en: 'Featured certifications' },
  badge_current:  { es: 'Actual', en: 'Current' },
  // Projects
  read_more:      { es: 'Leer más',  en: 'Read more' },
  read_less:      { es: 'Leer menos', en: 'Read less' },
  img_soon:       { es: 'Imágenes próximamente', en: 'Images coming soon' },
  btn_view:       { es: 'Ver proyecto', en: 'View project' },
  btn_code:       { es: 'Código', en: 'Source' },
  badge_private:  { es: 'Proyecto privado', en: 'Private project' },
  alt_shot:       { es: 'Captura de', en: 'Screenshot of' },
  // Contact form
  contact_body:   { es: 'Me encantaría escucharte. Escríbeme y te respondo en menos de 24 horas.', en: "I'd love to hear from you. Write me and I'll reply within 24 hours." },
  form_name:      { es: 'Nombre',  en: 'Name' },
  form_email:     { es: 'Email',   en: 'Email' },
  form_message:   { es: 'Mensaje', en: 'Message' },
  form_send:      { es: 'Enviar mensaje', en: 'Send message' },
  form_sending:   { es: 'Enviando...',    en: 'Sending...' },
  form_sent:      { es: '¡Mensaje enviado!', en: 'Message sent!' },
  ph_name:        { es: 'Tu nombre completo', en: 'Your full name' },
  ph_message:     { es: 'Cuéntame sobre tu proyecto...', en: 'Tell me about your project...' },
  form_error:     { es: 'Hubo un error. Escríbeme directamente a', en: 'Something went wrong. Write me directly at' },
  // CV imprimible (PDF)
  pc_role:        { es: 'Desarrollador Full-Stack & IoT', en: 'Full-Stack & IoT Developer' },
  pc_exp:         { es: 'Experiencia', en: 'Experience' },
  pc_edu:         { es: 'Formación', en: 'Education' },
  pc_certs:       { es: 'Certificaciones', en: 'Certifications' },
  pc_skills:      { es: 'Habilidades', en: 'Skills' },
  pc_projects:    { es: 'Proyectos destacados', en: 'Featured projects' },
  // Testimonials
  lbl_testimonials:   { es: 'TESTIMONIOS', en: 'TESTIMONIALS' },
  title_testimonials: { es: 'Lo que dicen de mi trabajo', en: 'What people say about my work' },
  // IoT
  iot_online:     { es: 'En línea', en: 'Online' },
  iot_offline:    { es: 'Sin conexión', en: 'Offline' },
  iot_relays:     { es: 'Relés',    en: 'Relays' },
  iot_uptime:     { es: 'Encendido', en: 'Uptime' },
  iot_watering:   { es: 'Riego',    en: 'Watering' },
};

@Injectable({ providedIn: 'root' })
export class LanguageService {
  private readonly KEY = 'cv_lang';
  lang: Lang = 'es';

  init(): void {
    const saved = localStorage.getItem(this.KEY) as Lang | null;
    const browser = (navigator.language || 'es').toLowerCase().startsWith('en') ? 'en' : 'es';
    this.lang = saved || browser;
  }
  toggle(): void {
    this.lang = this.lang === 'es' ? 'en' : 'es';
    localStorage.setItem(this.KEY, this.lang);
  }
  t(key: string): string {
    const entry = DICT[key];
    return entry ? entry[this.lang] : key;
  }

  /**
   * Devuelve un campo de CONTENIDO en el idioma activo.
   *
   * El diccionario de arriba solo cubre el texto fijo de la interfaz. El
   * contenido real (proyectos, experiencia, educación, certificaciones) vive
   * en Mongo, y ahí cada documento guarda el español en `campo` y, si existe,
   * el inglés en `campoEn`: `desc`/`descEn`, `title`/`titleEn`, etc.
   *
   * Si el campo en inglés falta o está vacío, devuelve el español. Eso es
   * deliberado: permite traducir de a poco sin que la CV quede con huecos, y
   * evita que un documento nuevo rompa la versión en inglés por un olvido.
   */
  tx(obj: any, campo: string): any {
    if (!obj) return '';
    if (this.lang === 'en') {
      const en = obj[campo + 'En'];
      const tiene = Array.isArray(en) ? en.length > 0 : String(en ?? '').trim() !== '';
      if (tiene) return en;
    }
    return obj[campo];
  }
}
