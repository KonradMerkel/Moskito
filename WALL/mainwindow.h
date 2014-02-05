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
    void singlePoint();                             // zeichnet einen einzelnen Punkt an der Wand an (entsprechend der Eingabe im GUI)
    void middle();                                  // zeigt die Mitte der Wand
    void aboutQt();                                 // about-Fenster von Qt
    void horizontalLine();                          // zeichnet einzelne Punkte einer horizontalen Linie
    void vertikalLine();                            // zeichnet einzelne Punkte einer vertikalen Linie

private:
    int hLine_n;                                    // Anzahl der schon gezeichneten Punkte einer Linie
    int vLine_n;
    Ui::MainWindow *ui;                             // graphische Benutzeroberfläche
    settings *dialg_settings;                       // Ausmessung und Ebenenerzeugung nach dem Start (Ausmessung der Wand)
};

#endif // MAINWINDOW_H
