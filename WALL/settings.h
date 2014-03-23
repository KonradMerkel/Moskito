#ifndef SETTINGS_H
#define SETTINGS_H

/************************************************************
                       Konfiguration
*************************************************************/
#ifndef DEBUGING
#define DEBUGING 0                      // ermöglicht zusätzliche Ausgabe zum debuggen
#endif
#define TO_MIDDLE 7.1                   // Abstand zwischen der Kante und dem Koordinatenursprung

/************************************************************
                        Bibliotheken
*************************************************************/
#include <QDialog>
#include <QString>
#include <QInputDialog>
#include "../../lib/Kom_Moskito.h"
#if DEBUGING
#include <iostream>
#endif


/************************************************************
                         namespace
*************************************************************/
#if DEBUGING
using namespace std;
#endif

namespace Ui {
class settings;
}

/************************************************************
                       class settings
*************************************************************/
class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = 0);
    ~settings();

    Kom_Moskito *moskito;                               // Kommunikation mit Moskito

    double getAbstand();                                // ermittelt den Abstand zwischen Wand und Moskito
    void setAbstand(double dist);

    double getTop() {return top;}
    double getButtom() {return buttom;}
    double getRight() {return right;}
    double getLeft() {return left;}

public slots:
    void ro_clicked();                                  // setzt die entsprechenden Koordinaten als Eckpunkte
    void lo_clicked();                                  // ro = rechts oben; lo = links oben; ru = rechts unten; lu = links unten
    void ru_clicked();
    void lu_clicked();
    void distance_clicked();
    void enable_all();
    void enable_next();

private slots:
    double calcKoord_horizontal(int alpha);             // errechnet aus den Drehwinkeln die Koordinaten
    double calcKoord_vertikal(int alpha, int beta);


private:
    Ui::settings *ui;
    double top;                                         // Höhe der Wand
    double buttom;                                      // Fußstelle der Wand
    double left;                                        // linke Begrenzung der Wand
    double right;                                       // rechte Begrenzung der Wand
};

#endif // SETTINGS_H
