import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { HomeComponent } from './components/home/home.component';
import { ProyectosComponent } from './components/proyectos/proyectos.component';
import { AboutComponent } from './components/about/about.component';
import { StudiesComponent } from './components/studies/studies.component';

const routes: Routes = [
  {path:'home', component:HomeComponent},
  {path:'projects',component:ProyectosComponent},
  {path:'about', component:AboutComponent},
  {path:'studies', component:StudiesComponent},
  {path:'**', redirectTo:'home'}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
