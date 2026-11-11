import { Injectable } from '@angular/core';
import { io, Socket } from 'socket.io-client';
import { environment } from 'src/environments/environment';

export type RealtimeEvent = 'inserted' | 'updated' | 'deleted';
export interface RealtimeChange { event: RealtimeEvent; data: any; }

/**
 * Tiempo real vía Socket.io contra la API de nncoms.
 * Contrato del servidor:
 *   socket.emit('join', { db, col, apiKey })
 *   socket.on('inserted' | 'updated' | 'deleted', data => ...)
 *
 * Se abre un socket por colección para que los eventos no se mezclen entre
 * colecciones (los nombres de evento son compartidos por conexión).
 */
@Injectable({ providedIn: 'root' })
export class RealtimeService {
  private readonly url = environment.api.url;
  private readonly db = environment.api.db;
  private readonly key = environment.api.key;

  /**
   * Suscribe a los cambios de una colección.
   * @returns función para cancelar la suscripción (cierra el socket).
   */
  subscribe(col: string, onChange: (change: RealtimeChange) => void): () => void {
    let socket: Socket;
    try {
      socket = io(this.url, {
        transports: ['websocket', 'polling'],
        reconnectionAttempts: 5,
        timeout: 8000,
      });
    } catch {
      return () => {};
    }

    socket.on('connect', () => {
      socket.emit('join', { db: this.db, col, apiKey: this.key });
    });

    const events: RealtimeEvent[] = ['inserted', 'updated', 'deleted'];
    events.forEach((ev) => socket.on(ev, (data: any) => onChange({ event: ev, data })));

    // No spamear la consola si la API no está accesible
    socket.on('connect_error', () => {});

    return () => {
      try { socket.removeAllListeners(); socket.disconnect(); } catch { /* noop */ }
    };
  }
}
