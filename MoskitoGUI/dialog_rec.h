#ifndef DIALOG_REC_H
#define DIALOG_REC_H

/************************************************************
                        Bibliotheken
*************************************************************/
#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QTimer>
#include <unistd.h>

/************************************************************
                       class Dialog_rec
*************************************************************/
namespace Ui {
class Dialog_rec;
}

class Dialog_rec : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_rec(QWidget *parent = 0);
    ~Dialog_rec();

signals:
    // löst das Starten und Stoppen des Aufnahmemoduses aus
    void rec_start(bool);

    // dieses Signal löst ein gleichnamiges Signal in MainWindow aus, welchen zum senden des Strings führt
    void sendToMoskito(QString);

public slots:

    // startet und stoppt die Wiedergabe einer Aufnahme
    void play(bool isOff);

    // sendet den nächsten Steuerbefehl, nachdem der Timer ausgelöst wurde
    void play_next();

    // öffnet und speichert die Aufnahme in einer Datei
    void save();
    void open();

    // sendet die erste Zeile der Aufnahme an den Moskito
    void send();

    // Speichert die gesendeten Befehle
    // Es werden nur Befehle aufgenommen, die mit dem SIGNAL
    // sendToMoskito(QString) versendet wurden. Somit wird die ständige Positionsabfrage
    // nicht notiert und es entsteht kein unnötiger Datenmüll.
    // Die Verknüfung mit dem SIGNAL wird druch die Methode MainWindow::REC(bool) geknüpft bzw
    // beendet.
    void writeREC(QString str);
    
private:
    Ui::Dialog_rec *ui;                                     // graphische Benutzeroberfläche
    QFile *rec_file;                                        // Datei, die geöffnet bzw gespeichert werden kann
    QStringList *com;                                       // Liste der Steuerkommandos, erzeugt aus der Aufnahmedatei
                                                            // Die List wird für die Wiedergabe genutzt
    QTimer *timer;                                          // Timer, die die Wiedergabe in den vorgegebenen Zeitintervallen auslöst
    int nr;                                                 // Anzahl an Steuerbefehlen (Zeilen in der Aufnahmedatei), die
};

#endif // DIALOG_REC_H
