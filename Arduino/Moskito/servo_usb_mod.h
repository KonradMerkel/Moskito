/************************************************************
		       Servo-USB - Modul
*************************************************************/
#ifndef SERVO_USB_MOD_H
#define SERVO_USB_MOD_H

#include <Arduino.h>

void aim(int alpha, int beta, bool laser, bool drive_on = false)  // Zielwinkel von USB anfahren
{
  if (!laser)
    drive_on = false;
  
  if (!drive_on){
    laser_switch(false);                                // Während der Drehung wird der Laser aus
  }
  int pos = alphaServo.read();
  if (((pos + 1) == alpha) || ((pos - 1) == alpha)){
    if (alpha + 10 > 180)
      aim(alpha - 10, beta, laser,drive_on);
    else
      aim(alpha + 10, beta, laser,drive_on);
    pos = alphaServo.read();
  }
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
  if (((pos + 1) == beta) || ((pos - 1) == beta)){
    if (beta + 10 > 180)
      aim(alpha, beta  - 10, laser,drive_on);
    else
      aim(alpha, beta + 10, laser,drive_on);
    pos = betaServo.read();
  }
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
            alphaServo.write(alphaServo.read()-10);
        }
        delay(500);
}

long double distance_single(double temp) // Ultraschall-Abstandssensor | Rückgabewert in cm
{
  delayMicroseconds(500);
  long double duration;
  digitalWrite(ULTRA_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRA_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRA_TRIG, LOW);
  duration = pulseIn(ULTRA_ECHO, HIGH);
  
  long double c = sqrt((28987/72)  * (temp + 273.15)) * 100; // in cm/s
  
  long double s =  c * duration * 0.000001;
  long double fi = (180* acos( ULTRA_DIST/(s)  ) / PI);
  return (s/2) * sin(PI*fi/180);
}

double distance_avg(double temp)
{
  long double dist = 0;
  long double dist_ = 0;
  long double dist__ = 0;
  long double dist_max = 0;
  long double dist_min = 999999999999999;
  double i, k, j;
  for(j=1; j<=AVG_NUM; j++)
  {
    for(k = 1; k<=AVG_NUM; k++)
    {
      for(i = 1; i<=AVG_NUM; i++)
      {
        dist += distance_single(temp);
        if ((dist/ i) < dist_min)
          dist_min = dist / i;
        else if ((dist/ i) > dist_max)
          dist_max = dist/ i;
      }
      i--;
      dist_ += dist / i;
      dist = 0;
    }
    k--;
    dist__ += dist_ / k;
    dist_ = 0;
  }
  j--;
#if MOSKITO_SERIAL_DEBUGGING
    Serial.print("Statistische Spannweite: ");
    Serial.println(double(dist_max - dist_min));
    Serial.print("Mittelwert des gemessenen Abstandes: ");
    Serial.println(double(dist__ / j));
#endif
  if ((dist_max - dist_min) <= ULTRA_STAT_RANGE){
    return double(dist__ / j);
  }else{
#if MOSKITO_SERIAL_DEBUGGING
    Serial.println("Ultraschallmessung war ungültig. Spannweite der Messungen zu hoch!");
#endif
    return 0;
  }
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
  char passwd[PASSWD_MAX_LENGTH];
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
          aim(param_.toInt(), param__.toInt(), true, false);
        else if (buffer[i] == '*')
          aim(param_.toInt(), param__.toInt(), LASER, false);
          else if (buffer[i] == '+')
          aim(param_.toInt(), param__.toInt(), true, true);
        else
          aim(param_.toInt(), param__.toInt(), false, false);
        i++;
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
   
      case 'p':                                         // setzt das Passwort für die Webseite
        for(i=1;i<PASSWD_MAX_LENGTH;i++){
          if (buffer[i] != '#'){
            passwd[i-1] = buffer[i];
          }else{
            passwd[i-1] = '*';
            break;
          }
        }
        if (i==PASSWD_MAX_LENGTH)
          break;
        if (i>2)
          EEPROM_writeAnything(PASSWD_POS, passwd);
        i++;
        break;
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
        Serial.print(ethernet);
#if MOSKITO_SERIAL_DEBUGGING
        Serial.println("");
#endif
        break;
#if MOSKITO_SERIAL_DEBUGGING
      case 's':
        Serial.println(isPasswd());
        break;
#endif
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
      case 'x':
        param_ = "0";
        for (int k=0; k<(AVG_NUM); k++) {
          double dist = distance_avg(TEMPERATUR);       // Ultraschall-Abstandssensor abfragen
          if (dist>0){
            dist = (dist + TO_MIDDLE) * 1000.00;
            unsigned long int conv = dist;
            Serial.print(conv);
#if MOSKITO_SERIAL_DEBUGGING
            Serial.println("");
#endif
            param_ = "1";
            break;
          }
        }
        if (param_ == "0")
          Serial.print("0");
#if MOSKITO_SERIAL_DEBUGGING
        Serial.println("");
#endif
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
