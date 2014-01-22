#ifndef MANUAL_H
#define MANUAL_H

/************************************************************
                        Bibliotheken
*************************************************************/
#include <QDialog>


/************************************************************
                         class Manual
*************************************************************/
namespace Ui {
class Manual;
}

class Manual : public QDialog
{
    Q_OBJECT
    
public:
    explicit Manual(QWidget *parent = 0);
    ~Manual();

public slots:

    // führt eine Bewegung in die entsprechende Richtung aus
    // Wichtig ist, dass die speziellen Steuersignale an den Moskito gesendet werden
    // Der Grund dafür liegt in der Genauigkeit.
    void up();
    void down();
    void right();
    void left();
    
signals:
    // dieses Signal löst ein gleichnamiges Signal in MainWindow aus, welchen zum senden des Strings führt
    void sendToMoskito(QString);

private:
    Ui::Manual *ui;
};

#endif // MANUAL_H
