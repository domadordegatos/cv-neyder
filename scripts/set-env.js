/**
 * Genera src/environments/environment.ts y environment.prod.ts.
 *
 * Por qué existe: la clave de api.nncoms.com no debe quedar escrita en ningún
 * archivo que se comitee. Los dos environment están en .gitignore y se generan
 * aquí, en cada build, a partir del entorno.
 *
 * De dónde saca los valores, por orden de prioridad:
 *   1. variables de entorno reales (lo que usa CI: secrets del repo)
 *   2. un archivo .env en la raíz (desarrollo local; también está ignorado)
 *   3. los valores por defecto de abajo
 *
 * Uso: se dispara solo, por el "prebuild"/"prestart" de package.json.
 * A mano:  node scripts/set-env.js
 *
 * Si NO hay API_KEY no falla a propósito: avisa y escribe key: ''. Así quien
 * clone el repo sin credenciales puede compilar y ver el sitio; lo único que
 * no funcionará son las secciones que leen de la API. Un fallo duro aquí
 * dejaría el repositorio inservible para cualquiera de fuera.
 */
const fs = require('fs');
const path = require('path');
const { entorno } = require('./leer-env');

const raiz = path.join(__dirname, '..');
const carpeta = path.join(raiz, 'src', 'environments');

// process.env manda sobre el .env: en CI los valores vienen de los secrets.
const env = entorno();

const API_URL = env.API_URL || 'https://api.nncoms.com';
const API_DB = env.API_DB || 'cvneyder';
const API_KEY = env.API_KEY || '';

function contenido(produccion) {
  return `// ARCHIVO GENERADO por scripts/set-env.js. No lo edites a mano:
// se reescribe en cada build y está en .gitignore.
// Para cambiar la clave de la API edita el .env de la raíz.

export const environment = {
  production: ${produccion},
  api: {
    url: '${API_URL}',
    key: '${API_KEY}',
    db: '${API_DB}',
  },
};
`;
}

fs.mkdirSync(carpeta, { recursive: true });
fs.writeFileSync(path.join(carpeta, 'environment.ts'), contenido(false), 'utf8');
fs.writeFileSync(path.join(carpeta, 'environment.prod.ts'), contenido(true), 'utf8');

if (API_KEY) {
  console.log(`set-env: environment generado (API ${API_URL}, base ${API_DB}, clave presente).`);
} else {
  console.warn(
    'set-env: AVISO - no hay API_KEY, se generó con key vacia.\n' +
      '          El sitio compila, pero lo que lee de api.nncoms.com saldra vacio.\n' +
      '          Local: copia .env.example a .env y pon la clave.\n' +
      '          CI: anade API_KEY como secret del repositorio.',
  );
}
