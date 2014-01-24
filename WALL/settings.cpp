#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    moskito = new Kom_Moskito;

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
    connect(ui->Btn_lo,SIGNAL(clicked()),this,SLOT(lo_clicked()));
    connect(ui->Btn_ro,SIGNAL(clicked()),this,SLOT(ro_clicked()));
    connect(ui->Btn_lu,SIGNAL(clicked()),this,SLOT(lu_clicked()));
    connect(ui->Btn_ru,SIGNAL(clicked()),this,SLOT(ru_clicked()));
    connect(ui->Btn_down,SIGNAL(clicked()),moskito,SLOT(man_down()));
    connect(ui->Btn_up,SIGNAL(clicked()),moskito,SLOT(man_up()));
    connect(ui->Btn_right,SIGNAL(clicked()),moskito,SLOT(man_right()));
    connect(ui->Btn_left,SIGNAL(clicked()),moskito,SLOT(man_left()));
}

settings::~settings()
{
    delete ui;
}

double settings::getAbstand()
{
    return (ui->spinBx_abstand->value() + TO_MIDDLE);
}


double settings::calcKoord_horizontal(int alpha)
{
    return (RADIUS-(getAbstand()*cos((PI*alpha) / 180)))/(sin((PI*alpha) / 180));
}

double settings::calcKoord_vertikal(int alpha, int beta)
{
    if (beta < 90)
        return tan((PI* (90-beta)) / 180) * sqrt(getAbstand() * getAbstand() + calcKoord_horizontal(alpha) * calcKoord_horizontal(alpha)) + HIGH;
    else if (beta > 90)
        return -(sqrt(getAbstand() * getAbstand() + calcKoord_horizontal(alpha) * calcKoord_horizontal(alpha)))/(tan((PI * (180-beta)) / 180)) + HIGH;
    else
        return HIGH;
}

void settings::lo_clicked()
{
    int alpha=0;
    int beta=0;
    if (!moskito->pos(alpha,beta)){
        QMessageBox::warning(this,"Positionsermittlung", "Es gab einen Fehler in der Positionsermittlung. Bitte Prüfen Sie, dass das Gerät richtig angeschlossen ist");
        return;
    }

#if DEBUGING
    cout << "Alpha: " << alpha << " Beta: " << beta << endl;
#endif

    left = calcKoord_horizontal(alpha);
    top = calcKoord_vertikal(alpha,beta);
}
void settings::lu_clicked()
{
    int alpha=0;
    int beta=0;
    if (!moskito->pos(alpha,beta)){
        QMessageBox::warning(this,"Positionsermittlung", "Es gab einen Fehler in der Positionsermittlung. Bitte Prüfen Sie, dass das Gerät richtig angeschlossen ist");
        return;
    }

#if DEBUGING
    cout << "Alpha: " << alpha << " Beta: " << beta << endl;
#endif

    left = calcKoord_horizontal(alpha);
    buttom = calcKoord_vertikal(alpha,beta);
}
void settings::ro_clicked()
{
    int alpha=0;
    int beta=0;
    if (!moskito->pos(alpha,beta)){
        QMessageBox::warning(this,"Positionsermittlung", "Es gab einen Fehler in der Positionsermittlung. Bitte Prüfen Sie, dass das Gerät richtig angeschlossen ist");
        return;
    }

#if DEBUGING
    cout << "Alpha: " << alpha << " Beta: " << beta << endl;
#endif

    right = calcKoord_horizontal(alpha);
    top = calcKoord_vertikal(alpha,beta);
}
void settings::ru_clicked()
{
    int alpha=0;
    int beta=0;
    if (!moskito->pos(alpha,beta)){
        QMessageBox::warning(this,"Positionsermittlung", "Es gab einen Fehler in der Positionsermittlung. Bitte Prüfen Sie, dass das Gerät richtig angeschlossen ist");
        return;
    }

#if DEBUGING
    cout << "Alpha: " << alpha << " Beta: " << beta << endl;
#endif

    right = calcKoord_horizontal(alpha);
    buttom = calcKoord_vertikal(alpha,beta);
}
