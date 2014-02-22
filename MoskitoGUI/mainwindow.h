#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/************************************************************
                       Konfiguration
*************************************************************/
#define DEFAULT_V 0                                 // Voreingestellte Geschwindigkeit eines möglichen Geschosses
#define GUI_ENABLE 1                                // Ermöglicht eine GUI-Unterstützung von Kom_Moskito
#define ENABLE_MORSE 0                              // ausschalten der Morsefunktionen
#define CURRENT_POS_TIME 500                       // Zeitintervall des Timers
#define DEBUGING 1                                 // ermöglicht zusätzliche Ausgabe zum debuggen (noch inaktiv)

/************************************************************
                        Bibliotheken
*************************************************************/
#include <QMainWindow>
#include <QMessageBox>
#include <QByteArray>
#include <QString>
#include <QTimer>
#include <QList>
#include <QInputDialog>
#include <QSettings>
#include <QFile>
#include <QTimer>
#if DEBUGING
#include <iostream>
using namespace std;
#endif

#include "../../lib/Kom_Moskito.h"
#include "qextserialport.h"
#include "dialog_rec.h"
#include "manual.h"
#include "konf.h"


/************************************************************
                          Strukturen
*************************************************************/
namespace Ui {
class MainWindow;
}

struct spezialKoord                                 // Struktur zum besseren Arbeiten (Speichern) mit Koordinaten und Drehwinkeln
{
    QString name;
    QChar isAct;                                    // Gibt an, ob die Drehwinkel oder die Koordinaten aktiv sein sollen
                                                    // Beide müssen nicht zwangsläufig auf das selbe Ziel zeigen
                                                    //(z.B.: wenn die Koordinaten des Ziels unbekannt aber die Drehwinkel bekannt sind.)

    Koord KO;                                       // Die Koordinaten des Ziels
                                                    // Diese Koordinaten müssen nicht mit den Drehwinkeln übereinstimmen


    unsigned int alpha;                             // Drehwinkel Alpha und Beta für das Ziel
    unsigned int beta;
};

/************************************************************
                         MainWindow
*************************************************************/
class MainWindow : public QMainWindow
{
  Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    // wird aktiv, wenn Button Zielen gedrückt wird
    // jenachdem ob die Zielkoordinaten bzw. die Winkel für das zielen markiert sind wird die
    // entsprechende aim_* -Funktion aufgerufen
    void aim(int laser=0);

    // wird vom Timer aufgerufen und gibt die aktulle Position als Signal currentPos(int, int)
    void currentPos();

    // zielt und schlatet den Laser an oder aus...
    void fire();

    // laser an oder ausschalten
    void laser();

    // speichert die Koordinaten in QList<spezialKoord> *sKO
    // ermöglicht das schnelle Zugreifen auf bestimmte Koordinaten
    void saveKO();

    // öffnet Koordinaten, die in QList<spezialKoord> *sKO gespeichert sind
    // öffnen bedeutet hierbei, dass das GUI mit den jeweiligen Werten gefüllt wird
    void openKO(int item);

    // löscht einzelne Koordinaten, die in QList<spezialKoord> *sKO gespeichert sind
    void rmKO();

    // ändert die Koordinaten, die in QList<spezialKoord> *sKO gespeichert sind
    // dabei werden die Koordinaten / Drehwinkel durch die Werte des GUI ersetzt und ein Inputfenster lässt den Namen ändern
    void editKO();

    // löscht QList<spezialKoord> komplett
    void sKO_clear();

    // öffnet / speichert QList<spezialKoord> *sKO in einer Datei
    // filename wird mit sKO_file abgeglichen
    bool readKOFile(QString filename);
    bool saveKOFile(QString filename);

    // öffnet einen Dialog zum Auswählen einer Datei
    // der Pfad der Datei wir in sKO_file gespeichert
    bool readKOFile_dialog();
    bool saveKOFile_dialog();

    // öffnet ein about-Fenster
    void about();
    void aboutQt();

    // öffnet / speichert wichtige Einstellungen, sodass sie beim nächsten Start wieder da sind
    // Die Speicherung ist vom Betriebssystem abhängig ( bei Linux als Datei, bei Windows in der Registry...)
    // gespeichert werden die Konfigurationen aus dem dialog_konf-Fenster und sKO_file
    void readSettings();
    void writeSettings();

    // startet bzw, stoppt die Aufnahme / Protokollierung der Steuerbefehle
    // Das Abrufen der akutellen Position wird nicht aufgenommen
    void REC(bool isREC);

signals:
    // sendet einen String zum Gerät
    // Ein ähnliches Signal gib es in jeder Klasse, die mit dem Gerät spricht.
    void sendToMoskito(QString);

    // sendet die aktuelle Position als SIGNAL
    void currentPos(int alpha, int beta);

private:
    Ui::MainWindow *ui;                             // graphische Oberfläche des Hauptfensters
    Dialog_rec *dialog_rec;                         // Aufnahmefenster
    Manual *dialog_man;                             // Manuelle Bedinung (Fenster)
    Konf *dialog_konf;                              // Konfigurationsfenster

    Kom_Moskito *moskito;                           // Kommunikation mit Moskito
    QList<spezialKoord> *sKO;                       // Gespeicherte Koordinaten für den Schnellzugriff
    QFile *sKO_file;                                // Datei, in den die Koordinaten gespeichert sind / werden
    QTimer *timer;                                  // Timer für currentPos()
};

#endif // MAINWINDOW_H
