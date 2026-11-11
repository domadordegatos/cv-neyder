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
  // Trayectoria
  tray_exp:       { es: 'Experiencia Laboral', en: 'Work Experience' },
  tray_edu:       { es: 'Formación Académica', en: 'Education' },
  tray_certs:     { es: 'Certificaciones destacadas', en: 'Featured certifications' },
  badge_current:  { es: 'Actual', en: 'Current' },
  // Projects
  read_more:      { es: 'Leer más',  en: 'Read more' },
  read_less:      { es: 'Leer menos', en: 'Read less' },
  img_soon:       { es: 'Imágenes próximamente', en: 'Images coming soon' },
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
}
