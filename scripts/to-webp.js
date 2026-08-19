// Convierte todas las imágenes raster (png/jpg/jpeg) de src/assets a WebP.
// Elimina el original tras convertir. No toca SVG ni favicon.
const fs = require('fs');
const path = require('path');
const sharp = require('sharp');

const ASSETS = path.join(__dirname, '..', 'src', 'assets');
const EXT = new Set(['.png', '.jpg', '.jpeg']);

function walk(dir) {
  let files = [];
  for (const name of fs.readdirSync(dir)) {
    const full = path.join(dir, name);
    const stat = fs.statSync(full);
    if (stat.isDirectory()) files = files.concat(walk(full));
    else files.push(full);
  }
  return files;
}

(async () => {
  const all = walk(ASSETS);
  let before = 0, after = 0, count = 0;
  for (const file of all) {
    const ext = path.extname(file).toLowerCase();
    if (!EXT.has(ext)) continue;
    const out = file.slice(0, -ext.length) + '.webp';
    const origSize = fs.statSync(file).size;
    try {
      await sharp(file).webp({ quality: 82 }).toFile(out);
      const newSize = fs.statSync(out).size;
      before += origSize; after += newSize; count++;
      fs.unlinkSync(file); // borra el original
      console.log(`${(origSize/1024).toFixed(0)}KB -> ${(newSize/1024).toFixed(0)}KB  ${path.relative(ASSETS, out)}`);
    } catch (e) {
      console.error(`ERROR ${file}: ${e.message}`);
    }
  }
  console.log(`\n${count} imágenes: ${(before/1024/1024).toFixed(1)}MB -> ${(after/1024/1024).toFixed(1)}MB`);
})();
