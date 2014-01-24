#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/************************************************************
                       Konfiguration
*************************************************************/
#define DEBUGING 0                                  // ermöglicht zusätzliche Ausgabe zum debuggen
#define DELTA_ALPHA 0                               // Korrekturfaktor des Alphaservos, aufgrund der Einspannung
#define GUI_ENABLE 1                                // Ermöglicht eine GUI-Unterstützung von Kom_Moskito
#define ENABLE_MORSE 0                              // ausschalten der Morsefunktionen

/************************************************************
                        Bibliotheken
*************************************************************/
#include <QMainWindow>
#include "settings.h"

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

public slots:
    void singlePoint();
    void middle();

private:
    Ui::MainWindow *ui;                             // graphische Benutzeroberfläche
    settings *dialg_settings;                       // Ausmessung und Ebenenerzeugung nach dem Start (Ausmessung der Wand)
};

#endif // MAINWINDOW_H
