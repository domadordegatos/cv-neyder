/**
 * Puebla las colecciones de MongoDB (vía la API de nncoms) con el contenido
 * actual de la CV, leído de scripts/seed-data.json.
 *
 * Uso:
 *   node scripts/seed-mongo.js
 *
 * La clave se toma del .env de la raíz (API_KEY) o de una variable de entorno
 * real, que tiene prioridad. NO hay valor por defecto a propósito: este script
 * ESCRIBE en la base, y un valor por defecto significaría que cualquiera que
 * clone el repositorio puede sobrescribir colecciones sin haber puesto ninguna
 * credencial de forma deliberada. Si falta la clave, aborta.
 *
 * Requiere Node 18+ (fetch global).
 */
const fs = require('fs');
const path = require('path');
const { entorno } = require('./leer-env');

const env = entorno();
const API_URL = (env.API_URL || 'https://api.nncoms.com').replace(/\/+$/, '');
const API_KEY = env.API_KEY || '';
const DB = env.API_DB || env.DB || 'cvneyder';

if (!API_KEY) {
  console.error(
    'seed-mongo: falta la clave de la API. Este script escribe en la base, así que\n' +
      'no se ejecuta sin una credencial puesta a propósito.\n' +
      '  Opción 1: copia .env.example a .env y rellena API_KEY.\n' +
      '  Opción 2: pásala en la llamada:  API_KEY=... node scripts/seed-mongo.js',
  );
  process.exit(1);
}

const data = JSON.parse(fs.readFileSync(path.join(__dirname, 'seed-data.json'), 'utf8'));

async function post(collection, doc) {
  const res = await fetch(`${API_URL}/api/${DB}/${collection}`, {
    method: 'POST',
    headers: { 'Content-Type': 'application/json', 'X-API-Key': API_KEY },
    body: JSON.stringify(doc),
  });
  if (!res.ok) {
    const txt = await res.text().catch(() => '');
    throw new Error(`HTTP ${res.status} ${collection}: ${txt.slice(0, 200)}`);
  }
}

(async () => {
  const collections = ['skills', 'experience', 'education', 'certifications', 'projects'];
  for (const col of collections) {
    const items = data[col] || [];
    let ok = 0;
    for (const item of items) {
      try { await post(col, item); ok++; }
      catch (e) { console.error(`  ✗ ${e.message}`); }
    }
    console.log(`${col}: ${ok}/${items.length} insertados`);
  }
  console.log('\nListo. Verifica en la vista /admin o directamente en Mongo.');
})();
