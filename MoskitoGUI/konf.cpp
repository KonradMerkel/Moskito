#include "konf.h"
#include "ui_konf.h"

Konf::Konf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Konf)
{
    ui->setupUi(this);

    connect(ui->dSpinBx_x,SIGNAL(valueChanged(double)),this,SLOT(setCalcRadius()));
    connect(ui->dSpinBx_y,SIGNAL(valueChanged(double)),this,SLOT(setCalcRadius()));
    connect(ui->dSpinBx_z,SIGNAL(valueChanged(double)),this,SLOT(setCalcRadius()));

    connect(ui->dSpinBx_x,SIGNAL(valueChanged(double)),this,SLOT(setCalcHigh()));
    connect(ui->dSpinBx_y,SIGNAL(valueChanged(double)),this,SLOT(setCalcHigh()));
    connect(ui->dSpinBx_z,SIGNAL(valueChanged(double)),this,SLOT(setCalcHigh()));

    connect(ui->Btn_Rchange,SIGNAL(clicked()),this,SLOT(setRadius()));
    connect(ui->Btn_Hchange,SIGNAL(clicked()),this,SLOT(setHigh()));

    connect(ui->dSpinBx_energie,SIGNAL(valueChanged(double)),this,SLOT(setCalcV()));
    connect(ui->dSpinBx_mass,SIGNAL(valueChanged(double)),this,SLOT(setCalcV()));
    connect(ui->Btn_Vchange,SIGNAL(clicked()),this,SLOT(setV()));
}

Konf::~Konf()
{
    delete ui;
}

void Konf::setCalcRadius()
{
    ui->dSpinBx_calcRadius->setValue(ui->dSpinBx_x->value() * cos(alpha) + ui->dSpinBx_y->value() * sin(alpha));
}

void Konf::setCalcHigh()
{
    ui->dSpinBx_calcHigh->setValue((sqrt(ui->dSpinBx_x->value() * ui->dSpinBx_x->value()+ui->dSpinBx_y->value() * ui->dSpinBx_y->value()))/(tan(180*(180-beta)/PI))+ui->dSpinBx_z->value());
}
void Konf::setCalcV(){
    ui->dSpinBx_calcV->setValue(sqrt((2*ui->dSpinBx_energie->value())/(ui->dSpinBx_mass->value()/1000))*100);
}

void Konf::currentAlphaBeta(int nalpha, int nbeta)
{
    ui->lb_alpha->setText(QString::number(nalpha));
    ui->lb_beta->setText(QString::number(nbeta));
    alpha = nalpha;
    beta = nbeta;
    setCalcHigh();
    setCalcRadius();
}

void Konf::setRadius(double nRadius)
{
    ui->dspinBx_radius->setValue(nRadius);
}
void Konf::setHigh(double nHigh)
{
    ui->dspinBx_high->setValue(nHigh);
}
void Konf::setV(double nV)
{
    ui->dSpinBx_v->setValue(nV);
}

void Konf::setRadius()
{
    setCalcRadius();
    ui->dspinBx_radius->setValue(ui->dSpinBx_calcRadius->value());
}

void Konf::setHigh()
{
    setCalcHigh();
    ui->dspinBx_high->setValue(ui->dSpinBx_calcHigh->value());
}
void Konf::setV()
{
    setCalcV();
    ui->dSpinBx_v->setValue(ui->dSpinBx_calcV->value());
}

double Konf::getHigh() const
{
    return ui->dspinBx_high->value();
}
double Konf::getRadius() const
{
    return ui->dspinBx_radius->value();
}
double Konf::getV() const
{
    return ui->dSpinBx_v->value();
}
