import { Component, OnInit } from '@angular/core';
import { Observable } from 'rxjs';
import { DataSvcService } from 'src/app/services/data-svc.service';
import { profileI } from '../models/profile';

@Component({
  selector: 'app-contact',
  templateUrl: './contact.component.html',
  styleUrls: ['./contact.component.scss']
})
export class ContactComponent implements OnInit {

  public dataProfile$: Observable<profileI[]>;
  constructor(private dataSvc: DataSvcService) { }

  ngOnInit(): void {
    this.dataProfile$ = this.dataSvc.getDataProfile();
  }

}
