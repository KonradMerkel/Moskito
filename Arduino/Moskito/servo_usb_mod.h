/************************************************************
		       Servo-USB - Modul
*************************************************************/
#ifndef SERVO_USB_MOD_H
#define SERVO_USB_MOD_H

#include <Arduino.h>

void aim(int alpha, int beta, bool laser)               // Zielwinkel von USB anfahren
{
  laser_switch(false);                                  // Während der Drehung wird der Laser aus
  int pos = alphaServo.read();
  if (pos > alpha){                                     // Langsames (exaktes) Anfahren der Winkel
    for(; pos >= alpha; pos--){
      alphaServo.write(pos);
      delay(MANUAL_DTIME);
    }
  }else{
    for(; pos <= alpha; pos++){
      alphaServo.write(pos);
      delay(MANUAL_DTIME);
    }
  }
  
  pos = betaServo.read();
  if (pos > beta){
    for(; pos >= beta; pos--){
      betaServo.write(pos);
      delay(MANUAL_DTIME);
    }
  }else{
    for(; pos <= beta; pos++){
      betaServo.write(pos);
      delay(MANUAL_DTIME);
    }
  }
  delay(20 * MANUAL_DTIME);
  laser_switch(laser);                                // Urzustand des Lasers wiederherstellen
}

void up()
{
        if ((betaServo.read()-10) > 0){
            betaServo.write(betaServo.read()-10);
            delay(500);
            betaServo.write(betaServo.read()+9);
        } else{
            betaServo.write(betaServo.read()+9);
            delay(500);
            betaServo.write(betaServo.read()-10);
        }
        delay(500);
}

/* Bemerkung zum genauen Anfahren der Winkel:
** Bei geringen Unterschieden des Ist- und des Soll-Winkels sind
** die Servomotoren sehr ungenau. Um dies zu umgehen wird der
** Servo um 10deg in eine Richtung ausgelengt und um 9deg wieder
** zurückgefahren. Dieses Vorgehen erhöht die Genauigkeit enorm.
*/

void down()
{
         if ((betaServo.read()+10) < 180){
            betaServo.write(betaServo.read()+10);
            delay(500);
            betaServo.write(betaServo.read()-9);
        } else{
            betaServo.write(betaServo.read()-9);
            delay(500);
            betaServo.write(betaServo.read()+10);
        }
        delay(500);
}

void left()
{
        if ((alphaServo.read()+10) < 180){
            alphaServo.write(alphaServo.read()+10);
            delay(500);
            alphaServo.write(alphaServo.read()-9);
        } else{
            alphaServo.write(alphaServo.read()-9);
            delay(500);
            alphaServo.write(alphaServo.read()+10);
        }
        delay(500);
}

void right()
{
        if ((alphaServo.read()-10) > 0){
            alphaServo.write(alphaServo.read()-10);
            delay(500);
            alphaServo.write(alphaServo.read()+9);
        } else{
            alphaServo.write(alphaServo.read()+9);
            delay(500);
            alphaServo.write(alphaServo.read()-20);
        }
        delay(500);
}

void servo_usb_runtime()
{
  /* Daten empfangen */
  while (Serial.available() > 0) {
    delay(5);
    char inChar = Serial.read();
    buffer += inChar;
  }
  
  /* Steuerbefehle auswerten */
  if (buffer.length() > 0) {
  String param_ = "";
  String param__ = "";
  int i = 1;
#if MOSKITO_SERIAL_DEBUGGING
  Serial.print("Daten empfangen: ");
  Serial.println(buffer);
#endif
    switch(buffer[0]) {
      case 'a':                                         // bestimmte Winkel anfahren (aim)
        for(;i<4;i++){
          if (buffer[i] != '#')
            param_ += buffer[i];
          else
            break;
        }
        i++;
        for(;i<8;i++){
          if (buffer[i] != '#')
            param__ += buffer[i];
          else
            break;
        }
        i++;
        if (buffer[i] == '1')
          aim(param_.toInt(), param__.toInt(), true);
        else if (buffer[i] == '*')
          aim(param_.toInt(), param__.toInt(), LASER);
        else
          aim(param_.toInt(), param__.toInt(), false);
        i = i +2;
        break;
#if ENABLE_MORSE
      case 'm':                                         // bestimmte Nachricht per Morsecode senden
        for(i=1;i<101;i++){
          if (buffer[i] != '#')
            param_ += buffer[i];
          else
            break;
        }
        morse(param_);
        i++;
        break;
#endif
  /* the credentials have to be concatenated with a colon like
   * username:password
   * and encoded using Base64 - this should be done outside of your Arduino
   * to be easy on your resources
   
   * if the user has requested this page using the following credentials
   * username = admin
   * password = admin
   * in other words: "YWRtaW46YWRtaW4=" is the Base64 representation of "admin:admin" */
   
      /*case 'p':                                         // setzt das Passwort für die Webseite
        for(i=1;i<45;i++){
          if (buffer[i] != '#')
            param_ += buffer[i];
          else
            break;
        }
        Serial.println(param_);
        EEPROM_writeAnything(PASSWD_POS, param_.length());
        EEPROM_writeAnything(PASSWD_POS + 5, param_.c_str());
        i++;
        break;*/
      case '8':                                         // eine Position nach oben fahren (1deg)
        up();
        break;
      case '2':                                         // eine Position nach unten fahren (1deg)
        down();
        break;
      case '4':                                         // eine Position nach links fahren (1deg)
        left();
        break;
      case '6':                                         // eine Position nach rechts fahren (1deg)
        right();
        break;
      case 'i':                                         // gibt die aktuell Position, den Laser- und Ethernetstatus aus
        Serial.print(alphaServo.read());
        Serial.print("#");
        Serial.print(betaServo.read());
        Serial.print("#");
        Serial.print(LASER);
        Serial.print("#");
        Serial.println(ethernet);
        break;
      /*case 's':  
        param_ = "";                                    // Passwort abfrage (Verschlüsselt mit Base64)
        unsigned int length;
        char passwd;
        EEPROM_readAnything(PASSWD_POS, length);
        Serial.println(length);
        for (int k = 0; k<length; k++){
          EEPROM_readAnything(PASSWD_POS + k +5, passwd);
          param_ += passwd;
          Serial.print(passwd);
        }
        Serial.println("");
        Serial.println(param_);
        break;*/
      case 'f':                                         // Laser anschalten
        laser_switch(true);
        break;
      case 'd':
        laser_switch(false);                            // Laser ausschalten
        break;
      case 'e':                                         // Ethernet anschalten
        ethernet_switch(true);
        break;
      case 'o':
        ethernet_switch(false);                         // Ethernet ausschalten
        break;
      default:
        buffer =0;
        break;
    }
    if (buffer.length() > i){                           // restliche Steuerbefehle merken
      if (buffer[i+1]  != '\n'){
        String buffer_ = buffer;
        buffer = "";
        for(;i<buffer_.length();i++){
          buffer += buffer_[i];
        }
      }else{
        buffer = "";
      }
    }else{
      buffer = "";
    }
  }
}
#endif // SERVO_USB_MOD_H
