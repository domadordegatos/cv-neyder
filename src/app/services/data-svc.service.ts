import { Injectable } from '@angular/core';
import { map, Observable } from 'rxjs';
import { coursesI } from '../components/models/courses';
import { AngularFirestore, AngularFirestoreCollection } from '@angular/fire/compat/firestore';
import { awardsI } from '../components/models/awards';

@Injectable({
  providedIn: 'root'
})
export class DataSvcService {
  courses: Observable<coursesI[]>
  awards: Observable<awardsI[]>
  private courseCollection: AngularFirestoreCollection<coursesI>;
  private awardsCollection: AngularFirestoreCollection<awardsI>;
  private awardsIndiCollection: AngularFirestoreCollection<awardsI>;

  constructor(private readonly afs: AngularFirestore) { }

  public getCoursesView(): Observable<coursesI[]>{
          
    this.courseCollection = this.afs.collection<coursesI>('courses', p=> p.orderBy('order','asc'));
  
    return this.courseCollection
      .snapshotChanges()
      .pipe(
        map(actions =>
          actions.map(a => {
            const data = a.payload.doc.data() as coursesI;
            const id = a.payload.doc.id;
            return { id, ...data };
          })
        )
      );
  }

  public getAwardsView(): Observable<awardsI[]>{
          
    this.awardsCollection = this.afs.collection<awardsI>('awards', p=> p.orderBy('order','asc'));
  
    return this.awardsCollection
      .snapshotChanges()
      .pipe(
        map(actions =>
          actions.map(a => {
            const data = a.payload.doc.data() as awardsI;
            const id = a.payload.doc.id;
            return { id, ...data };
          })
        )
      );
  }

  public getAwardIndiView(id:string): Observable<awardsI[]>{
          
    this.awardsIndiCollection = this.afs.collection<awardsI>('awards', p=> p.where('id','==',id));
  
    return this.awardsIndiCollection
      .snapshotChanges()
      .pipe(
        map(actions =>
          actions.map(a => {
            const data = a.payload.doc.data() as awardsI;
            const id = a.payload.doc.id;
            return { id, ...data };
          })
        )
      );
  }


}

