/************************************************************
			  LCD - Modul
*************************************************************/
#ifndef LCD_MOD_H
#define LCD_MOD_H

#include <Arduino.h>

void writeTricker()
{
  lcd.home();
  for (int i=0; i<LCD_LAENGE; i++){
    if ((tricker_n+i) >= tricker_all.length()){
      lcd.print(tricker_all[(tricker_n+i)- tricker_all.length()]);
    }else{ lcd.print(tricker_all[tricker_n+i]);}
  }
}

void lcdRefresh()
{
  lcd.home();
  lcd.clear();
  writeTricker();
  lcd.setCursor(0, 1);
  lcd.print("A| Laser on/off");
  lcd.setCursor(0, 2);
  lcd.print("B| Ethernet on/off");
  lcd.setCursor(0, 3);
  lcd.print("Alpha:");
  lcd.setCursor(11, 3);
  lcd.print("Beta:");
}

void lcd_runtime()
{
  if ((millis() - clear_t) >= CLEAR_TIME){		          // Bildschirm reseten
    lcdRefresh();
    clear_t = millis();
  }

  if ((millis()- tricker_t) >= TRICKER_TIME){		        // Tricker akutalisieren
    if ((tricker_all.length()) > LCD_LAENGE){
      writeTricker();
      if (tricker_n >= tricker_all.length()) {tricker_n = 0;}
      else {tricker_n++;}
    }else{
      lcd.setCursor(0, 0);
      lcd.print(tricker_all);
    }
    tricker_t = millis();
  }
  
  /* Position der Servomotoren in Echtzeit */
  lcd.setCursor(7, 3);
  lcd.print(alphaServo.read());
  lcd.print(" ");                                      // mögliche letze Stellen löschen
  lcd.setCursor(17, 3);
  lcd.print(betaServo.read());
  lcd.print(" ");
}

#endif // LCD_MOD_H
