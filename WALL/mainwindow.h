#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/************************************************************
                       Konfiguration
*************************************************************/
#define DEBUGING 1                                 // ermöglicht zusätzliche Ausgabe zum debuggen
#define DELTA_ALPHA 0                               // Korrekturfaktor des Alphaservos, aufgrund der Einspannung
#define GUI_ENABLE 1                                // Ermöglicht eine GUI-Unterstützung von Kom_Moskito
#define ENABLE_MORSE 0                              // ausschalten der Morsefunktionen

/************************************************************
                        Bibliotheken
*************************************************************/
#include <QMainWindow>
#include <QString>
#include <QInputDialog>
#include <QDataStream>
#include "settings.h"
#include "../../lib/Kom_Moskito.h"

#if DEBUGING
#include <iostream>
#endif


/************************************************************
                         Strukturen
*************************************************************/
#if DEBUGING
using namespace std;
#endif

namespace Ui {
class MainWindow;
}


/************************************************************
                       class MainWindow
*************************************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

   /* Koord getRO() {return ro;}
    Koord getRU() {return ru;}
    Koord getLO() {return lo;}
    Koord getLU() {return lu;}*/
    double getAbstand();

private slots:
    void setRO(bool set);
    void setRU(bool set);
    void setLO(bool set);
    void setLU(bool set);
    Koord calcKoord();

public slots:
    void calcCorner();
    void singlePoint();

private:
    Ui::MainWindow *ui;                             // graphische Benutzeroberfläche
    Kom_Moskito *moskito;                           // Kommunikation mit Moskito
    settings *dialg_settings;                       // Ausmessung und Ebenenerzeugung nach dem Start (Ausmessung der Wand)
    Koord ro;
    Koord ru;
    Koord lo;
    Koord lu;
};

#endif // MAINWINDOW_H
