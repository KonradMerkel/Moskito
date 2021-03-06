#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialg_settings = new settings;
    vLine_n = 0;
    hLine_n = 0;

    dialg_settings->show();
    ui->lb_fail->setText("");
    ui->lb_wand->setText("");
    connect(dialg_settings,SIGNAL(rejected()),this,SLOT(close()));
    connect(ui->Btn_single, SIGNAL(clicked()), this, SLOT(singlePoint()));
    connect(ui->Btn_middle,SIGNAL(clicked()),this,SLOT(middle()));
    connect(ui->Btn_aboutQt,SIGNAL(clicked()),this,SLOT(aboutQt()));
    connect(ui->Btn_horizontal,SIGNAL(clicked()),this,SLOT(horizontalLine()));
    connect(ui->Btn_vertikal,SIGNAL(clicked()),this,SLOT(vertikalLine()));
    connect(dialg_settings,SIGNAL(accepted()),this,SLOT(endofsettings()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::aboutQt()
{
    QMessageBox::aboutQt(this,"AboutQt");
}

void MainWindow::singlePoint()
{
    Koord sPoint;
    sPoint.x = dialg_settings->getAbstand();
    if (ui->cBx_horiz->currentText() == "von rechts"){
        sPoint.y = dialg_settings->getRight() + ui->spinBx_horiz->value();
    }else{
        sPoint.y = dialg_settings->getLeft() - ui->spinBx_horiz->value();
    }

    if (ui->cBx_vertikal->currentText() == "von oben"){
        sPoint.z = dialg_settings->getTop() - ui->spinBx_vertikal->value();
    }else{
        sPoint.z = dialg_settings->getButtom() + ui->spinBx_vertikal->value();
    }

    dialg_settings->moskito->aim_Koord(sPoint);
}

void MainWindow::horizontalLine()
{
    double abstand;
    vLine_n = 0;
    if (ui->cBx_ganzeWand_h->isChecked()){
        abstand = (dialg_settings->getLeft() - dialg_settings->getRight()) / (ui->spinBx_n_h->value() + 1);
        ui->spinBx_horiz->setValue(((hLine_n +1) * abstand));
    }else{
        abstand = ui->spinBx_abst_h->value();
        if ((abstand * ui->spinBx_n_h->value()+ ui->spinBx_horiz_h->value()) > (dialg_settings->getLeft() - dialg_settings->getRight()))
            QMessageBox::warning(this,"Warnung","Einige Punkte liegen außerhalb der markierten Wand. Diese werden nicht angezeigt.");
        ui->spinBx_horiz->setValue(ui->spinBx_horiz_h->value() + (hLine_n * abstand));
    }
    ui->cBx_horiz->setCurrentIndex(ui->cBx_horiz_h->currentIndex());

    ui->spinBx_vertikal->setValue(ui->spinBx_vertikal_h->value());
    ui->cBx_vertikal->setCurrentIndex(ui->cBx_vertikal_h->currentIndex());
    singlePoint();

    hLine_n++;
    if (hLine_n >= (ui->spinBx_n_h->value()))
        hLine_n = 0;
}

void MainWindow::vertikalLine()
{
    double abstand;
    hLine_n = 0;
    if (ui->cBx_ganzeWand_v->isChecked()){
        abstand = (dialg_settings->getTop() - dialg_settings->getButtom()) / (ui->spinBx_n_v->value() + 1);
        ui->spinBx_vertikal->setValue(((vLine_n+1) * abstand));
    }else{
        abstand = ui->spinBx_abst_v->value();
        if ((abstand * ui->spinBx_n_v->value() + ui->spinBx_vertikal_v->value()) > (dialg_settings->getTop() - dialg_settings->getButtom()))
            QMessageBox::warning(this,"Warnung","Einige Punkte liegen ausserhalb der markierten Wand. Diese werden nicht angezeigt.");
        ui->spinBx_vertikal->setValue(ui->spinBx_horiz_v->value() + (vLine_n * abstand));
    }
    ui->cBx_vertikal->setCurrentIndex(ui->cBx_vertikal_v->currentIndex());

    ui->spinBx_horiz->setValue(ui->spinBx_horiz_v->value());
    ui->cBx_horiz->setCurrentIndex(ui->cBx_horiz_v->currentIndex());
    singlePoint();

    vLine_n++;
    if (vLine_n >= (ui->spinBx_n_v->value()))
        vLine_n = 0;
}

void MainWindow::middle()
{
    ui->cBx_horiz->setCurrentIndex(0);
    ui->cBx_vertikal->setCurrentIndex(1);
    ui->spinBx_horiz->setValue((dialg_settings->getLeft() - dialg_settings->getRight()) /2);
    ui->spinBx_vertikal->setValue((dialg_settings->getTop() - dialg_settings->getButtom()) /2);
    singlePoint();
}

void MainWindow::endofsettings()
{
    QString wand = QString::number(dialg_settings->getLeft() - dialg_settings->getRight());
    wand += "cm  x  ";
    wand += QString::number(dialg_settings->getTop()  - dialg_settings->getButtom());
    wand += "cm";
    ui->lb_wand->setText(wand);
}
