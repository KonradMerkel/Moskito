#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialg_settings = new settings;

    dialg_settings->show();
    ui->lb_fail->setText("");
    connect(dialg_settings,SIGNAL(rejected()),this,SLOT(close()));
    connect(ui->Btn_single, SIGNAL(clicked()), this, SLOT(singlePoint()));
    connect(ui->Btn_middle,SIGNAL(clicked()),this,SLOT(middle()));
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::middle()
{
    Koord sPoint;
    sPoint.x = dialg_settings->getAbstand();
    sPoint.y = (dialg_settings->getLeft() - dialg_settings->getRight()) /2;
    sPoint.z = (dialg_settings->getTop() - dialg_settings->getButtom()) /2;
    dialg_settings->moskito->aim_Koord(sPoint);
}
