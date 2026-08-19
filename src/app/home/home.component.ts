import { Component, OnInit, AfterViewInit, OnDestroy, ViewChild, ElementRef, NgZone } from '@angular/core';
import * as AOS from 'aos';

interface BlobParticle {
  x: number; y: number;
  vx: number; vy: number;
  r: number; targetR: number;
  color: string;
  alpha: number;
  dying: boolean;
  dyingTimer: number;
  splitCooldown: number;
  driftAngle: number;
  driftSpeed: number;
}

interface GooPoint {
  bx: number; by: number; // base position (on circle)
  x: number;  y: number;  // current displaced position
  vx: number; vy: number;
}

interface Dash {
  x: number; y: number;     // current pos
  ox: number; oy: number;   // origin (home)
  vx: number; vy: number;
  angle: number;
  w: number; h: number;
  color: string;
}

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.scss']
})
export class HomeComponent implements OnInit, AfterViewInit, OnDestroy {

  @ViewChild('blobCanvas') blobCanvasRef!: ElementRef<HTMLCanvasElement>;
  @ViewChild('heroSection') heroSectionRef!: ElementRef<HTMLElement>;
  @ViewChild('blobFrame') blobFrameRef!: ElementRef<HTMLElement>;

  private blobs: BlobParticle[] = [];
  private dashes: Dash[] = [];
  private gooPoints: GooPoint[] = [];
  private gooCenter = { x: 0, y: 0 };
  private gooR = 0;
  private blobAnimFrame = 0;
  private blobMouse = { x: -999, y: -999 };
  private readonly BLOB_COLORS = ['#2ec4b6', '#6366f1', '#5b8dee', '#2ec4b6'];
  private readonly TARGET_COUNT = 4;
  private blobMouseMove!: (e: MouseEvent) => void;

  currentYear = new Date().getFullYear();

  skillsFront = [
    { name: 'JavaScript', icon: 'assets/1200px-Javascript-shield.svg.webp' },
    { name: 'TypeScript', icon: 'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/typescript/typescript-original.svg' },
    { name: 'Angular', icon: 'assets/angular-icon-logo.webp' },
    { name: 'Ionic', icon: 'assets/ionic.webp' },
    { name: 'HTML & CSS', icon: 'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/html5/html5-original.svg' },
    { name: 'Bootstrap', icon: 'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/bootstrap/bootstrap-original.svg' },
  ];

  skillsBack = [
    { name: 'Node.js', icon: 'assets/node.webp' },
    { name: 'Firebase', icon: 'assets/firebase-3521427-2944871.webp' },
    { name: 'Firestore', icon: 'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/firebase/firebase-plain.svg' },
    { name: 'REST APIs', icon: 'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/fastapi/fastapi-original.svg' },
  ];

  skillsHard = [
    { name: 'Arduino', icon: 'assets/arduino-logo-1.webp' },
    { name: 'C++', icon: 'assets/1200px-ISO_C++_Logo.svg.webp' },
    { name: 'IoT', icon: 'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/raspberrypi/raspberrypi-original.svg' },
    { name: 'Git', icon: 'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/git/git-original.svg' },
  ];

  experience = [
    {
      role: 'Instructor Contratista',
      org: 'SENA – Regional Casanare',
      location: 'Yopal, Casanare',
      period: 'Feb 2024 – Presente',
      current: true,
      bullets: [
        'Formación profesional integral presencial y virtual (160 h/mes)',
        'Programas: Informática, Diseño y Desarrollo de Software',
        'Acompañamiento técnico-pedagógico en educación media articulada',
      ]
    },
    {
      role: 'Docente de Informática & Soporte Técnico',
      org: 'Colegio San Mateo Apóstol',
      location: 'Yopal, Casanare',
      period: 'Feb 2015 – Presente',
      current: true,
      bullets: [
        'Docencia en básica primaria, secundaria y media (todos los grados)',
        'Administración de redes cableadas e inalámbricas institucionales',
        'Desarrollo de software contable y de ventas (PHP, MySQL, JS, MVC)',
      ]
    },
    {
      role: 'Ingeniero de Apoyo',
      org: 'Consorcio Smart Grid Casanare',
      location: 'Yopal, Casanare',
      period: 'Jul 2020 – Jul 2022',
      current: false,
      bullets: [
        'Parametrización de equipos de comunicaciones (fibra, radio, celular)',
        'Supervisión de integraciones de control en campo (subestaciones)',
        'Control de bases de datos e informes de gestión técnica',
      ]
    },
  ];

  education = [
    {
      degree: 'Magíster en Tecnología Educativa y Competencias Digitales',
      institution: 'Universidad Internacional de La Rioja (UNIR)',
      year: '2025',
      icon: 'bi-mortarboard-fill',
      highlight: true,
    },
    {
      degree: 'Especialista en Ciberseguridad',
      institution: 'Universidad Autónoma de Occidente, Cali',
      year: '2023',
      icon: 'bi-shield-lock-fill',
      highlight: false,
    },
    {
      degree: 'Ingeniero de Sistemas',
      institution: 'Fundación Universitaria de San Gil (UNISANGIL)',
      year: '2020',
      icon: 'bi-cpu-fill',
      highlight: false,
    },
  ];

  certifications = [
    {
      name: 'Matrícula Profesional – Ing. de Sistemas',
      detail: 'COPNIA · No. 041122-0537183 BYC · Vigente',
      year: '2020',
      icon: 'bi-patch-check-fill',
    },
    {
      name: 'Diplomado Ciberseguridad – Cisco CBROPS (120 h)',
      detail: 'Universidad Santo Tomás',
      year: '2023',
      icon: 'bi-shield-fill',
    },
    {
      name: 'IA Generativa Aplicada a la Educación (150 h)',
      detail: 'UNIR',
      year: '2024',
      icon: 'bi-robot',
    },
    {
      name: 'Misión TIC – Desarrollo de Aplicaciones Web (800 h)',
      detail: 'MinTIC / UNAB',
      year: '2022',
      icon: 'bi-globe',
    },
    {
      name: 'Auditor SGSI – ISO/IEC 27001:2013 (40 h)',
      detail: 'ICONTEC',
      year: '2022',
      icon: 'bi-shield-check',
    },
  ];

  alsoWith = [
    'Prompting avanzado e integración de IA generativa',
    'Arquitectura IoT end-to-end (ESP32 → MQTT → Dashboard)',
    'Automatización de flujos con lógica embebida',
    'Ciberseguridad aplicada y auditoría ISO/IEC 27001',
    'Despliegue en servidores Linux (Ubuntu) y Firebase',
    'Pensamiento sistémico: del problema al producto',
  ];

  projects = [
    {
      title: 'BarApp – Menú Digital para Bares',
      subtitle: 'SPA full-stack con gestión de pedidos, roles y facturación en tiempo real',
      desc: 'Diseñé y desarrollé esta plataforma para resolver un problema real: bares sin sistema digital para tomar pedidos por mesa. Clientes escanean un QR y hacen su pedido desde el celular; el admin lo ve actualizado al instante en su panel. Arquitectura basada en Angular + Firebase Firestore (tiempo real), con tres niveles de acceso (super-admin, admin de local y cliente de mesa), generación de facturas en Excel y códigos QR únicos por mesa.',
      why: '¿Por qué Angular + Firebase? Velocidad de desarrollo, sincronización en tiempo real sin servidor propio y despliegue inmediato: exactamente lo que necesita un negocio pequeño.',
      highlights: [
        'Autenticación con roles: super-admin, admin por local, cliente por mesa',
        'Pedidos en tiempo real con Firebase Firestore (sin recargar)',
        'Generación de códigos QR únicos por mesa',
        'Panel de facturación y exportación a Excel (ExcelJS)',
        'Diseño responsivo pensado para celular del cliente',
      ],
      tags: ['Angular 15', 'Firebase', 'Firestore', 'TypeScript', 'Bootstrap', 'ExcelJS', 'QRCode'],
      repo: null,
      demo: null,
      screenshots: [
        'assets/barapp-login.webp',
        'assets/Screenshot_1.webp',
        'assets/Screenshot_2.webp',
        'assets/Screenshot_3.webp',
        'assets/Screenshot_4.webp',
        'assets/Screenshot_5.webp',
        'assets/barapp-superadmin.webp',
      ],
      credentials: { user: 'neyderflashh@gmail.com', pass: 'muebleazul2' },
      urls: [
        { label: 'Super-admin', url: 'https://barapp.nncoms.com/super-admin-panel', desc: 'Gestión global de bares activos' },
        { label: 'Admin del bar', url: 'https://barapp.nncoms.com/lachula/admin/gestion', desc: 'Panel de pedidos, menú, facturas y QR' },
        { label: 'Cliente / Mesa', url: 'https://barapp.nncoms.com/lachula/0LF694CEQH', desc: 'Vista del cliente: escanea QR y pide desde el celular' },
      ],
    },
    {
      title: 'Mandao – App de Domicilios',
      subtitle: 'Plataforma de delivery local con mapa en tiempo real y dos roles de usuario',
      desc: 'App móvil híbrida para solicitar domicilios personalizados: el usuario marca origen y destino en un mapa, describe su encargo y elige método de pago; el repartidor disponible más cercano acepta y ejecuta la entrega. Construida con Ionic + Angular y Firebase para sincronización en tiempo real, con mapas interactivos vía Leaflet/OpenStreetMap.',
      why: '¿Por qué Ionic + Leaflet? Ionic permite una sola base de código para Android, iOS y web. Leaflet con OpenStreetMap elimina costos de API de mapas — ideal para un proyecto propio sin infraestructura costosa.',
      highlights: [
        'Dos roles: Usuario (cliente) y Delivery (repartidor) con flujos independientes',
        'Mapa interactivo con Leaflet: origen, destino y cálculo de ruta en tiempo real',
        'Formulario de pedido con método de pago (efectivo / transferencia) y momento de cobro',
        'Matching automático: pedido se asigna al delivery disponible más cercano',
        'Autenticación con Google (Firebase Auth) — registro y login en un clic',
        'Sincronización de estado del pedido en tiempo real con Firestore',
      ],
      tags: ['Ionic', 'Angular 16', 'Firebase', 'Firestore', 'Leaflet', 'TypeScript', 'Capacitor'],
      repo: 'https://github.com/domadordegatos/mandao',
      demo: null,
      urls: [
        { label: 'App en vivo', url: 'https://mandao.nncoms.com', desc: 'Abre la app — ingresa con tu cuenta de Google' },
      ],
      credentials: null,
      screenshots: [
        'assets/mandao/Screenshot_6.webp',
        'assets/mandao/Screenshot_7.webp',
        'assets/mandao/Screenshot_8.webp',
        'assets/mandao/Screenshot_9.webp',
        'assets/mandao/Screenshot_10.webp',
      ],
    },
    {
      title: 'CarruCell – Catálogo Digital para Negocios',
      subtitle: 'Plataforma multi-tenant para que cualquier negocio tenga su catálogo web propio',
      desc: 'Aplicación web que permite a tiendas y negocios crear su catálogo de productos online con categorías, fotos y precios, accesible vía un enlace personalizado. Cada negocio tiene su propio espacio aislado con autenticación independiente. El dueño gestiona categorías y productos desde un panel privado; los clientes navegan el catálogo sin necesidad de registrarse.',
      why: '¿Por qué Angular + Firebase? Multi-tenancy sin servidor propio: Firestore filtra por email del propietario, dando a cada negocio su espacio aislado con una sola base de datos y cero infraestructura adicional.',
      highlights: [
        'Multi-tenant: cada negocio tiene su catálogo con URL propia (/carrucell/nombre-negocio)',
        'Panel de administración: CRUD de categorías y productos con subida de imágenes',
        'Vista de cliente sin login: navega categorías y productos de forma pública',
        'Autenticación por email/contraseña con Firebase Auth',
        'Sincronización en tiempo real con Firestore',
        'Validación de negocio registrado con feedback al usuario',
      ],
      tags: ['Angular', 'Firebase', 'Firestore', 'TypeScript', 'Bootstrap'],
      repo: 'https://github.com/domadordegatos/carru-cell',
      demo: null,
      urls: [
        { label: 'Admin', url: 'https://carrucell.nncoms.com', desc: 'Panel de administración: crear y editar productos y categorías' },
        { label: 'Catálogo El Neyder', url: 'https://carrucell.nncoms.com/carru-cell/el%20neyder', desc: 'Vista pública del catálogo del negocio' },
      ],
      credentials: { user: 'neyderflashh@gmail.com', pass: '123456' },
      screenshots: [
        'assets/carrucel/Screenshot_7.webp',
        'assets/carrucel/Screenshot_8.webp',
        'assets/carrucel/Screenshot_9.webp',
        'assets/carrucel/Screenshot_10.webp',
        'assets/carrucel/Screenshot_11.webp',
      ],
    },
    {
      title: 'Subasta Ganadera Aguazul',
      subtitle: 'App web para subastas ganaderas con pujas y paletas en tiempo real',
      desc: 'Plataforma digital para la Subasta Ganadera de Aguazul que digitaliza todo el proceso de subasta: los compradores se registran, reciben un número de paleta único y participan en la compra de lotes de ganado en tiempo real. El sistema valida identidad con cédula/NIT, permite login con email o Google, y gestiona el flujo de puja desde el panel del subastador.',
      why: '¿Por qué Angular + Firebase? La subasta ocurre en tiempo real con múltiples compradores simultáneos — Firebase Firestore garantiza que todos vean el mismo precio actualizado al instante sin necesidad de recargar.',
      highlights: [
        'Registro de compradores con datos legales: cédula/NIT, contacto y dirección',
        'Asignación de número de paleta único por comprador',
        'Autenticación con email/contraseña y login con Google (Firebase Auth)',
        'Visualización de lotes ganaderos y pujas en tiempo real con Firestore',
        'Panel de administración para gestión de lotes y compradores',
        'Flujo protegido: solo compradores verificados pueden pujar',
      ],
      tags: ['Angular', 'Firebase', 'Firestore', 'TypeScript', 'Bootstrap'],
      repo: null,
      demo: null,
      urls: [
        { label: 'App en vivo', url: 'https://subasta.nncoms.com', desc: 'Plataforma de subasta ganadera' },
      ],
      credentials: { user: 'juegoscsma@gmail.com', pass: 'juegos123' },
      screenshots: [
        'assets/subasta/Screenshot_1.webp',
        'assets/subasta/Screenshot_2.webp',
        'assets/subasta/Screenshot_3.webp',
        'assets/subasta/Screenshot_4.webp',
        'assets/subasta/Screenshot_5.webp',
      ],
    },
    {
      title: 'Gescode – Plataforma Académica Escolar',
      subtitle: 'Sistema de gestión académica para docentes y estudiantes del Colegio San Mateo Apóstol',
      desc: 'Plataforma web integral que digitaliza la gestión académica del colegio: los docentes administran sus grupos, registran evaluaciones por indicadores de logro con pesos configurables, gestionan asistencia, asignan tareas y se comunican con estudiantes y colegas. El sistema genera consolidados automáticos por período y permite seguimiento detallado del rendimiento de cada estudiante.',
      why: '¿Por qué PHP + MySQL? Infraestructura existente del colegio sin costos adicionales de servidor. PHP permite despliegue inmediato, sesiones robustas y consultas complejas sobre datos académicos con MySQL.',
      highlights: [
        'Gestión de grupos por asignatura y año lectivo con múltiples docentes',
        'Evaluaciones por indicadores de logro con tipos, pesos y promedios automáticos',
        'Registro de asistencia y observaciones por estudiante',
        'Módulo de tareas con fechas, entregas y calificación',
        'Sistema de mensajería interna entre docentes y estudiantes',
        'Consolidados de notas por período con exportación',
        'Calendario académico integrado',
      ],
      tags: ['PHP', 'MySQL', 'JavaScript', 'HTML', 'CSS', 'Bootstrap'],
      repo: null,
      demo: null,
      urls: [
        { label: 'Sistema en vivo', url: 'https://csma.nncoms.com', desc: 'Plataforma académica del Colegio San Mateo Apóstol' },
      ],
      credentials: { user: 'docente1', pass: 'Admin123*' },
      screenshots: [
        'assets/gescode/Screenshot_7.webp',
        'assets/gescode/Screenshot_8.webp',
        'assets/gescode/Screenshot_9.webp',
        'assets/gescode/Screenshot_10.webp',
        'assets/gescode/Screenshot_11.webp',
      ],
    },
    {
      title: 'CSMA Contable',
      subtitle: 'Sistema web de gestión financiera para institución educativa',
      desc: 'Plataforma web desarrollada para el Colegio San Mateo Apóstol que centraliza la administración financiera: registro de pagos ordinarios y extraordinarios, control de cartera, gestión de estudiantes, acudientes y matrículas. Permite al personal administrativo consultar historiales, verificar saldos pendientes y mantener trazabilidad de cada movimiento.',
      why: '¿Por qué PHP + MySQL? El colegio ya contaba con hosting tradicional sin soporte para Node o Firebase. PHP con MySQL fue la elección pragmática: bajo costo de infraestructura, fácil mantenimiento y despliegue inmediato.',
      highlights: [
        'Registro y consulta de pagos ordinarios y extraordinarios por periodo',
        'Módulo de cartera: saldos pendientes y estado financiero por estudiante',
        'Gestión completa de estudiantes, acudientes y matrículas',
        'Historial detallado con trazabilidad de cada movimiento',
        'Interfaz limpia y responsiva adaptada para uso administrativo',
      ],
      tags: ['PHP', 'MySQL', 'JavaScript', 'HTML', 'CSS', 'Bootstrap'],
      repo: null,
      demo: null,
      urls: [
        { label: 'Sistema en vivo', url: 'https://contable.nncoms.com', desc: 'Acceso al panel administrativo contable' },
      ],
      credentials: { user: 'root', pass: 'raiz' },
      screenshots: [
        'assets/contable/Screenshot_1.webp',
        'assets/contable/Screenshot_2.webp',
        'assets/contable/Screenshot_3.webp',
        'assets/contable/Screenshot_4.webp',
        'assets/contable/Screenshot_5.webp',
      ],
    },
    {
      title: 'CSMA – Sistema de Cafetería Escolar',
      subtitle: 'Gestión de ventas, inventario y asistencia para tienda escolar',
      desc: 'Sistema web completo para la administración de la cafetería/tienda del Colegio San Mateo Apóstol. Permite registrar ventas, controlar inventario de productos, gestionar movimientos de caja y llevar asistencia. Diseñado para ser operado por personal no técnico con una interfaz clara y acceso protegido por roles.',
      why: '¿Por qué PHP? Sistema desplegado en servidor local del colegio sin dependencias externas: funciona incluso sin internet, lo que es crítico en un entorno escolar.',
      highlights: [
        'Registro de ventas e inventario de productos en tiempo real',
        'Control de movimientos de caja y cierre diario',
        'Gestión de asistencia integrada al sistema',
        'Bloqueo temporal de cuenta tras intentos fallidos (seguridad)',
        'Sesiones aisladas para evitar conflictos entre usuarios simultáneos',
        'Interfaz responsiva optimizada para uso rápido en mostrador',
      ],
      tags: ['PHP', 'MySQL', 'JavaScript', 'HTML', 'CSS', 'Bootstrap'],
      repo: null,
      demo: null,
      urls: [
        { label: 'Sistema en vivo', url: 'https://cafeteria.nncoms.com', desc: 'Acceso al panel de cafetería' },
      ],
      credentials: { user: 'root', pass: 'raizz' },
      screenshots: [
        'assets/cafeteria/Screenshot_1.webp',
        'assets/cafeteria/Screenshot_2.webp',
        'assets/cafeteria/Screenshot_3.webp',
        'assets/cafeteria/Screenshot_4.webp',
        'assets/cafeteria/Screenshot_5.webp',
      ],
    },
    {
      title: 'Generador de Formatos SENA',
      subtitle: 'Herramienta que convierte un Excel en documentos Word oficiales del SENA, sin almacenar ningún dato',
      desc: 'Aplicación web desarrollada para agilizar la gestión documental de la etapa productiva: el instructor carga el listado de aprendices en Excel y la app genera automáticamente los formatos oficiales del SENA — Compromiso del Aprendiz, Autorización de Tratamiento de Datos y Seguimiento de Etapa Productiva — listos para imprimir o archivar. Si hay un solo aprendiz descarga los archivos directo; si son varios, empaca todo en un ZIP. Incluye soporte para firmas incrustadas en el Excel y un tour guiado la primera vez que se usa. Todo el procesamiento ocurre en el navegador: ningún dato personal se envía a ningún servidor ni se almacena, cumpliendo la Ley 1581 de habeas data.',
      why: '¿Por qué Angular puro sin backend? Es un requisito funcional: la ley exige que datos sensibles de menores (documentos, acudientes, teléfonos) no salgan del dispositivo. Angular + docxtemplater corren completamente en el cliente.',
      tags: ['Angular', 'TypeScript', 'JavaScript', 'HTML', 'CSS'],
      highlights: [
        'Genera Compromiso del Aprendiz, Tratamiento de Datos y Seguimiento de Etapa Productiva',
        'Procesamiento 100% local: ningún dato sale del navegador (Ley 1581)',
        'Descarga individual o ZIP masivo para grupos completos con barra de progreso',
        'Extrae firmas incrustadas en el Excel y las incluye en el formato de seguimiento',
        'Modo edición para corregir datos directamente en la tabla antes de generar',
        'Tour guiado interactivo (driver.js) para nuevos usuarios',
        'Plantilla Excel descargable con validaciones y fila de ejemplo automática',
      ],
      repo: null,
      demo: null,
      urls: [
        { label: 'App en vivo', url: 'https://formatosena.nncoms.com', desc: 'Generador de formatos SENA en el navegador' },
      ],
      credentials: null,
      screenshots: [
        'assets/formatos/Screenshot_1.webp',
        'assets/formatos/Screenshot_2.webp',
      ],
    },
    {
      title: 'Bitácoras SENA – Control de Entregas',
      subtitle: 'Plataforma docente para gestionar bitácoras de aprendices con correlación automática de nombres',
      desc: 'Herramienta que desarrollé para resolver un problema real de mi trabajo: recibir y cruzar decenas de archivos Excel de bitácoras (formato GFPI-F-147) sin equivocarse de aprendiz. El instructor carga la ficha con la lista del grupo, suelta todos los `.xlsx` de golpe y el sistema los correlaciona automáticamente usando Jaro-Winkler sobre los nombres escritos a mano. Lo que resuelve solo aparece en verde; lo dudoso va a revisión manual. Desde el mismo panel se retroalimenta a cada aprendiz (aprobada / con observaciones) y se publican plazos de entrega con cuenta regresiva. Cada ficha genera un enlace único por token que los aprendices consultan sin login, con actualizaciones en tiempo real vía Firebase onSnapshot.',
      why: '¿Por qué Angular + Firebase? Necesitaba algo que funcionara desde el navegador, sin instalación, con sincronización instantánea para que los aprendices vean el estado actualizado al segundo. La correlación difusa resuelve el problema real: los nombres llegan con tildes inconsistentes, numeración y erratas.',
      tags: ['Angular', 'TypeScript', 'Firebase', 'Firestore', 'HTML', 'CSS'],
      repo: null,
      demo: null,
      urls: [
        { label: 'App en vivo', url: 'https://bitacora.nncoms.com', desc: 'Acceso con Google (instructores autorizados)' },
      ],
      credentials: null,
      screenshots: [
        'assets/bitacoras/Screenshot_1.webp',
        'assets/bitacoras/Screenshot_2.webp',
        'assets/bitacoras/Screenshot_3.webp',
      ],
    },
    {
      title: 'NEWTÓNICA – Feria de Ciencias Escolar',
      subtitle: 'Plataforma de inscripción y gestión de proyectos y retos científicos',
      desc: 'Plataforma web para la organización de la feria de ciencias del Colegio San Mateo Apóstol. Los estudiantes pueden explorar proyectos y retos disponibles por categoría y grado, inscribirse cuando las convocatorias están abiertas (con cuenta regresiva en tiempo real), y los administradores gestionan la totalidad del evento desde un panel dedicado. Construida con Angular + Firebase para sincronización en tiempo real e inscripciones controladas por fechas.',
      why: '¿Por qué Angular + Firebase? La cuenta regresiva en vivo, el control de fechas de apertura y el estado de inscripciones en tiempo real requieren una solución reactiva sin servidor dedicado.',
      tags: ['Angular', 'TypeScript', 'Firebase', 'Firestore', 'HTML', 'CSS'],
      repo: null,
      demo: null,
      urls: [
        { label: 'Ver proyectos', url: 'https://ctm.nncoms.com', desc: 'Explorar proyectos y retos de la feria' },
        { label: 'Panel admin', url: 'https://ctm.nncoms.com/login', desc: 'Acceso al panel de administración' },
      ],
      credentials: { user: 'csmactm@gmail.com', pass: 'ctm2026' },
      screenshots: [
        'assets/ctm/Screenshot_1.webp',
        'assets/ctm/Screenshot_2.webp',
        'assets/ctm/Screenshot_3.webp',
        'assets/ctm/Screenshot_4.webp',
        'assets/ctm/Screenshot_5.webp',
        'assets/ctm/Screenshot_6.webp',
      ],
    },
    {
      title: 'Huerto Automatizado – Control Remoto IoT',
      subtitle: 'Sistema embebido en ESP32 con dashboard web para riego inteligente y monitoreo en tiempo real',
      desc: 'Sistema IoT completo para automatizar y controlar un huerto desde cualquier lugar. El firmware corre en un ESP32 y gestiona 4 relés (bombas/válvulas), un RTC DS3231, pantalla LCD 20×4 y teclado matricial 4×4 para operación local. La comunicación remota usa MQTT sobre WebSocket Seguro (WSS puerto 443), eliminando la necesidad de abrir puertos en el router. El dashboard web en Angular muestra estado en tiempo real, permite encender/apagar relés remotamente y visualiza telemetría del dispositivo (RSSI, heap libre, uptime, motivo del último reinicio).',
      highlights: [
        '4 relés controlables remotamente vía MQTT/WSS o localmente desde el teclado',
        'Hasta 8 riegos programados por horario con duración configurable',
        'Telemetría cada 5 min: señal WiFi, memoria, uptime, reconexiones',
        'Watchdog automático: reinicia el ESP32 si el firmware se cuelga',
        'Configuración de WiFi desde el teclado físico (estilo T9 multitap)',
        'Control de backlight LCD por horario (encendido/apagado automático)',
      ],
      why: '¿Por qué MQTT sobre WSS? Permite comunicación bidireccional segura sin abrir puertos en el firewall, usando el mismo puerto 443 del HTTPS. Solución ideal para redes domésticas o institucionales con restricciones.',
      tags: ['ESP32', 'Arduino', 'MQTT', 'Angular', 'TypeScript', 'C++', 'IoT', 'WebSockets'],
      repo: null,
      demo: null,
      urls: [
        { label: 'Dashboard en vivo', url: 'https://huerto.nncoms.com', desc: 'Panel de control del huerto en tiempo real' },
      ],
      credentials: { user: 'huerto', pass: 'redhatcontrol2026' },
      screenshots: [
        'assets/huerto/Screenshot_2.webp',
        'assets/huerto/Screenshot_3.webp',
        'assets/huerto/Screenshot_4.webp',
      ],
    },
  ];

  tagIcons: Record<string, string> = {
    'Angular':     'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/angularjs/angularjs-original.svg',
    'Angular 15':  'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/angularjs/angularjs-original.svg',
    'Angular 16':  'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/angularjs/angularjs-original.svg',
    'TypeScript':  'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/typescript/typescript-original.svg',
    'JavaScript':  'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/javascript/javascript-original.svg',
    'HTML':        'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/html5/html5-original.svg',
    'CSS':         'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/css3/css3-original.svg',
    'Bootstrap':   'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/bootstrap/bootstrap-original.svg',
    'Firebase':    'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/firebase/firebase-plain.svg',
    'Firestore':   'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/firebase/firebase-plain.svg',
    'Node.js':     'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/nodejs/nodejs-original.svg',
    'Ionic':       'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/ionic/ionic-original.svg',
    'PHP':         'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/php/php-original.svg',
    'MySQL':       'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/mysql/mysql-original.svg',
    'Git':         'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/git/git-original.svg',
    'Capacitor':   'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/capacitor/capacitor-original.svg',
    'Leaflet':     'data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="%2357a823"><path d="M12 2C8.13 2 5 5.13 5 9c0 5.25 7 13 7 13s7-7.75 7-13c0-3.87-3.13-7-7-7zm0 9.5c-1.38 0-2.5-1.12-2.5-2.5S10.62 6.5 12 6.5s2.5 1.12 2.5 2.5S13.38 11.5 12 11.5z"/></svg>',
    'ESP32':       'assets/arduino-logo-1.webp',
    'Arduino':     'assets/arduino-logo-1.webp',
    'C++':         'assets/1200px-ISO_C++_Logo.svg.webp',
    'MQTT':        'data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="%235b52e8"><path d="M12 2a10 10 0 1 0 10 10A10 10 0 0 0 12 2zm0 18a8 8 0 1 1 8-8 8 8 0 0 1-8 8zm-1-5h2v2h-2zm0-8h2v6h-2z"/></svg>',
    'WebSockets':  'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/socketio/socketio-original.svg',
    'IoT':         'https://cdn.jsdelivr.net/gh/devicons/devicon/icons/raspberrypi/raspberrypi-original.svg',
  };

  lightboxProjectIdx: number | null = null;
  screenshotIndex: number[] = [];
  fadingOut: boolean[] = [];
  expandedProjects: boolean[] = [];
  private autoPlayInterval: any;

  get lightboxSrc(): string | null {
    if (this.lightboxProjectIdx === null) return null;
    const p = this.projects[this.lightboxProjectIdx];
    return p?.screenshots?.[this.getIdx(this.lightboxProjectIdx)] ?? null;
  }

  openLightbox(projectIdx: number): void { this.lightboxProjectIdx = projectIdx; }
  closeLightbox(): void { this.lightboxProjectIdx = null; }

  lightboxPrev(): void {
    if (this.lightboxProjectIdx === null) return;
    const len = this.projects[this.lightboxProjectIdx].screenshots!.length;
    this.prevShot(this.lightboxProjectIdx, len);
  }
  lightboxNext(): void {
    if (this.lightboxProjectIdx === null) return;
    const len = this.projects[this.lightboxProjectIdx].screenshots!.length;
    this.nextShot(this.lightboxProjectIdx, len);
  }

  toggleExpand(i: number): void {
    const wasExpanded = !!this.expandedProjects[i];
    this.expandedProjects[i] = !wasExpanded;

    // rAF asegura que la manipulación DOM ocurra después del ciclo de render de Angular
    requestAnimationFrame(() => {
      const article = document.querySelectorAll('.project-item')[i] as HTMLElement;
      if (!article) return;

      const wrap   = article.querySelector<HTMLElement>('.project-desc-wrap')!;
      const extras = article.querySelector<HTMLElement>('.project-extras')!;
      const fade   = article.querySelector<HTMLElement>('.desc-fade');

      if (!wasExpanded) {
        wrap.style.height  = wrap.scrollHeight + 'px';
        extras.style.height  = extras.scrollHeight + 'px';
        extras.style.opacity = '1';
        if (fade) fade.style.opacity = '0';
      } else {
        wrap.style.height    = '80px';
        extras.style.height  = '0px';
        extras.style.opacity = '0';
        if (fade) fade.style.opacity = '1';
      }
    });
  }

  isExpanded(i: number): boolean {
    return !!this.expandedProjects[i];
  }

  getIdx(i: number): number {
    if (this.screenshotIndex[i] === undefined) this.screenshotIndex[i] = 0;
    return this.screenshotIndex[i];
  }
  prevShot(i: number, len: number): void { this.changeShot(i, (this.getIdx(i) - 1 + len) % len); }
  nextShot(i: number, len: number): void { this.changeShot(i, (this.getIdx(i) + 1) % len); }

  changeShot(i: number, next: number): void {
    this.fadingOut[i] = true;
    setTimeout(() => {
      this.screenshotIndex[i] = next;
      this.fadingOut[i] = false;
    }, 300);
  }

  focusAreas = [
    'Aplicaciones web de una sola página (SPA)',
    'Apps móviles híbridas con Ionic',
    'Backends en tiempo real con Firebase',
    'Proyectos IoT y automatización',
    'Interfaces accesibles y responsivas',
  ];

  ngAfterViewInit(): void {
    document.querySelectorAll<HTMLElement>('.project-desc-wrap').forEach(el => {
      el.style.height = '80px';
    });
    document.querySelectorAll<HTMLElement>('.project-extras').forEach(el => {
      el.style.height = '0px';
      el.style.opacity = '0';
    });
    // defer so browser has computed layout (offsetWidth/Height available)
    setTimeout(() => this.initBlobs(), 60);
  }

  ngOnInit(): void {
    AOS.init({ duration: 700, once: true, offset: 60 });
    this.autoPlayInterval = setInterval(() => {
      this.projects.forEach((p, i) => {
        if (p.screenshots && p.screenshots.length > 1 && this.lightboxProjectIdx === null) {
          this.nextShot(i, p.screenshots.length);
        }
      });
    }, 3500);
  }

  ngOnDestroy(): void {
    clearInterval(this.autoPlayInterval);
    cancelAnimationFrame(this.blobAnimFrame);
    if (this.heroSectionRef?.nativeElement) {
      this.heroSectionRef.nativeElement.removeEventListener('mousemove', this.blobMouseMove);
    }
  }

  private makeBlob(x: number, y: number, r: number, color: string, vx = 0, vy = 0): BlobParticle {
    return {
      x, y, vx, vy,
      r, targetR: r,
      color, alpha: 1,
      dying: false, dyingTimer: 0,
      splitCooldown: 0,
      driftAngle: Math.random() * Math.PI * 2,
      driftSpeed: 0.2 + Math.random() * 0.15,
    };
  }

  // Draws a smooth organic oval using bezier curves through noisy control points
  private drawOrganicBlob(ctx: CanvasRenderingContext2D, b: BlobParticle, t: number): void {
    const N = 10; // control points
    const speed = Math.sqrt(b.vx * b.vx + b.vy * b.vy);
    // Squish in direction of motion: stretch perpendicular, compress along velocity
    const motionAngle = Math.atan2(b.vy || 0.001, b.vx || 0.001);
    const squish = Math.min(speed * 0.08, 0.35); // max 35% deformation

    const pts: { x: number; y: number }[] = [];
    for (let i = 0; i < N; i++) {
      const angle = (i / N) * Math.PI * 2;
      // Multi-frequency noise for organic feel
      const noise =
        b.r * 0.18 * Math.sin(t * 0.5 + angle * 2.1 + b.driftAngle * 0.3) +
        b.r * 0.09 * Math.sin(t * 0.9 + angle * 3.7 + b.driftAngle) +
        b.r * 0.05 * Math.cos(t * 1.3 + angle * 5.1);
      // Oval aspect ratio (slightly wider than tall, random per blob)
      const rx0 = (b.r + noise) * (1.0 + 0.18 * Math.sin(b.driftAngle));
      const ry0 = (b.r + noise) * (1.0 - 0.12 * Math.sin(b.driftAngle));
      // Apply motion squish in local frame
      const localAngle = angle - motionAngle;
      const sStretch = 1 + squish * Math.abs(Math.sin(localAngle));
      const sSqueeze = 1 - squish * 0.5 * Math.abs(Math.cos(localAngle));
      pts.push({ x: rx0 * Math.cos(angle) * sSqueeze, y: ry0 * Math.sin(angle) * sStretch });
    }

    // Smooth bezier through all points
    ctx.beginPath();
    for (let i = 0; i < N; i++) {
      const curr = pts[i];
      const next = pts[(i + 1) % N];
      const mid = { x: (curr.x + next.x) / 2, y: (curr.y + next.y) / 2 };
      i === 0 ? ctx.moveTo(mid.x, mid.y) : ctx.lineTo(mid.x, mid.y);
      ctx.quadraticCurveTo(next.x, next.y, ((next.x + pts[(i + 2) % N].x) / 2), ((next.y + pts[(i + 2) % N].y) / 2));
    }
    ctx.closePath();
  }

  private initBlobs(): void {
    const canvas = this.blobCanvasRef?.nativeElement;
    const hero = this.heroSectionRef?.nativeElement;
    if (!canvas || !hero) return;

    const W = hero.offsetWidth;
    const H = hero.offsetHeight;
    canvas.width = W;
    canvas.height = H;
    const ctx = canvas.getContext('2d')!;

    this.blobs = [];
    const positions = [
      { x: W * 0.13, y: H * 0.30 },
      { x: W * 0.82, y: H * 0.22 },
      { x: W * 0.24, y: H * 0.68 },
      { x: W * 0.76, y: H * 0.64 },
    ];
    positions.forEach((p, i) => {
      const b = this.makeBlob(p.x, p.y, 52 + Math.random() * 14, this.BLOB_COLORS[i % this.BLOB_COLORS.length]);
      b.vx = (Math.random() - 0.5) * 0.5;
      b.vy = (Math.random() - 0.5) * 0.5;
      this.blobs.push(b);
    });

    // Spawn confetti dashes — spread all around the hero including sides and below photo
    const DASH_COLORS = ['#5b52e8', '#d43f8c', '#6366f1', '#2ec4b6'];
    const dashDefs = [
      // original right cluster
      { px: 0.52, py: 0.22 }, { px: 0.62, py: 0.18 }, { px: 0.70, py: 0.28 },
      { px: 0.75, py: 0.15 }, { px: 0.58, py: 0.35 }, { px: 0.80, py: 0.12 },
      { px: 0.72, py: 0.40 }, { px: 0.85, py: 0.20 }, { px: 0.88, py: 0.30 },
      { px: 0.90, py: 0.10 }, { px: 0.65, py: 0.45 }, { px: 0.93, py: 0.25 },
      { px: 0.82, py: 0.38 }, { px: 0.68, py: 0.16 }, { px: 0.78, py: 0.32 },
      // below and sides of photo
      { px: 0.60, py: 0.62 }, { px: 0.72, py: 0.70 }, { px: 0.83, py: 0.60 },
      { px: 0.91, py: 0.55 }, { px: 0.67, py: 0.78 }, { px: 0.79, py: 0.82 },
      { px: 0.88, py: 0.72 }, { px: 0.55, py: 0.75 }, { px: 0.95, py: 0.65 },
      // left side of hero
      { px: 0.05, py: 0.18 }, { px: 0.10, py: 0.42 }, { px: 0.04, py: 0.60 },
      { px: 0.14, py: 0.70 }, { px: 0.08, py: 0.85 }, { px: 0.20, py: 0.55 },
      // centre-left scatter
      { px: 0.30, py: 0.10 }, { px: 0.38, py: 0.68 }, { px: 0.42, py: 0.82 },
      { px: 0.25, py: 0.88 }, { px: 0.47, py: 0.55 },
    ];
    this.dashes = dashDefs.map((d, i) => {
      const ox = d.px * W; const oy = d.py * H;
      const ang = (Math.random() * 160 - 80) * Math.PI / 180;
      return { x: ox, y: oy, ox, oy, vx: 0, vy: 0,
        angle: ang,
        w: 11 + Math.random() * 6, h: 3.5 + Math.random() * 2.5,
        color: DASH_COLORS[i % DASH_COLORS.length] };
    });

    // Goo blob — position relative to canvas (hero)
    const frame = this.blobFrameRef?.nativeElement;
    if (frame) {
      const heroRect = hero.getBoundingClientRect();
      const frameRect = frame.getBoundingClientRect();
      const cx = frameRect.left - heroRect.left + frameRect.width / 2;
      const cy = frameRect.top  - heroRect.top  + frameRect.height / 2;
      this.gooCenter = { x: cx, y: cy };
      this.gooR = frameRect.width * 0.40; // 80% of frame = white blob diameter → radius 40%
      const N = 18;
      this.gooPoints = Array.from({ length: N }, (_, i) => {
        const angle = (i / N) * Math.PI * 2;
        const bx = cx + Math.cos(angle) * this.gooR;
        const by = cy + Math.sin(angle) * this.gooR;
        return { bx, by, x: bx, y: by, vx: 0, vy: 0 };
      });
    }

    this.blobMouseMove = (e: MouseEvent) => {
      const rect = hero.getBoundingClientRect();
      this.blobMouse.x = e.clientX - rect.left;
      this.blobMouse.y = e.clientY - rect.top;
    };
    hero.addEventListener('mousemove', this.blobMouseMove);

    let t = 0;
    const MAX_SPEED = 4.5;
    const animate = () => {
      t += 0.007;
      ctx.clearRect(0, 0, W, H);
      const mx = this.blobMouse.x;
      const my = this.blobMouse.y;
      // ── Goo blob ─────────────────────────────────────────────────────────
      if (this.gooPoints.length) {
        const gcx = this.gooCenter.x;
        const gcy = this.gooCenter.y;
        const gR  = this.gooR;
        // Cursor position relative to blob center
        const cvx = mx - gcx;
        const cvy = my - gcy;
        const cDist = Math.sqrt(cvx * cvx + cvy * cvy);
        const cursorAngle = Math.atan2(cvy, cvx);
        // Proximity: full effect when cursor is near the rim, fades out far away
        const NEAR = gR * 2.4;
        const proximity = Math.max(0, 1 - cDist / NEAR); // 0..1
        const BULGE = gR * 0.42 * proximity; // how far the near side swells out

        const gN = this.gooPoints.length;
        this.gooPoints.forEach((p, pi) => {
          const radAngle = Math.atan2(p.by - gcy, p.bx - gcx);

          // ── Lava lamp autonomous drift (subtle, radial) ─────────────────
          const phase = pi / gN * Math.PI * 2;
          const lavaOff =
            Math.sin(t * 0.35 + phase * 1.3) * gR * 0.13 +
            Math.cos(t * 0.24 + phase * 2.1) * gR * 0.08;

          // ── Surface-tension bulge toward cursor ─────────────────────────
          // Alignment: 1 when this point faces the cursor, 0 on the sides
          let align = Math.cos(radAngle - cursorAngle);
          align = Math.max(0, align);
          // Smooth, wide bump (power 2) so neighbours move together → no spikes
          const bump = align * align * BULGE;

          // Displace the point radially OUTWARD (never toward a single spot)
          const totalOff = lavaOff + bump;
          const tx = p.bx + Math.cos(radAngle) * totalOff;
          const ty = p.by + Math.sin(radAngle) * totalOff;

          // Fluid spring — smooth & responsive
          p.vx += (tx - p.x) * 0.22;
          p.vy += (ty - p.y) * 0.22;
          p.vx *= 0.72; p.vy *= 0.72;
          p.x += p.vx; p.y += p.vy;
        });

        // Draw goo with smooth bezier
        ctx.save();
        ctx.beginPath();
        const N = this.gooPoints.length;
        for (let i = 0; i < N; i++) {
          const a = this.gooPoints[i];
          const b = this.gooPoints[(i + 1) % N];
          const mx2 = (a.x + b.x) / 2;
          const my2 = (a.y + b.y) / 2;
          i === 0 ? ctx.moveTo(mx2, my2) : ctx.lineTo(mx2, my2);
          ctx.quadraticCurveTo(b.x, b.y, (b.x + this.gooPoints[(i + 2) % N].x) / 2, (b.y + this.gooPoints[(i + 2) % N].y) / 2);
        }
        ctx.closePath();
        // White with slight blue tint and shadow
        // Animate light source position for lava lamp shimmer
        const lightX = gcx + Math.cos(t * 0.3) * gR * 0.35;
        const lightY = gcy + Math.sin(t * 0.22) * gR * 0.35;
        const gooGrad = ctx.createRadialGradient(lightX, lightY, 0, gcx, gcy, gR * 1.05);
        gooGrad.addColorStop(0,   'rgba(255,255,255,1.0)');
        gooGrad.addColorStop(0.4, 'rgba(248,250,255,0.99)');
        gooGrad.addColorStop(0.75,'rgba(232,240,255,0.97)');
        gooGrad.addColorStop(1,   'rgba(210,228,255,0.90)');
        ctx.fillStyle = gooGrad;
        ctx.shadowColor = 'rgba(91,82,232,0.22)';
        ctx.shadowBlur = 28;
        ctx.fill();
        ctx.restore();
      }
      // ─────────────────────────────────────────────────────────────────────

      const toSplit: BlobParticle[] = [];

      this.blobs.forEach(b => {
        if (b.splitCooldown > 0) b.splitCooldown--;

        // Perpetual wandering drift — never stops
        b.driftAngle += (Math.random() - 0.5) * 0.04;
        b.vx += Math.cos(b.driftAngle) * b.driftSpeed * 0.015;
        b.vy += Math.sin(b.driftAngle) * b.driftSpeed * 0.015;

        // Mouse push (gentle ripple around cursor)
        const dx = b.x - mx;
        const dy = b.y - my;
        const dist = Math.sqrt(dx * dx + dy * dy);
        const pushZone = 110;
        if (dist < pushZone && dist > 1) {
          const force = ((pushZone - dist) / pushZone) * 0.14;
          b.vx += (dx / dist) * force;
          b.vy += (dy / dist) * force;
        }

        // Detect cut: cursor passes through inner 70% of blob
        if (!b.dying && b.splitCooldown === 0 && dist < b.r * 0.7) {
          toSplit.push(b);
        }

        // Blob-blob repulsion
        this.blobs.forEach(other => {
          if (other === b) return;
          const ox = b.x - other.x;
          const oy = b.y - other.y;
          const od = Math.sqrt(ox * ox + oy * oy);
          const minD = b.r + other.r + 4;
          if (od < minD && od > 1) {
            const push = (minD - od) / minD * 0.055;
            b.vx += (ox / od) * push;
            b.vy += (oy / od) * push;
          }
        });

        // Damping — keeps energy but not forever
        b.vx *= 0.968;
        b.vy *= 0.968;

        // Speed cap
        const spd = Math.sqrt(b.vx * b.vx + b.vy * b.vy);
        if (spd > MAX_SPEED) { b.vx = (b.vx / spd) * MAX_SPEED; b.vy = (b.vy / spd) * MAX_SPEED; }

        b.x += b.vx;
        b.y += b.vy;

        // Soft boundary — bounce and redirect drift inward
        const m = b.r * 0.85;
        if (b.x < m) { b.x = m; b.vx = Math.abs(b.vx) * 0.55; b.driftAngle = (Math.random() - 0.5) * Math.PI * 0.6; }
        if (b.x > W - m) { b.x = W - m; b.vx = -Math.abs(b.vx) * 0.55; b.driftAngle = Math.PI + (Math.random() - 0.5) * 0.6; }
        if (b.y < m) { b.y = m; b.vy = Math.abs(b.vy) * 0.55; b.driftAngle = Math.PI / 2 + (Math.random() - 0.5) * 0.6; }
        if (b.y > H - m) { b.y = H - m; b.vy = -Math.abs(b.vy) * 0.55; b.driftAngle = -Math.PI / 2 + (Math.random() - 0.5) * 0.6; }

        // Grow slowly back to targetR after split
        if (!b.dying && b.r < b.targetR) b.r = Math.min(b.targetR, b.r + 0.12);

        // Draw
        ctx.save();
        ctx.globalAlpha = b.alpha;
        ctx.translate(b.x, b.y);
        this.drawOrganicBlob(ctx, b, t);
        const grad = ctx.createRadialGradient(-b.r * 0.28, -b.r * 0.28, b.r * 0.05, 0, 0, b.r * 1.15);
        grad.addColorStop(0, b.color + 'dd');
        grad.addColorStop(0.5, b.color + 'aa');
        grad.addColorStop(1, b.color + '22');
        ctx.fillStyle = grad;
        ctx.shadowColor = b.color;
        ctx.shadowBlur = 28;
        ctx.fill();
        ctx.restore();
      });

      // Process splits — strong lateral impulse
      toSplit.forEach(b => {
        const idx = this.blobs.indexOf(b);
        if (idx === -1) return;
        // Split perpendicular to cursor approach direction
        const toCursorX = mx - b.x;
        const toCursorY = my - b.y;
        const len = Math.sqrt(toCursorX * toCursorX + toCursorY * toCursorY) || 1;
        // Perpendicular vector
        const perpX = -toCursorY / len;
        const perpY =  toCursorX / len;
        const newR = b.targetR * 0.72;
        const impulse = 5.5; // strong push sideways
        const b1 = this.makeBlob(b.x + perpX * b.r * 0.3, b.y + perpY * b.r * 0.3,
          newR, b.color, perpX * impulse + b.vx * 0.5, perpY * impulse + b.vy * 0.5);
        const b2 = this.makeBlob(b.x - perpX * b.r * 0.3, b.y - perpY * b.r * 0.3,
          newR, b.color, -perpX * impulse + b.vx * 0.5, -perpY * impulse + b.vy * 0.5);
        b1.splitCooldown = 80;
        b2.splitCooldown = 80;
        // Spawn slightly offset so they don't overlap immediately
        this.blobs.splice(idx, 1, b1, b2);
      });

      // Update & draw confetti dashes — water-fluid behavior
      this.dashes.forEach((d, di) => {
        const dx = d.x - mx;
        const dy = d.y - my;
        const dist = Math.sqrt(dx * dx + dy * dy);

        // Wide ripple zone — gradual push, like water surface
        const ripple = 160;
        if (dist < ripple && dist > 1) {
          // Force falls off smoothly (cosine curve, not linear)
          const t2 = (dist / ripple);
          const wave = (1 - t2 * t2) * 0.42;
          d.vx += (dx / dist) * wave;
          d.vy += (dy / dist) * wave;
        }

        // Very gentle spring back — floats back slowly, not snapping
        const pullX = d.ox - d.x;
        const pullY = d.oy - d.y;
        const pullDist = Math.sqrt(pullX * pullX + pullY * pullY);
        // Weaker spring when close to home (feels like floating), stronger when far
        const springK = 0.004 + pullDist * 0.00018;
        d.vx += pullX * springK;
        d.vy += pullY * springK;

        // Fluid damping — more drag the faster it moves (water resistance)
        const spd = Math.sqrt(d.vx * d.vx + d.vy * d.vy);
        const drag = spd > 1.5 ? 0.78 : 0.88;
        d.vx *= drag;
        d.vy *= drag;

        d.x += d.vx;
        d.y += d.vy;

        // Smooth rotation toward movement direction — lazy, not snappy
        if (spd > 0.15) {
          const targetAngle = Math.atan2(d.vy, d.vx);
          let diff = targetAngle - d.angle;
          // Normalize to [-π, π]
          while (diff > Math.PI) diff -= Math.PI * 2;
          while (diff < -Math.PI) diff += Math.PI * 2;
          d.angle += diff * 0.08;
        }

        // Gentle idle oscillation so they're never fully still
        d.x += Math.sin(t * 0.8 + di * 0.7) * 0.08;
        d.y += Math.cos(t * 0.6 + di * 0.5) * 0.06;

        // Draw dash — pill shape
        ctx.save();
        ctx.globalAlpha = 0.70 + 0.18 * Math.sin(t * 0.9 + di * 0.6);
        ctx.translate(d.x, d.y);
        ctx.rotate(d.angle);
        const hw = d.w / 2; const hh = d.h / 2; const rad = hh;
        ctx.beginPath();
        ctx.moveTo(-hw + rad, -hh);
        ctx.lineTo(hw - rad, -hh);
        ctx.arcTo(hw, -hh, hw, 0, rad);
        ctx.lineTo(hw, hh - rad);
        ctx.arcTo(hw, hh, hw - rad, hh, rad);
        ctx.lineTo(-hw + rad, hh);
        ctx.arcTo(-hw, hh, -hw, 0, rad);
        ctx.lineTo(-hw, -hh + rad);
        ctx.arcTo(-hw, -hh, -hw + rad, -hh, rad);
        ctx.closePath();
        ctx.fillStyle = d.color;
        ctx.shadowColor = d.color;
        ctx.shadowBlur = 5 + spd * 3;
        ctx.fill();
        ctx.restore();
      });

      this.blobAnimFrame = requestAnimationFrame(animate);
    };
    animate();
  }

  onBlobClick(_event: MouseEvent): void { /* disabled */ }

  contactForm = { name: '', email: '', message: '' };
  contactStatus: 'idle' | 'sending' | 'sent' | 'error' = 'idle';

  onTilt(event: MouseEvent): void {
    const card = event.currentTarget as HTMLElement;
    const rect = card.getBoundingClientRect();
    const x = event.clientX - rect.left;
    const y = event.clientY - rect.top;
    const cx = rect.width / 2;
    const cy = rect.height / 2;
    const rotateX = ((y - cy) / cy) * -8;
    const rotateY = ((x - cx) / cx) * 8;
    card.style.transform = `perspective(600px) rotateX(${rotateX}deg) rotateY(${rotateY}deg) scale(1.02)`;
    card.style.transition = 'transform 0.1s ease';
  }

  resetTilt(event: MouseEvent): void {
    const card = event.currentTarget as HTMLElement;
    card.style.transform = 'perspective(600px) rotateX(0deg) rotateY(0deg) scale(1)';
    card.style.transition = 'transform 0.4s ease';
  }

  async sendContact(): Promise<void> {
    if (!this.contactForm.name || !this.contactForm.email || !this.contactForm.message) return;
    this.contactStatus = 'sending';
    try {
      const res = await fetch('https://api.emailjs.com/api/v1.0/email/send', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          service_id: 'service_h8jbhoe',
          template_id: 'template_2ycioib',
          user_id: '0u6kiLc9fATOLPdSB',
          template_params: {
            from_name: this.contactForm.name,
            from_email: this.contactForm.email,
            message: this.contactForm.message.replace(/\n/g, '<br>'),
            to_email: 'soporte@nncoms.com',
          },
        }),
      });
      this.contactStatus = res.ok ? 'sent' : 'error';
      if (res.ok) this.contactForm = { name: '', email: '', message: '' };
    } catch {
      this.contactStatus = 'error';
    }
  }

  scrollTo(id: string): void {
    document.getElementById(id)?.scrollIntoView({ behavior: 'smooth' });
  }
}
