#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialg_settings = new settings;
    moskito = new Kom_Moskito;
    /*ro = new Koord;
    lu = new Koord;
    ru = new Koord;
    lo = new Koord;
*/
    QStringList items;
    items << "/dev/ttyACM0" << "/dev/ttyACM1" << "/dev/ttyACM2" << "/dev/ttyACM3" << "other" << "Testmodus";

    bool ok;
    QString item = QInputDialog::getItem(this, "Moskito-Port","Bitte geben Sie den Port an, an dem der Moskito angeschlossen ist.", items, 0, false, &ok);
    if (item == "other"){
        item = QInputDialog::getText(this,"Moskito-Port","Bitte geben Sie den Port an, an dem der Moskito angeschlossen ist.", QLineEdit::Normal, "/dev/ttyACM0", &ok);
    }
    if (!ok || item.isEmpty())                                                // keinen Port für die serielle Kommunikation
        exit(1);

    moskito->init(item);

    dialg_settings->show();
    ui->lb_fail->setText("");
    connect(dialg_settings,SIGNAL(rejected()),this,SLOT(close()));
    connect(dialg_settings,SIGNAL(accepted()),this,SLOT(calcCorner()));
    connect(dialg_settings,SIGNAL(calcLO(bool)),this,SLOT(setLO(bool)));
    connect(dialg_settings,SIGNAL(calcLU(bool)),this,SLOT(setLU(bool)));
    connect(dialg_settings,SIGNAL(calcRO(bool)),this,SLOT(setRO(bool)));
    connect(dialg_settings,SIGNAL(calcRU(bool)),this,SLOT(setRU(bool)));
    connect(ui->Btn_single, SIGNAL(clicked()), this, SLOT(singlePoint()));
    connect(dialg_settings,SIGNAL(sendToMoskito(QString)),moskito,SLOT(send(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calcCorner()
{
    int i = 0;

    if((lo.x == 0.0) && (lo.y == 0.0 )&& (lo.z == 0.0)){
        i++;
#if DEBUGING
        cout << "Errechne Links oben aus den gesamelten Daten\n";
#endif
        lo.x = getAbstand();
        lo.y = lu.y;
        lo.z = ro.z;
    }
    if((ro.x == 0.0) && (ro.y == 0.0 )&& (ro.z == 0.0)){
        i++;
        ro.x = getAbstand();
        ro.y = ru.y;
        ro.z = lo.z;
    }
    if((lu.x == 0.0) && (lu.y == 0.0 )&& (lu.z == 0.0)){
        i++;
        lu.x = getAbstand();
        lu.y = lo.y;
        lu.z = ru.z;
    }
    if((ru.x == 0.0) && (ru.y == 0.0 )&& (ru.z == 0.0)){
        i++;
        ru.x = getAbstand();
        ru.y = ro.y;
        ru.z = lu.z;
    }
    if (i > 1){
        QMessageBox::critical(this,"Mindestes 3 Ecken", "Es müssen mindestens drei Ecken markiert sein.");
        exit(1);
    }
}

double MainWindow::getAbstand()
{
    return dialg_settings->getAbstand();
}

void MainWindow::setLO(bool set)
{
    if (set)
    {
        Koord t = calcKoord();
        lo.x = t.x;
        lo.y = t.y;
        lo.z = t.z;
    }else{
        lo.x = 0;
        lo.y = 0;
        lo.z = 0;
    }
#if DEBUGING
    cout << "x: " << lo.x << endl;
    cout << "y: " << lo.y << endl;
    cout << "z: " << lo.z << endl;
#endif
}

void MainWindow::setLU(bool set)
{
    if (set)
    {
        Koord t = calcKoord();
        lu.x = t.x;
        lu.y = t.y;
        lu.z = t.z;
    }else{
        lu.x = 0;
        lu.y = 0;
        lu.z = 0;
    }
#if DEBUGING
    cout << "x: " << lu.x << endl;
    cout << "y: " << lu.y << endl;
    cout << "z: " << lu.z << endl;
#endif
}

void MainWindow::setRO(bool set)
{
    if (set)
    {
        Koord t = calcKoord();
        ro.x = t.x;
        ro.y = t.y;
        ro.z = t.z;
    }else{
        ro.x = 0;
        ro.y = 0;
        ro.z = 0;
    }
#if DEBUGING
    cout << "x: " << ro.x << endl;
    cout << "y: " << ro.y << endl;
    cout << "z: " << ro.z << endl;
#endif
}

void MainWindow::setRU(bool set)  // the choosen one
{
    if (set)
    {
        Koord t = calcKoord();
        ru.x = t.x;
        ru.y = t.y;
        ru.z = t.z;
    }else{
        ru.x = 0;
        ru.y = 0;
        ru.z = 0;
    }
#if DEBUGING
    cout << "x: " << ru.x << endl;
    cout << "y: " << ru.y << endl;
    cout << "z: " << ru.z << endl;
#endif
}

Koord MainWindow::calcKoord()
{
    double d = getAbstand();
    Koord t;
    int alpha=0;
    int beta=0;
    if (!moskito->pos(alpha,beta)){
        QMessageBox::warning(this,"Positionsermittlung", "Es gab einen Fehler in der Positionsermittlung. Bitte Prüfen Sie, dass das Gerät richtig angeschlossen ist");
    }

#if DEBUGING
    cout << "Alpha: " << alpha << " Beta: " << beta << endl;
#endif
    t.x = d;
    t.y = (RADIUS-(d*cos((PI*alpha) / 180)))/(sin((PI*alpha) / 180));
    if (beta < 90)
        t.z = tan((PI* (90-beta)) / 180) * sqrt(d * d + t.y * t.y) + HIGH;
    else if (beta > 90)
        t.z = -(sqrt(d * d + t.y * t.y))/(tan((PI * (180-beta)) / 180)) + HIGH;
    else
        t.z = HIGH;

    return t;
}

void MainWindow::singlePoint()
{
    Koord sPoint;
    sPoint.x = ro.x;
    if (ui->cBx_horiz->currentText() == "von rechts")
    {
        sPoint.y = ro.y + ui->spinBx_horiz->value();
    }else{
        sPoint.y = lo.y - ui->spinBx_horiz->value();
    }
    if (ui->cBox_vertikal->currentText() == "von oben")
    {
        sPoint.z = ro.z - ui->spinBx_vertikal->value();
    }else{
        sPoint.z = ru.z + ui->spinBx_vertikal->value();
    }
    moskito->aim_Koord(sPoint);
}
