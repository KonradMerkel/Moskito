#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#define TO_MIDDLE 0.071

namespace Ui {
class settings;
}



class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = 0);
    ~settings();

    double getAbstand();

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
    void calcRO(bool);
    void calcRU(bool);
    void calcLO(bool);
    void calcLU(bool);

private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
