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

    double getAbstand();

    double getTop() {return top;}
    double getButtom() {return buttom;}
    double getRight() {return right;}
    double getLeft() {return left;}

public slots:
    void ro_clicked();
    void lo_clicked();
    void ru_clicked();
    void lu_clicked();

private slots:
    double calcKoord_horizontal(int alpha);
    double calcKoord_vertikal(int alpha, int beta);

private:
    Ui::settings *ui;
    double top;
    double buttom;
    double left;
    double right;
};

#endif // SETTINGS_H
