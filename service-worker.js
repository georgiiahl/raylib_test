// service-worker.js
self.addEventListener('install', (event) => {
    event.waitUntil(
      caches.open('game-cache').then((cache) => {
        return cache.addAll([
          '/',
          '/index.html',
          '/index.js',
          '/index.wasm',
          '/style.css',
          '/favicon.ico',
          '/manifest.json',
          '/icons/icon-192x192.png',
          '/icons/icon-256x256.png',
          '/icons/icon-384x384.png',
          '/icons/icon-512x512.png',
        ]);
      })
    );
  });
  
  self.addEventListener('fetch', (event) => {
    event.respondWith(
      caches.match(event.request).then((response) => {
        return response || fetch(event.request);
      })
    );
  });
  