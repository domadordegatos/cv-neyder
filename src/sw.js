// Service worker de la CV.
// En localhost se AUTODESTRUYE (limpia caché + se desregistra) para no chocar
// con el dev server de webpack. En producción cachea de forma segura.
const CACHE = 'cv-neyder-v3';
const isLocal = self.location.hostname === 'localhost'
  || self.location.hostname === '127.0.0.1'
  || self.location.hostname.indexOf('192.168.') === 0;

if (isLocal) {
  // Kill-switch: limpiar todo y desregistrar
  self.addEventListener('install', () => self.skipWaiting());
  self.addEventListener('activate', (event) => {
    event.waitUntil((async () => {
      const keys = await caches.keys();
      await Promise.all(keys.map((k) => caches.delete(k)));
      await self.registration.unregister();
      const clients = await self.clients.matchAll();
      clients.forEach((c) => { try { c.navigate(c.url); } catch (e) {} });
    })());
  });
} else {
  self.addEventListener('install', (e) => {
    self.skipWaiting();
    e.waitUntil(caches.open(CACHE).then((c) => c.add('/')));
  });

  self.addEventListener('activate', (e) => {
    e.waitUntil(
      caches.keys()
        .then((keys) => Promise.all(keys.filter((k) => k !== CACHE).map((k) => caches.delete(k))))
        .then(() => self.clients.claim())
    );
  });

  self.addEventListener('fetch', (event) => {
    const req = event.request;
    if (req.method !== 'GET') return;
    const url = new URL(req.url);
    if (url.origin !== self.location.origin) return; // no tocar API/CDN/fuentes

    // Navegaciones → network-first con fallback al index cacheado
    if (req.mode === 'navigate') {
      event.respondWith(
        fetch(req).then((res) => {
          const copy = res.clone();
          caches.open(CACHE).then((c) => c.put('/', copy));
          return res;
        }).catch(() => caches.match('/'))
      );
      return;
    }

    // Recursos estáticos (hash inmutable) → cache-first
    event.respondWith(
      caches.match(req).then((cached) => cached || fetch(req).then((res) => {
        const copy = res.clone();
        caches.open(CACHE).then((c) => c.put(req, copy));
        return res;
      }).catch(() => cached))
    );
  });
}
