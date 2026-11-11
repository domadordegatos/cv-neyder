/**
 * Lector de .env, compartido por set-env.js y seed-mongo.js.
 *
 * Sin dependencias a propósito: es un formato CLAVE=valor de una línea y meter
 * un paquete para esto obligaría a tocar package-lock.json.
 *
 * Las variables de entorno reales tienen prioridad sobre el .env, para que en
 * CI manden los secrets del repositorio y no un archivo que nunca llega allí.
 */
const fs = require('fs');
const path = require('path');

function leerDotEnv(archivo) {
  if (!fs.existsSync(archivo)) return {};
  const salida = {};
  for (const linea of fs.readFileSync(archivo, 'utf8').split(/\r?\n/)) {
    const t = linea.trim();
    if (!t || t.startsWith('#')) continue;
    const corte = t.indexOf('=');
    if (corte < 1) continue;
    const clave = t.slice(0, corte).trim();
    let valor = t.slice(corte + 1).trim();
    const entrecomillado =
      (valor.startsWith('"') && valor.endsWith('"')) ||
      (valor.startsWith("'") && valor.endsWith("'"));
    if (entrecomillado) valor = valor.slice(1, -1);
    salida[clave] = valor;
  }
  return salida;
}

/** El entorno efectivo: .env de la raíz del proyecto, pisado por process.env. */
function entorno() {
  const raiz = path.join(__dirname, '..');
  return { ...leerDotEnv(path.join(raiz, '.env')), ...process.env };
}

module.exports = { leerDotEnv, entorno };
