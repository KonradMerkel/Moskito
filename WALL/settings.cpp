#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    connect(ui->Btn_lo,SIGNAL(clicked(bool)),this,SIGNAL(calcLO(bool)));
    connect(ui->Btn_lu,SIGNAL(clicked(bool)),this,SIGNAL(calcLU(bool)));
    connect(ui->Btn_ro,SIGNAL(clicked(bool)),this,SIGNAL(calcRO(bool)));
    connect(ui->Btn_ru,SIGNAL(clicked(bool)),this,SIGNAL(calcRU(bool)));
    connect(ui->Btn_down,SIGNAL(clicked()),this,SLOT(down()));
    connect(ui->Btn_up,SIGNAL(clicked()),this,SLOT(up()));
    connect(ui->Btn_right,SIGNAL(clicked()),this,SLOT(right()));
    connect(ui->Btn_left,SIGNAL(clicked()),this,SLOT(left()));
}

settings::~settings()
{
    delete ui;
}

double settings::getAbstand()
{
    return (ui->spinBx_abstand->value() + TO_MIDDLE);
}

void settings::up()
{
emit sendToMoskito("8");
}

void settings::down()
{
emit sendToMoskito("2");
}

void settings::right()
{
emit sendToMoskito("6");
}

void settings::left()
{
emit sendToMoskito("4");
}
