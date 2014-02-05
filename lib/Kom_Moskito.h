#ifndef KOM_MOSKITO_H
#define KOM_MOSKITO_H
/*
 * Um diese Bibliothek nutzen zu können müssen folgende
 * Zeilen in die *.pro (Projektdatei) hinzugefügt werden:
 *
 * include(../../lib/qextserialport-1.2rc/src/qextserialport.pri)
 * QT += testlib
 *
 */


/************************************************************
                       Konfiguration
*************************************************************/
#define PI 3.1415926535
#ifndef RADIUS
#define RADIUS 6   /* UNGENAU */                                 // Radius zwischen Laser und Drehachse
#endif
#ifndef HIGH
#define HIGH 13.27 /* UNGENAU */                                 // Höhe der Drehachse
#endif
#ifndef BAUD_RATE
#define BAUD_RATE BAUD115200                        // Baudrate der seriellen Verbindung
#endif
#ifndef SERIAL_INIT_TIME
#define SERIAL_INIT_TIME 1500                       // Zeit um eine Verbindung zum Moskito herzustellen
#endif
#ifndef TIME_OUT
#define TIME_OUT 50                                 // Timeout für das initialisieren des Gerätes nachdem SERIAL_INIT_TIME verstrichen ist
#endif
#ifndef DELTA_ALPHA
#define DELTA_ALPHA 0   /* UNGENAU */                            // Korrekturfaktor des Alphaservos, aufgrund der Einspannung
#endif
#ifndef ENABLE_MORSE
#define ENABLE_MORSE 1                              // ein- bzw ausschalten der Morsefunktionen
#endif
#ifndef DEBUGING
#define DEBUGING 0                                 // ermöglicht zusätzliche Ausgabe zum debuggen
#endif
/************************************************************
                        Bibliotheken
*************************************************************/
#include <QObject>
#include <QStringList>
#include <QtTest/QtTest>
#include <math.h>
#include "qextserialport.h"
#include <QtGui/QMessageBox>
#include <iostream>

using namespace std;

/************************************************************
                  Strukturen und globale Funktionen
*************************************************************/
struct Koord                                        // Struktur zum besseren Arbeiten mit Koordinaten in 3D
{
    double x;
    double y;
    double z;
};

/************************************************************
                          class KomMoskito
*************************************************************/
class Kom_Moskito : public QObject
{
    Q_OBJECT

public:
    explicit Kom_Moskito(QObject *parent = 0):
        QObject(parent)
    {
        port = new QextSerialPort(QLatin1String("/dev/ttyACM0"), QextSerialPort::Polling);
    }
    ~Kom_Moskito()
    {
        port->close();
        delete port;
    }

    // Initialisiert eine Verbindung zum Gerät
    bool init(QString path="Testmodus")
    {
        if (path != "Testmodus")
        {
            port->setBaudRate(BAUD_RATE);
            port->setPortName(path);
            port->open(QIODevice::ReadWrite | QIODevice::Unbuffered);
            port->setFlowControl(FLOW_OFF);
            port->setParity(PAR_NONE);
            port->setDataBits(DATA_8);
            port->setStopBits(STOP_2);

            port->setTimeout(TIME_OUT);

            if(!port->isOpen()) {
                QMessageBox::critical(0, "port error", "Impossible to open the port!");
                cerr << "Impossible to open the port!\n";
                return false;
            }
            QTest::qWait(SERIAL_INIT_TIME);// Zeit um die Verbindung zu initialisieren
        }
        return true;
    }

    bool getLaser()
    {
        pos(trash_int , trash_int_, trash_bool, trash_bool_);
        return trash_bool;
    }
    bool getEthernet()
    {
        pos(trash_int , trash_int_, trash_bool, trash_bool_);
        return trash_bool_;
    }

    // liest die aktuelle Position des Moskito aus. (Druch senden des Steuersignals 'i')
    // Die Rückgabe ist im Sendeformat alpha#beta#laser#ethernet
    QString pos()
    {
        if (send("i") == false){ // akutelle Position abfragen
            port->readAll(); // möglichen Buffer leeren
            return "xx#xx#0#0"; // Fehler beim senden
        }

        char buffer[13];
        int numBytes;
        int i=0;

        do{
        numBytes = port->bytesAvailable();
        QTest::qWait(4);
        i++;
        if (i>10)
            return "xx#xx#0#0"; // Fehler
        }while(numBytes <= 7);

        if(numBytes > 12)
            numBytes = 12;

        i = port->read(buffer, numBytes);
        port->readAll();
        if (i != -1){
            return QString(buffer);
        }else
            return "xx#xx#0#0";     // Fehler
    }

    // führt die read()-Fkt aus und splittet den String als Alpha und Beta
    // Der Rückgabewert gibt an, ob die Übertragung funktioniert hat
    bool pos(int &alpha, int &beta)
    {
        return pos(alpha, beta, trash_bool, trash_bool_);
    }
    bool pos(int &alpha, int &beta, bool &laser, bool &ethernet)
    {
        QString r = pos();
        if (r == "xx#xx#0#0"){
#if DEBUGING
            cout << "Fehler bei der Positionsabfrage (in bool pos(int &alpha, int &beta, bool &laser, bool &ethernet))\n";
#endif
            return false;
        }
        QStringList s = r.split('#');
        if (s.size() == 4) {
            alpha = s[0].toInt();
            beta = s[1].toInt();
            if (s[2].toInt()>=1)
                laser = true;
            else
                laser = false;
            if (s[3].split('\n')[0].toInt() >= 1)
                ethernet = true;
            else
                ethernet = false;
            return true;
        }
        return false;
    }

signals:
    // sendet einen String zum Gerät
    // Ein ähnliches Signal gib es in jeder Klasse, die mit dem Gerät spricht.
    void sendedToMoskito(QString);

public slots:
    // sendet den angegebenen String an das Gerät
    // ist mit dem sendToMoskito-Signal verknüpft und wird in der Regel darüber aufgerufen, da dadurch die Aufnahmefunktion
    // benachrichtigt wird
    bool send(QString s)
    {
      if (-1 == port->write(s.toLocal8Bit())) {
          return false;
      }else{
          if (s != "i"){
              emit sendedToMoskito(s);        // nur Steuerbefehle werden als SIGNAL an andere Instanzen gesendet
#if DEBUGING
              cout << "Steuerbefehl " << s.toStdString() << " wurde erfolgreich gesendet\n";
#endif
          }
          return true;
      }
    }

    // fährt die Servos in den Standby-Modus
    // Das heißt: Alpha=90deg ;  Beta=90deg
    bool standby()
    {
        return send("a90#90#0#");
    }

    // rechnet die Koordinaten in Dehwinkel um
    // Die Drehwinkel werden auf der Benutzeroberfläche in die entsprechenden Objekte geschrieben
    // Dies ermöglicht ein nachverfolgen der bzw. auslesen der Drehwinkel
    // aim_Koord() ruft danach aim_deg() auf
    bool aim_Koord(Koord target, int laser=2)
    {
        double alpha, beta;
        double x = target.x;
        double y = target.y;
        double z = target.z;
        double h = HIGH;
        double r = RADIUS;

        if(sqrt(x*x+y*y)<= r){
            QMessageBox::warning(0,"Befehl ist nicht ausführbar","Die Koordinaten sind nicht weit genug vom Koordinatenursprung entfernt. Innerhalb des Drehradius können keine Koordinaten angezeigt werden.");
            cerr << "Die Koordinaten sind nicht weit genug vom Koordinatenursprung entfernt. Innerhalb des Drehradius können keine Koordinaten angezeigt werden." << endl;
            return false;
        }

        alpha = 2* ((180 * atan((y+ sqrt(x*x+y*y-r * r))/(x+r))) / PI); // es gibt eine 2. Lösung!

        if ((alpha > 180) || (alpha < 0)) {
            QMessageBox::warning(0,"Befehl ist nicht ausführbar","Die Position Alpha kann nicht angefahren werden, da die Schrittmotoren nur von 0 bis 180 deg anfahren können. Alpha = " + QString::number(alpha));
            cerr << "Die Position Alpha kann nicht angefahren werden, da die Schrittmotoren nur von 0 bis 180 deg anfahren können. Alpha = " << alpha << endl;
            return false;
        }

        if (z < h)
            beta = 180 - (180* atan( sqrt(x*x + y*y) / (h-z)  ) / PI);
        else if (z > h)
            beta = 90 - (180* atan( (z-h) / sqrt(x*x + y*y)   ) / PI);
        else
            beta = 90;
        if ((beta > 180) || (beta < 0)){
            QMessageBox::warning(0,"Befehl ist nicht ausführbar","Die Position Beta kann nicht angefahren werden, da die Schrittmotoren nur von 0 bis 180 deg anfahren können. Beta = " + QString::number(beta));
            cerr << "Die Position Beta kann nicht angefahren werden, da die Schrittmotoren nur von 0 bis 180 deg anfahren können. Beta = " << beta << endl;
            return false;
        }



        //prüfung:
        double should = ( (cos(PI*alpha/180) * x + y* sin(PI*alpha/180)) );
        if((r >= should - 0.05) && (r <= should + 0.05)){
        }else{
            QMessageBox::warning(0,"Berechnung der Winkel","Der Winkel Alpha ist bei der Prüfung durchgefallen. Möchten Sie trotzdem fortfahren?");
            cerr << "Der Winkel Alpha ist bei der Prüfung durchgefallen.\n" ;
            return false;
        }
#if DEBUGING
        cout << "Errechnetes Alpha+DELTA_ALPHA: " << (alpha + DELTA_ALPHA) << " Beta: " << beta << endl;
#endif

        return aim_deg(alpha + DELTA_ALPHA, beta, laser);
    }

    // löst ein Signal aus, welches die Drehwinkel im entsprechenden Format an den Moskito sendet
    // Das Auslösen des Signals ermöglicht weitere Verarbeitung
    bool aim_deg(double alpha, double beta, int laser=2){ return aim_deg(rund(alpha), rund(beta), laser); }
    bool aim_deg(int alpha, int beta, int laser=2)
    {
        if (laser == 1)
            return send(QString("a" + QString::number(alpha) + "#" + QString::number(beta) + "#1#"));       // Laser wird aktiviert
        else if (laser == 2)
            return send(QString("a" + QString::number(alpha) + "#" + QString::number(beta) + "#*#"));       // Laser bleibt unverändert
        else
            return send(QString("a" + QString::number(alpha) + "#" + QString::number(beta) + "#0#"));       // Laser wird deaktiviert
    }

    // Schaltet den Laser / Ethernet an und aus
    bool setLaser (bool on){
        if (on)
            return send("f"); // Laser anschalten
        else
            return send("d"); // Laser ausschalten
    }
    bool setEthernet (bool on){
        if (on)
            return send("e"); // Ethernet anschalten
        else
            return send("o"); // Ethernet ausschalten
    }

    bool man_up() {return send("8");}
    bool man_down() {return send("2");}
    bool man_right() {return send("6");}
    bool man_left() {return send("4");}

#if ENABLE_MORSE
    // veranlasst den Moskito zum Senden einens Strings per Morsecode
    bool morse(QString s)
    {
        if (s.length()< 100)
            return send("m" + s + "#");
        else
            return false;      // String zu lang -> d.h. Moskito fällt zulange aus
    }

#endif

private:
    // Mülleimer (wenn Referenzen nötig sind, aber die Werte verorfen werden können
    int trash_int;
    bool trash_bool;
    int trash_int_;
    bool trash_bool_;

protected:
    QextSerialPort *port;                           // Kommunikation über einen serialen Port (Kommunikation mit Moskito)
    
    // rundet einen double nach den Rundungsreglen
    // ist Notwendig, da die Drehwinkel nur auf 1deg genau eingestellt und übertragen werden
    int rund(double a)
    {
        if (a < 0)
            return (int)a;  // Fehler! Dafür ist die Funktion nicht ausgelegt bzw ist es nicht nötig
        int a_int = a;
        if (a >= (a_int + 0.5))
            return a_int + 1;
        else
            return a_int;
    }
};

#endif //KOM_MOSKITO_H
