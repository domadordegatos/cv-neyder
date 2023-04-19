import { Component, OnInit, TemplateRef } from '@angular/core';
import { Observable } from 'rxjs';
import { DataSvcService } from 'src/app/services/data-svc.service';
import { proyectsI } from '../models/proyects';
import AOS from "aos";

@Component({
  selector: 'app-proyectos',
  templateUrl: './proyectos.component.html',
  styleUrls: ['./proyectos.component.scss']
})
export class ProyectosComponent implements OnInit {
  public proyects$: Observable<proyectsI[]>
  public proyectsIndi$: Observable<proyectsI[]>;
  constructor(private dataSvc: DataSvcService) { }

  ngOnInit(): void {
    AOS.init();
    this.proyects$ = this.dataSvc.getProyectsLenguages();
  }

  openImages(id:string){
    console.log("id",id);
    this.proyectsIndi$ = this.dataSvc.getDataProyectsImage(id)
  }

}
