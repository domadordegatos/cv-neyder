import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { ProfileComponent } from './components/profile/profile.component';
import { ProyectsComponent } from './components/proyects/proyects.component';
import { WorksComponent } from './components/works/works.component';
import { EducationComponent } from './components/education/education.component';
import { CoursesComponent } from './components/courses/courses.component';

import { AngularFireModule } from '@angular/fire/compat';
import { AngularFireAuthModule } from '@angular/fire/compat/auth';
import { AngularFireStorageModule } from '@angular/fire/compat/storage';
import { AngularFirestoreModule } from '@angular/fire/compat/firestore';
import { environment } from 'src/environments/environment';
import { ContactComponent } from './components/contact/contact.component';
import { StickyComponent } from './components/sticky/sticky.component';
import { TooltipModule } from 'ngx-bootstrap/tooltip';
import 'animate.css';

@NgModule({
  declarations: [
    AppComponent,
    ProfileComponent,
    ProyectsComponent,
    WorksComponent,
    EducationComponent,
    CoursesComponent,
    ContactComponent,
    StickyComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    AngularFireAuthModule,
    AngularFirestoreModule,
    AngularFireStorageModule,
    TooltipModule.forRoot(),
    AngularFireModule.initializeApp(environment.firebaseConfig)
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
