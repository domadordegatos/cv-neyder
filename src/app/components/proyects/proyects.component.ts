import { Component, OnInit, TemplateRef } from '@angular/core';
import { Observable } from 'rxjs';
import { DataSvcService } from 'src/app/services/data-svc.service';
import { proyectsI } from '../models/proyects';

@Component({
  selector: 'app-proyects',
  templateUrl: './proyects.component.html',
  styleUrls: ['./proyects.component.scss'],
})
export class ProyectsComponent implements OnInit {
  public php$: Observable<proyectsI[]>;
  public ang$: Observable<proyectsI[]>;
  public proyectsIndi$: Observable<proyectsI[]>;
  constructor(private dataSvc: DataSvcService) { }

  ngOnInit(): void {
    this.php$ = this.dataSvc.getLenguageView("php");
    this.ang$ = this.dataSvc.getLenguageView("ang");
  }

  openImages(id:string){
    console.log("id",id);
    this.proyectsIndi$ = this.dataSvc.getDataProyectsImage(id)
  }

}
