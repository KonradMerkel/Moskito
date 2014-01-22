/************************************************************
		       Morse-Code - Funktionen
*************************************************************/
#ifndef MORSE_MOD_H
#define MORSE_MOD_H

/* Bemerkung:
** Diese Datei beinhaltet kein Modul, sondern nur einige Funktionen.
** Aufgrund der Länge der Funktionen besitzen diese dennoch ihre
** eigene Datei. Das Unterschied zur einem Modul besteht darin, dass
** es keine runtime()- Funktion gibt.
** Weiterhin kann während des sendens einer Morsenachricht nicht vom
** Gerät erledigt werden.
*/

#include <Arduino.h>

void morse_lang()
{
  laser_switch(true);
  delay(lang);
  laser_switch(false);
  delay(lang);
}
void morse_kurz()
{
  laser_switch(true);
  delay(kurz);
  laser_switch(false);
  delay(kurz);
}

void morse(String str)
{
  #if MOSKITO_SERIAL_DEBUGGING
  Serial.println("beginne zu morsen");
  #endif
  if (str == "") {return;}
  for (int i=0; i < str.length(); i++)
  {
    switch ((char)str[i]){
      case ' ':
        delay(EndOfWord);
        break;
      case 1:
        morse_kurz();
        morse_lang();
        morse_lang();
        morse_lang();
        morse_lang();
        delay(EndOfChar);
        break;
      case 2:
        morse_kurz();
        morse_kurz();
        morse_lang();
        morse_lang();
        morse_lang();
        delay(EndOfChar);
        break;
      case 3:
        morse_kurz();
        morse_kurz();
        morse_kurz();
        morse_lang();
        morse_lang();
        delay(EndOfChar);
        break;
      case 4:
        morse_kurz();
        morse_kurz();
        morse_kurz();
        morse_kurz();
        morse_lang();
        delay(EndOfChar);
        break;
      case 5:
        morse_kurz();
        morse_kurz();
        morse_kurz();
        morse_kurz();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 6:
        morse_lang();
        morse_kurz();
        morse_kurz();
        morse_kurz();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 7:
        morse_lang();
        morse_lang();
        morse_kurz();
        morse_kurz();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 8:
        morse_lang();
        morse_lang();
        morse_lang();
        morse_kurz();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 9:
        morse_lang();
        morse_lang();
        morse_lang();
        morse_lang();
        morse_kurz();
        break;
      case 0:
        morse_lang();
        morse_lang();
        morse_lang();
        morse_lang();
        delay(EndOfChar);
        break;
      case 'A': case 'a':
        morse_kurz();
        morse_lang();
        delay(EndOfChar);
        break;
      case 'B': case 'b':
        morse_lang();
        morse_kurz();
        morse_kurz();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 'C': case 'c':
        morse_lang();
        morse_kurz();
        morse_lang();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 'D': case 'd':
        morse_lang();
        morse_kurz();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 'E': case 'e':
        morse_kurz();
        delay(EndOfChar);
        break;
      case 'F': case 'f':
        morse_kurz();
        morse_kurz();
        morse_lang();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 'G': case 'g':
        morse_lang();
        morse_lang();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 'H': case 'h':
        morse_kurz();
        morse_kurz();
        morse_kurz();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 'I': case 'i':
        morse_kurz();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 'J': case 'j':
        morse_kurz();
        morse_lang();
        morse_lang();
        morse_lang();
        delay(EndOfChar);
        break;
      case 'K': case 'k':
        morse_lang();
        morse_kurz();
        morse_lang();
        delay(EndOfChar);
        break;
      case 'L': case 'l':
        morse_kurz();
        morse_lang();
        morse_kurz();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 'M': case 'm':
        morse_lang();
        morse_lang();
        delay(EndOfChar);
        break;
      case 'N': case 'n':
        morse_lang();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 'O': case 'o':
        morse_lang();
        morse_lang();
        morse_lang();
        delay(EndOfChar);
        break;
      case 'P': case 'p':
        morse_kurz();
        morse_lang();
        morse_lang();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 'Q': case 'q':
        morse_lang();
        morse_lang();
        morse_kurz();
        morse_lang();
        delay(EndOfChar);
        break;
      case 'R': case 'r':
        morse_kurz();
        morse_lang();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 'S': case 's':
        morse_kurz();
        morse_kurz();
        morse_kurz();
        delay(EndOfChar);
        break;
      case 'T': case 't':
        morse_lang();
        delay(EndOfChar);
        break;
      case 'U': case 'u':
        morse_kurz();
        morse_kurz();
        morse_lang();
        delay(EndOfChar);
        break;
      case 'V': case 'v':
        morse_kurz();
        morse_kurz();
        morse_kurz();
        morse_lang();
        delay(EndOfChar);
        break;
      case 'W': case 'w':
        morse_kurz();
        morse_lang();
        morse_lang();
        delay(EndOfChar);
        break;
      case 'X': case 'x':
        morse_lang();
        morse_kurz();
        morse_kurz();
        morse_lang();
        delay(EndOfChar);
        break;
      case 'Y': case 'y':
        morse_lang();
        morse_kurz();
        morse_lang();
        morse_lang();
        delay(EndOfChar);
        break;
      case 'Z': case 'z':
        morse_lang();
        morse_lang();
        morse_kurz();
        morse_kurz();
        delay(EndOfChar);
        break;
      default:
        delay(EndOfChar);
        break;
    }
  }
}

#endif // MORSE_MOD_H
