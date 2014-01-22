#include "manual.h"
#include "ui_manual.h"

Manual::Manual(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manual)
{
    ui->setupUi(this);
    connect(ui->Btn_down,SIGNAL(clicked()),this,SLOT(down()));
    connect(ui->Btn_up,SIGNAL(clicked()),this,SLOT(up()));
    connect(ui->Btn_right,SIGNAL(clicked()),this,SLOT(right()));
    connect(ui->Btn_left,SIGNAL(clicked()),this,SLOT(left()));
}

Manual::~Manual()
{
    delete ui;
}

void Manual::up()
{
    emit sendToMoskito("8");
}

void Manual::down()
{
    emit sendToMoskito("2");
}

void Manual::right()
{
    emit sendToMoskito("6");
}

void Manual::left()
{
    emit sendToMoskito("4");
}
