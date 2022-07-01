import { Component, OnInit } from '@angular/core';
import { Observable } from 'rxjs';
import { DataSvcService } from 'src/app/services/data-svc.service';
import { awardsI } from '../models/awards';
import { coursesI } from '../models/courses';

@Component({
  selector: 'app-courses',
  templateUrl: './courses.component.html',
  styleUrls: ['./courses.component.scss']
})
export class CoursesComponent implements OnInit {
  public courses$: Observable<coursesI[]>;
  public awards$: Observable<awardsI[]>;
  public awardsIndi$: Observable<awardsI[]>;
  constructor(private dataSvc: DataSvcService) { }

  ngOnInit(): void {
    this.courses$ = this.dataSvc.getCoursesView();
    this.awards$ = this.dataSvc.getAwardsView();
  }

  openAward(id:string){
    console.log("id",id);
    this.awardsIndi$ = this.dataSvc.getAwardIndiView(id);
  }
}
