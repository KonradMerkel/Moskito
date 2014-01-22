#ifndef KONF_H
#define KONF_H

/************************************************************
                       Konfiguration
*************************************************************/
#define PI 3.1415926535

/************************************************************
                        Bibliotheken
*************************************************************/
#include <QDialog>
#include <math.h>

/************************************************************
                       class Konf
*************************************************************/
namespace Ui {
class Konf;
}

class Konf : public QDialog
{
    Q_OBJECT
    
public:
    explicit Konf(QWidget *parent = 0);
    ~Konf();

public slots:

    // setzt die Variablen und Rechnungen auf den aktuellen Stand.
    // Durch das SIGNAL MainWindow::currentPos(int,int) bekommt es
    // die aktuelle Positionen der Motoren. Diese dienen der
    // Berechnungen für eine mögliche Kalibierung bzw Konfiguration
    void currentAlphaBeta(int nalpha, int nbeta);

    // Diese Methoden Errechnen den Radius, die Höhe bzw die Geschwindigkeit
    // des Geschosses aus den gegebenen Werten (Benutzereingabe und currentAlphaBeta)
    void setCalcRadius();
    void setCalcHigh();
    void setCalcV();

    // setzen den eingegebenen bzw errechneten Konfigurationen als Wert fest.
    // Diese Werte werden gespeichert und sind beim nächsten Neustart wieder
    // verfügbar
    void setHigh(double nHigh);
    void setHigh();
    void setRadius(double nRadius);
    void setRadius();
    void setV(double nV);
    void setV();

    // Geben die Konfigurationswerte aus
    double getRadius();
    double getHigh();
    double getV();
    
private:
    Ui::Konf *ui;                               // graphische Benutzeroberfläche
    int alpha;                                  // Drehwinkel Alpha für die Berechnung
    int beta;                                   // Drehwinkel Beta für die Berechnung
};

#endif // KONF_H
