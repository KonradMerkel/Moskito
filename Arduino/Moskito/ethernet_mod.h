/************************************************************
		                    Ethernet - Modul
*************************************************************/
#ifndef ETHERNET_MOD_H
#define ETHERNET_MOD_H

/************************************************************
		Webseite im Programmspreicher
*************************************************************/
P(start) = "<HTML><HEAD><TITLE>Moskito</TITLE><META NAME=\"AUTHOR\" CONTENT=\"Konrad Merkel\"></HEAD><BODY LANG=\"de-DE\" DIR=\"LTR\">";
P(start_admin) = "<HTML><HEAD><TITLE>Moskito</TITLE><META NAME=\"AUTHOR\" CONTENT=\"Konrad Merkel\"><meta http-equiv=\"refresh\" content=\"1\"></HEAD><BODY LANG=\"de-DE\" DIR=\"LTR\">";
P(end) = "</BODY></HTML>";
P(about) = "<H1 STYLE=\"background: transparent\"><FONT FACE=\"DejaVu Sans, sans-serif\">About Moskito</FONT></H1><H2 CLASS=\"western\"><FONT COLOR=\"#c5000b\"><FONT FACE=\"Cantarell\">14.03</FONT></FONT></H2><P STYLE=\"margin-bottom: 0cm\"><FONT COLOR=\"#4c4c4c\"><B>Moskito mit HTTP</B></FONT>"
"<BR><P>Moskito bezeichnet ein Multifunktionsgerät bestehend aus zwei Servomotoren, einem Laser und weiteren Sensoren und Aktoren. Gesteuert wird die Hardware durch einen Mikrocontroller. Das Gerät kann somit zum Beispiel als Vermessungs- und Markierungssystem für Hand- und Heimwerker werden.</P>"
"<P>Das besondere an diesem Projekt ist, dass von der Idee über die Umsetzung bis hin zum fertigen Produkt die gesamte Entwicklung in einer Hand liegt. Das betrifft<BR>• die Mathematik,<BR>• die Fertigung der Holzkomponenten,<BR>• die Schaltkreise,<BR>• die Programmierung auf mehreren Plattformen in mehreren Schichten (layered system structure) und<BR>• ausführlichen Tests.</P>"
"<P>Für viele Anwendungsgebiete des Moskito, wie zum Beispiel als Ziel- und Vermessungssystem, benötigt man eine Reihe von Gleichungen und Formel, die die Koordinaten in Drehwinkel der Servos umrechnen können. Genutzt wird dazu ein abstraktes mathematisches Modell auf Basis der Analysis. Die entsprechenden Formeln sind in der <A HREF=\"https://github.com/KonradMerkel/Moskito\">schriftlichen Arbeit</A> genau erläutert.<\P>"
"<P>Die Hard- und Software ist in drei wesentliche Teil, Ebenen unterteilt. Als erste Ebene bildet den Kern das universale Betriebssystem des Mikrocontrollers der für die Steuerung der Hardwarekomponenten verantwortlich ist. Dieses System ist modular aufgebaut. Dabei hat jedes Modul eine bestimmte Aufgabe, die es erfüllen muss. Je nach Wichtigkeit dieser Aufgabe wird dem Modul entsprechend mehr oder weniger CPU-Zeit gegeben.</P>"
"<P>Die zweite Ebene ist die Anwenderschicht auf einem Computer, der mit dem Gerät über ein USB-Kabel verbunden ist. Dieser Teil bietet eine hohe Flexibilität und Benutzerfreundlichkeit, da es zum einen grafische Benutzeroberflächen gibt und zum anderen für jeden Einsatz das entsprechende und spezialisierte Programm. Durch eine entsprechende Entwicklerschnittstelle am Computer können auch fremde Entwickler ohne viel Aufwand das Projekt erweitern. Das heißt das eine Spezialisierung durch adaptive Anwenderprogramme schnell und effizient erfolgen kann. Aus diesem Grund bezeichnet man den Moskito als Multifunktionsgerät.</P>"
"<P>Die dritte Ebene ist die Monitorring-Schicht. Ist der Mikrocontroller an ein Netzwerk angeschlossen, so ist er in der Lage sich per DHCP mit dem Netzwerk zu verbinden und stellt dann eine Webseite zur Verfügung. Auf dieser Webseite gibt es einen geschützten Bereich, auf dem die Positionen der Servomotoren und der Laserstatus angezeigt wer</P>"
"<BR><P><A HREF=\"admin.html\">Hier</A> geht es weiter zur Monitorring-Seite..<BR><A HREF=\"https://github.com/KonradMerkel/Moskito\">Hier</A> kann man den Quelltext und die schriftliche Arbeit sehen...</P>";

P(admin) = "<H1 STYLE=\"background: transparent\"><FONT FACE=\"DejaVu Sans, sans-serif\">Monitorring  des Moskitos</FONT></H1><H2 CLASS=\"western\"><FONT FACE=\"Cantarell\">Hier ist es Ihnen möglich die aktuellen Parameter und des Moskitos zu sehen...</FONT></H2>";
P(alpha) = "<FORM ACTION=\"review_tabelle.htm\"><TABLE CELLPADDING=0 CELLSPACING=4><TR><TD><P ALIGN=LEFT>Alpha-Servo:</P></TD><TD><P><INPUT TYPE=TEXT NAME=\"alpha\" MAXLENGTH=3 value=\"";
P(beta) = "\"></P></TD></TR><TR><TD><P ALIGN=LEFT>Beta-Servo:</P></TD><TD><P><INPUT TYPE=TEXT NAME=\"beta\" MAXLENGTH=3 value=\"";
P(ip_html) = "\"></P></TD></TR><TR><TD><P ALIGN=LEFT>IP:</P></TD><TD><P><INPUT TYPE=TEXT NAME=\"ip\" MAXLENGTH=16 value=\"";
P(laser) = "\"></P></TD></TR><TR><TD><P ALIGN=LEFT>Laser:</P></TD><TD><P>";
P(endOfAdmin) = "</P></TD></TR></TABLE></FORM><P STYLE=\"margin-bottom: 0cm\"><A HREF=\"about.html\">About Moskito</A></P>";


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
      server.printP(start_admin);
      server.printP(admin);
    
      server.printP(alpha);
      server.print(alphaServo.read());
      server.printP(beta);
      server.print(betaServo.read());
      server.printP(ip_html);
      ip = Ethernet.localIP();
      String local_IP = "";
      local_IP += ip[0];
      local_IP += ".";
      local_IP += ip[1];
      local_IP += ".";
      local_IP += ip[2];
      local_IP += ".";
      local_IP += ip[3];
      server.print(local_IP);
      server.printP(laser);
      if (LASER)
        server.print("<FONT COLOR=red><b>AN</b></FONT>");
      else
        server.print("AUS");
      server.printP(endOfAdmin);
      server.printP(end);
    }
  }
  else{
    server.httpUnauthorized();
#if MOSKITO_SERIAL_DEBUGGING
    Serial.println("Unautorisierter Zugriff auf adminCmd");
#endif
  }
}

#endif //ETHERNET_MOD_H
