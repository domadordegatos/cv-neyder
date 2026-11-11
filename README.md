# NeyderHv

This project was generated with [Angular CLI](https://github.com/angular/angular-cli) version 13.3.0.

## Development server

Run `ng serve` for a dev server. Navigate to `http://localhost:4200/`. The application will automatically reload if you change any of the source files.

## Code scaffolding

Run `ng generate component component-name` to generate a new component. You can also use `ng generate directive|pipe|service|class|guard|interface|enum|module`.

## Configuracion (hazlo antes de compilar)

Este proyecto consume una API propia (`api.nncoms.com`) con una clave que **no
esta en el repositorio**. Los archivos `src/environments/environment.ts` y
`environment.prod.ts` no se comitean: los genera `scripts/set-env.js` en cada
build a partir del entorno.

```bash
cp .env.example .env     # y rellena API_KEY
npm install
npm run build            # el prebuild genera los environment solo
```

Sin `API_KEY` el proyecto **compila igual** y el sitio se ve; lo unico que
quedara vacio son las secciones que leen de la API. En integracion continua la
clave va como *secret* del repositorio, nunca en un archivo.

Para repoblar las colecciones desde `scripts/seed-data.json`:

```bash
node scripts/seed-mongo.js
```

Ese si exige `API_KEY` y aborta sin ella, porque escribe en la base.

## Build

Run `ng build` to build the project. The build artifacts will be stored in the `dist/` directory.

## Running unit tests

Run `ng test` to execute the unit tests via [Karma](https://karma-runner.github.io).

## Running end-to-end tests

Run `ng e2e` to execute the end-to-end tests via a platform of your choice. To use this command, you need to first add a package that implements end-to-end testing capabilities.

## Further help

To get more help on the Angular CLI use `ng help` or go check out the [Angular CLI Overview and Command Reference](https://angular.io/cli) page.
