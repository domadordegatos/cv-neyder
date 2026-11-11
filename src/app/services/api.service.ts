import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Observable } from 'rxjs';
import { map } from 'rxjs/operators';
import { environment } from 'src/environments/environment';

/**
 * Cliente genérico para la API de MongoDB (api.nncoms.com).
 * Patrón de rutas:  {url}/api/{db}/{collection}
 * Auth:             header  X-API-Key
 */
@Injectable({ providedIn: 'root' })
export class ApiService {
  private readonly base = environment.api.url.replace(/\/+$/, '');
  private readonly db = environment.api.db;

  constructor(private http: HttpClient) {}

  private headers(): HttpHeaders {
    return new HttpHeaders({
      'Content-Type': 'application/json',
      'X-API-Key': environment.api.key,
    });
  }

  private url(collection: string): string {
    return `${this.base}/api/${this.db}/${collection}`;
  }

  /** Devuelve todos los documentos de una colección como array.
   *  Acepta respuestas en forma [ ... ], { data: [...] } o { documents: [...] }. */
  list<T>(collection: string): Observable<T[]> {
    return this.http
      .get<any>(this.url(collection), { headers: this.headers() })
      .pipe(map((res) => this.unwrap<T>(res)));
  }

  /** Inserta un documento en una colección. */
  create<T>(collection: string, doc: T): Observable<any> {
    return this.http.post(this.url(collection), doc, { headers: this.headers() });
  }

  /** Actualiza parcialmente un documento por su _id. */
  update(collection: string, id: string, patch: any): Observable<any> {
    return this.http.patch(`${this.url(collection)}/${id}`, patch, { headers: this.headers() });
  }

  /** Elimina un documento por su _id. */
  remove(collection: string, id: string): Observable<any> {
    return this.http.delete(`${this.url(collection)}/${id}`, { headers: this.headers() });
  }

  /** Sube una imagen al hosting. Devuelve { url, path }. El navegador
   *  fija el Content-Type multipart automáticamente (no lo pongas a mano). */
  uploadImage(file: File, category: string, slug: string): Observable<{ url: string; path: string }> {
    const fd = new FormData();
    fd.append('file', file);
    fd.append('category', category);
    fd.append('slug', slug || 'general');
    const h = new HttpHeaders({ 'X-API-Key': environment.api.key });
    return this.http.post<{ url: string; path: string }>(`${this.base}/api/upload`, fd, { headers: h });
  }

  private unwrap<T>(res: any): T[] {
    if (Array.isArray(res)) return res as T[];
    if (res && Array.isArray(res.data)) return res.data as T[];
    if (res && Array.isArray(res.documents)) return res.documents as T[];
    if (res && Array.isArray(res.result)) return res.result as T[];
    return [];
  }
}
