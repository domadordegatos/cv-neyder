import { Component, OnInit } from '@angular/core';
import * as AOS from 'aos';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.scss']
})
export class HomeComponent implements OnInit {

  currentYear = new Date().getFullYear();

  skillsFront = [
    { name: 'JavaScript', icon: 'assets/1200px-Javascript-shield.svg.png' },
    { name: 'TypeScript', icon: null },
    { name: 'Angular', icon: 'assets/angular-icon-logo.png' },
    { name: 'Ionic', icon: 'assets/ionic.png' },
    { name: 'HTML & CSS', icon: null },
    { name: 'Bootstrap', icon: null },
  ];

  skillsBack = [
    { name: 'Node.js', icon: 'assets/node.png' },
    { name: 'Firebase', icon: 'assets/firebase-3521427-2944871.png' },
    { name: 'Firestore', icon: null },
    { name: 'REST APIs', icon: null },
  ];

  skillsHard = [
    { name: 'Arduino', icon: 'assets/arduino-logo-1.png' },
    { name: 'C++', icon: 'assets/1200px-ISO_C++_Logo.svg.png' },
    { name: 'IoT', icon: null },
    { name: 'Git', icon: null },
  ];

  alsoWith = [
    'RxJS y programación reactiva',
    'Autenticación con Firebase Auth',
    'Despliegue en Firebase Hosting',
    'Control de versiones con Git',
    'Diseño responsivo mobile-first',
    'Sensores y módulos Arduino',
  ];

  projects = [
    {
      title: 'CV / Portfolio Personal',
      subtitle: 'Una web para presentar mi trabajo al mundo',
      desc: 'Desarrollado con Angular 13, Firebase y Bootstrap 5. Incluye animaciones, diseño responsivo y despliegue continuo en Firebase Hosting.',
      tags: ['Angular', 'Firebase', 'Bootstrap'],
      repo: 'https://github.com/domadordegatos/cv-neyder',
      demo: 'https://cv-neyder.web.app',
    },
    {
      title: 'App de Gestión con Ionic',
      subtitle: 'Aplicación híbrida para Android e iOS',
      desc: 'App móvil construida con Ionic y Angular para la gestión de tareas y usuarios, con autenticación Firebase y base de datos en tiempo real.',
      tags: ['Ionic', 'Firebase', 'TypeScript'],
      repo: 'https://github.com/domadordegatos',
      demo: null,
    },
    {
      title: 'Sistema IoT con Arduino',
      subtitle: 'Monitoreo ambiental en tiempo real',
      desc: 'Dispositivo de monitoreo que mide humedad y temperatura con sensores DHT11, envía datos por módulo HC-05 y los visualiza en un dashboard web.',
      tags: ['Arduino', 'C++', 'IoT'],
      repo: 'https://github.com/domadordegatos',
      demo: null,
    },
    {
      title: 'API REST con Node.js',
      subtitle: 'Backend para una aplicación de inventario',
      desc: 'Servidor Express.js con autenticación JWT, CRUD completo y documentación con Swagger. Consume y expone datos en JSON.',
      tags: ['Node.js', 'Express', 'JavaScript'],
      repo: 'https://github.com/domadordegatos',
      demo: null,
    },
  ];

  focusAreas = [
    'Aplicaciones web de una sola página (SPA)',
    'Apps móviles híbridas con Ionic',
    'Backends en tiempo real con Firebase',
    'Proyectos IoT y automatización',
    'Interfaces accesibles y responsivas',
  ];

  ngOnInit(): void {
    AOS.init({ duration: 700, once: true, offset: 60 });
  }

  scrollTo(id: string): void {
    document.getElementById(id)?.scrollIntoView({ behavior: 'smooth' });
  }
}
