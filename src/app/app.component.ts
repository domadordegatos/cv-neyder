import { Component, OnInit } from '@angular/core';
import { ThemeService } from './services/theme.service';
import { LanguageService } from './services/language.service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent implements OnInit {
  title = 'neyder-hv';

  constructor(private theme: ThemeService, private language: LanguageService) {}

  ngOnInit(): void {
    this.theme.init();
    this.language.init();
  }
}
