/************************************************************
		                    Ethernet - Modul
*************************************************************/
#ifndef ETHERNET_MOD_H
#define ETHERNET_MOD_H

/* Bemerkung:
** An Stelle einer runtime()-Funktion besitzt die Bibliothek
** eine Funktion namens webserver.processConnection(). Diese
** Funktion hat die selben Aufgaben wie eine runtime()-Funktion
*/
void aboutCmd(WebServer &server, WebServer::ConnectionType type, char *, bool)  // about-Seite
{
  if (type == WebServer::POST){
    server.httpFail();
    #if MOSKITO_SERIAL_DEBUGGING
    Serial.println("POST-Status an aboutCmd gesendet");
    #endif
    return;
  }
  server.httpSuccess();
  #if MOSKITO_SERIAL_DEBUGGING
  Serial.println("Erfolgreicher Http-Zugriff");
  #endif

  if (type != WebServer::HEAD){
    server.printP(start);
    server.printP(about);
    server.printP(end);
  }
}

/*String isPasswd()
{
  String passwd;
  EEPROM_readAnything(PASSWD_POS, passwd);
  return passwd;
}*/

void adminCmd(WebServer &server, WebServer::ConnectionType type, char *, bool)  // Admin-Seite
{
  if (server.checkCredentials("YWRtaW46YWRtaW4=")){
    server.httpSuccess();
    #if MOSKITO_SERIAL_DEBUGGING
    Serial.println("Anmeldung in AdminCmd erfolgreich");
    #endif
    if (type != WebServer::HEAD){
      server.printP(start);
      server.printP(admin);
    
      server.printP(alpha);
      server.print(alphaServo.read());
      server.printP(beta);
      server.print(betaServo.read());
      server.printP(laser);
      server.print(LASER ? "CHECKED" : "");
      server.printP(endOfAdmin);
      server.printP(end);
    }
  }
  else{
    server.httpUnauthorized();
#if MOSKITO_SERIAL_DEBUGGING
    Serial.println("Unautorisierter zugriff auf adminCmd");
#endif
  }
}

#endif //ETHERNET_MOD_H
