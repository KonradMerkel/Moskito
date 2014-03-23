/*
** Moskito
***************************************************************
** (c) Konrad Merkel
** 13. Dezember 2013 (Vorgängerversion: 5. Juli 2013)
**************************************************************/

/* Bemerkung:
** Der Quellcode besitzt mehrere Module, die jeweils eine Aufgabe
** erledigen oder eine Hardwarekomponente steuern. Um die
** Übersichtlichkeit zu waren sind die Module in einzelnen Dateien. 
** Die Dateien müssen die Endung ".h" besitzen, da sonst die
** Arduino IDE einen Fehler meldet.
*/

/************************************************************
			Konfiguration
*************************************************************/
#define PI 3.1415926535
#define MOSKITO_SERIAL_DEBUGGING 0                      // für Debugging-Modus auf 1 setzen
#define WEBDUINO_SERIAL_DEBUGGING 0                     // für Debugging-Modus auf 1 setzen
                                                        // Im Debugging-Modus kann die Komunikation mit
                                                        // anderen Softwareschichten nicht möglich sein
#define ENABLE_MORSE 1                                  // ein- bzw ausschalten der Morsefunktionen
                                                        // ermöglicht dauerhaft gute Performance
#define BAUD 115200					                            // Baudrate für serielle Schnittstelle		
#define H_SERVO_PIN 7 					                        // Alpha-Servo
#define V_SERVO_PIN 6 				 	                        // Beta-Servo
#define BUTTON_A_PIN 35
#define BUTTON_B_PIN 37
#define JOYSTICK_ALPHA A1                               // Joystick horizontale Bedienung
#define JOYSTICK_BETA A0                                // Joystick für vertikal
#define JOYSTICK_BTN 33                                 // Button am Joystick
#define ULTRA_ECHO 29                                   // Ultraschallsensor (Echo)
#define ULTRA_TRIG 31                                   // Ultraschallsensor (Trig)
#define LASER_PIN 22
#define GREEN_LED 28
#define LCD_ZEILEN 4					                          // Anzahl an Zeilen auf dem Display (mindestens 4)
#define LCD_LAENGE 20					                          // Anzahl der Zeichen pro Zeile
#define MANUAL_DTIME 6					                        // Zeit für das Füllen des Buffers pro Char
							                                          // (Serielle Kom.) und Zeit für das Ausrichten der
							                                          // Servomotoren pro deg
#define CLEAR_TIME 8000 				                        // Zeit nachdem die Oberfläche neu geschrieben wird
#define TRICKER_TIME 800 				                        // Zeit zwischen dem Rücken des Trickers.
#define BTN_TIME 200					                          // Zeit zwischen den Button-Abfragen
#define JOY_TIME 200                                    // Zeit zwischen den langsamen Joystickkommandos
#define WEBDUINO_FAVICON_DATA ""			                  // Icon der Webseite
#define WEBDUINO_FAIL_MESSAGE "<h1>Keine gültige Adresse</h1>"
#define DHCP 0                                          // Ermöglicht DHCP
#define PASSWD_POS 80                                   // Speicherstelle des Passwortes (AdminWebSeite) im EEPROM
#define PASSWD_MAX_LENGTH 45                            // maximale Länge des Passwortes (AdminWebSeite)

/*zeitliche Abstände für die Morsebefehle*/
#define lang 600
#define kurz 250
#define EndOfChar 750
#define EndOfWord 1000

/*Ultaschallsensor*/
#define ULTRA_DIST 2.8                                  // Distance zwischen Sender und Empfänger (in cm)
#define TEMPERATUR 19.7
#define TO_MIDDLE 2.65                                  // Abstand zwischen Ultraschallsensor und Drehachse des Betaservos (in cm)
#define AVG_NUM 6
#define ULTRA_STAT_RANGE 25                            // zulässige Spannweite der Ultraschallmessungen in cm
/************************************************************
			Bibliotheken
*************************************************************/
#include <math.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include <SPI.h>
#include <EEPROM.h>
#include <Ethernet.h>
#include "WebServer.h"
#include "EEPROMAnything.h"

/************************************************************
		      Globale Variablen
*************************************************************/
Servo alphaServo;
Servo betaServo;
LiquidCrystal lcd(9,8,46,47,48,49);
bool ethernet = false;					                        // zeigt ob Ethernet aktiviert ist
WebServer webserver("", 80);  				                  // HTTP-Server

String const tricker_s 	= "Moskito 2014 ++ "; 		      // für den Tricker (Leerzeichen am Ende)
String tricker_ethernet = "Ethernet deaktiviert";	      // für den Tricker (nicht konstant)
String tricker_all;             			                  // Text des gesamten Trickers
unsigned long int tricker_t = 0;			                  // Betriebszeit, bei der des letzte Mal der Tricker
							                                          // weitergerückt ist (in Milisekunden)
unsigned long int clear_t = 0;				                  // Betriebszeit des letzten Refeshvorgangs des LCD
unsigned short int tricker_n = 0;			                  // Stelle an der der Tricker gerade steht

bool LASER = false;                                     // zeigt ob der Laser aktiviert ist
unsigned long int btn_t = 0;                            // Betriebszeit der letzten Button-Abfrage
unsigned long int joy_t = 0;                            // Betriebszeit der letzten Joystickbedienung

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};	    // MAC-Adresse des Gerätes
IPAddress ip(192, 168, 1, 35); 		  	                // für den Fall, dass DHCP nicht funktioniert oder deaktiviert ist

String buffer = "";                                     // Buffer für das Empfangen (Serielle Kom.)
String local_IP = "";                                   // lokale IP für die Anzeige auf der Monitorring-Webseite

/************************************************************
                Modulübergreifende Funktionen
*************************************************************/
extern void lcdRefresh();                               // Funktion aus dem LCD-Modul
void laser_switch(bool on)                              // aktiviert bzw. deaktiviert den Laser
{
  if (!on){
    digitalWrite(LASER_PIN, HIGH);                      // LASER ausschalten
    LASER = false;
    lcd.begin(LCD_LAENGE, LCD_ZEILEN);                  // LCD neu initialisieren (wegen Energieengpässen)
    lcdRefresh();
  }else{
    digitalWrite(LASER_PIN, LOW);                       // LASER anschalten
    LASER = true;
  }
}

void ethernet_switch(bool on)                           // aktiviert bzw. deaktiviert Ethernet
{
  if (on){
    ethernet = true;
    lcd.home();
    lcd.clear();
    lcd.print("Ethernet wird");
    lcd.setCursor(0, 1);
    lcd.print("eingerichtet...");
    lcd.setCursor(0, 3);
    lcd.print("bitte etwas Geduld");
#if DHCP
    if (Ethernet.begin(mac) == 0) {
      lcd.setCursor(0, 2);
      lcd.print("Kein DHCP");
      lcd.setCursor(0, 3);
      lcd.print("Versuche default IP");
      delay(1000);
      Ethernet.begin(mac, ip);
    }
#else
    delay(2000);
    Ethernet.begin(mac, ip);
#endif
    webserver.begin();
    
    ip = Ethernet.localIP();
    local_IP = "";
    local_IP += ip[0];
    local_IP += ".";
    local_IP += ip[1];
    local_IP += ".";
    local_IP += ip[2];
    local_IP += ".";
    local_IP += ip[3];
    tricker_ethernet = "IP: ";
    tricker_ethernet += ip[0];
    tricker_ethernet += ".";
    tricker_ethernet += ip[1];
    tricker_ethernet += ".";
    tricker_ethernet += ip[2];
    tricker_ethernet += ".";
    tricker_ethernet += ip[3];
    if (tricker_s != ""){
      tricker_ethernet += " ++ ";
    }
  }else{
    tricker_ethernet = "Ethernet deaktiviert";
    if (tricker_s != ""){
      tricker_ethernet += " ++ ";
    }
    ethernet = false;
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print("Ethernet wird");
    lcd.setCursor(0, 1);
    lcd.print("deaktiviert...");
    delay(1000);
  }
  tricker_all = tricker_s + tricker_ethernet;
  lcdRefresh();
}

/************************************************************
			  LCD - Modul
*************************************************************/
#include "lcd_mod.h"

/************************************************************
		        Ethernet - Modul
*************************************************************/
#include "ethernet_mod.h"

/************************************************************
		       Morse-Code - Funktionen
*************************************************************/
#if ENABLE_MORSE
#include "morse_mod.h"                                  // Während etwas gesendet wird, kann nicht anderes
#endif                                                  // gemacht werden

/************************************************************
		       Servo-USB - Modul
*************************************************************/
#include "servo_usb_mod.h"

/************************************************************
			 Button - Modul
*************************************************************/
void accurate()
{
        if ((alphaServo.read()-10) > 0){
            alphaServo.write(alphaServo.read()-10);
            delay(500);
            alphaServo.write(alphaServo.read()+10);
        } else{
            alphaServo.write(alphaServo.read()+10);
            delay(500);
            alphaServo.write(alphaServo.read()-10);
        }
        if ((betaServo.read()+10) < 180){
            betaServo.write(betaServo.read()+10);
            delay(500);
            betaServo.write(betaServo.read()-10);
        } else{
            betaServo.write(betaServo.read()-10);
            delay(500);
            betaServo.write(betaServo.read()+10);
        }
        delay(500);
}

void btn_runtime()
{
  if ((millis() - btn_t) >= BTN_TIME){
    if (digitalRead(BUTTON_A_PIN)){ laser_switch(!LASER);}
    if (digitalRead(BUTTON_B_PIN)){ ethernet_switch(!ethernet);}
    if (!digitalRead(JOYSTICK_BTN)){ /*accurate();*/ }
    btn_t = millis();
  }
  if (analogRead(JOYSTICK_ALPHA) > 900){
    alphaServo.write(alphaServo.read()+1);
  }else if (analogRead(JOYSTICK_ALPHA) < 30){
    alphaServo.write(alphaServo.read()-1);
  }else if ((analogRead(JOYSTICK_ALPHA) > 680) && ((millis() - joy_t) >= JOY_TIME)){
    alphaServo.write(alphaServo.read()+1);
    joy_t = millis();
  }else if ((analogRead(JOYSTICK_ALPHA) < 520) && ((millis() - joy_t) >= JOY_TIME)){
    alphaServo.write(alphaServo.read()-1);
  }
  if (analogRead(JOYSTICK_BETA) > 900){
    betaServo.write(betaServo.read()+1);
  }else if (analogRead(JOYSTICK_BETA) < 30){
    betaServo.write(betaServo.read()-1);
  }else if ((analogRead(JOYSTICK_BETA) > 680) && ((millis() - joy_t) >= JOY_TIME)){
    betaServo.write(betaServo.read()+1);
    joy_t = millis();
  }else if ((analogRead(JOYSTICK_BETA) < 520) && ((millis() - joy_t) >= JOY_TIME)){
    betaServo.write(betaServo.read()-1);
    joy_t = millis();
  }
}

/*##                                          ##*
 *##                                          ##*
 *##                KERNEL (MAIN)             ##*
 *##                                          ##*
 *##                                          ##*
 *##                                          ##*/
 

/************************************************************
		       Initialisierung
*************************************************************/
void setup()
{
  Serial.begin(BAUD);                                   // nur für Kommandobefehle nicht für Debugging
  #if MOSKITO_SERIAL_DEBUGGING
  Serial.println("Starte Moskito...");
  #endif
  lcd.begin(LCD_LAENGE, LCD_ZEILEN);                    // LCD initialisieren
  pinMode(BUTTON_A_PIN, INPUT);                         // Buttons initialisieren
  pinMode(BUTTON_B_PIN, INPUT);
  pinMode(ULTRA_ECHO, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(ULTRA_TRIG, OUTPUT);
  pinMode(LASER_PIN, OUTPUT);                           // Laser initialisieren
  digitalWrite(LASER_PIN, HIGH);                        // Laser ausschalten
  alphaServo.attach(H_SERVO_PIN);                       // Servomotoren initialisieren
  betaServo.attach(V_SERVO_PIN);
  
  webserver.setDefaultCommand(&aboutCmd);               // Seiten des Http-Servers initialisieren
  webserver.addCommand("admin.html", &adminCmd);
  webserver.addCommand("about.html", &aboutCmd);
  
  /* Startbildschirm */
  #if MOSKITO_SERIAL_DEBUGGING
  Serial.println("Zeige Startbildschirm an");
  #endif
  lcd.setCursor(4, 0);
  lcd.print("Moskito 2013");
  lcd.setCursor(0, 1);
  lcd.print("F&E: Konrad Merkel");
  lcd.setCursor(0, 3);
  lcd.print("starten...");
  delay(2000);
  
  if (tricker_s != ""){                                 // Trickerstrings bearbeiten und zusammenfügen
    tricker_ethernet += " ++ ";
  }
  tricker_all = tricker_s + tricker_ethernet;
  lcdRefresh();
  #if MOSKITO_SERIAL_DEBUGGING
  Serial.println("Initialisierung beendet");
  #endif
  digitalWrite(GREEN_LED, HIGH);
}


/************************************************************
		       Arbeitsumgebung: CPU_ALLOCATION
*************************************************************/
void loop()
{
  //for (int i=0; i<1; i++){ // Berechnungen in der Dokumentation für i<5, dies wurde aber zu Gunsten des Joysticks geändert
  servo_usb_runtime();
  if (ethernet)
    webserver.processConnection();
  servo_usb_runtime();
  //btn_runtime();
  lcd_runtime();
  servo_usb_runtime();
  lcd_runtime();
  if (ethernet)
    webserver.processConnection();
  //btn_runtime();
  servo_usb_runtime();
  lcd_runtime();
  servo_usb_runtime();
  lcd_runtime();
  if (ethernet)
    webserver.processConnection();
  //}
  btn_runtime();
  
  /* Bemerkung:
  ** Nach ungefähr 50 Tagen Betriebszeit fängt millis() wieder von vorn an zu zählen.
  ** Dies geschieht, da nach dieser Zeit die Größe des unsigned long int überschritten ist.
  ** Damit das System auch danach noch zuverlässig arbeitet, müssen die Zeitsteuerungsvariablen
  ** auch zurückgesetzt werden.
  ** Durch den Startbildschirm, der am Anfang 2 Sekunden eingeblendet wird, kann millis() in
  ** void loop() nur dann unter 2000 sein, wenn die 50 Tage überschritten sind.
  */
  if (millis() < 1900){
    tricker_t = 0;
    clear_t = 0;
    btn_t = 0;
  }
}
