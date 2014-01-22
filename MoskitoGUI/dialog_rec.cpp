#include "dialog_rec.h"
#include "ui_dialog_rec.h"

Dialog_rec::Dialog_rec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_rec)
{
    ui->setupUi(this);

    rec_file = new QFile;
    com = new QStringList;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(play_next()));

    connect(ui->Btn_play,SIGNAL(clicked(bool)),this,SLOT(play(bool)));
    connect(ui->Btn_rec,SIGNAL(toggled(bool)),this,SIGNAL(rec_start(bool)));
    connect(ui->Btn_save,SIGNAL(clicked()),this,SLOT(save()));
    connect(ui->Btn_open,SIGNAL(clicked()),this,SLOT(open()));
    connect(ui->Btn_send,SIGNAL(clicked()),this,SLOT(send()));
}

Dialog_rec::~Dialog_rec()
{
    delete rec_file;
    delete com;
    delete ui;
}

void Dialog_rec::send()
{
    emit sendToMoskito(ui->lEd_send->text().split('\n')[0]);
    ui->lEd_send->clear();
}

void Dialog_rec::play(bool isOff)
{
    if (!isOff){
        timer->stop();
        ui->Btn_play->setText("Wiedergeben");
    }else{
        com->clear();
        nr = 1;
        *com = ui->txtEd_rec->toPlainText().split("\n");
        emit sendToMoskito(com->value(0));
        timer->start(ui->dSpinBx_dt->value() * 1000);
        ui->Btn_play->setText("Stop");
    }
}

void Dialog_rec::play_next()
{
    if (nr < com->length()){
        emit sendToMoskito(com->value(nr));
        nr++;
    }else{
        if (ui->checkBx_wdh->isChecked()){
            play(true);
        }else{
            play(false);
        }
    }
}

void Dialog_rec::save()
{
    rec_file->setFileName(QFileDialog::getSaveFileName(this,"Aufnahmedatei", QDir::homePath(), "alle Dateien (*.*)"));
    rec_file->open(QIODevice::WriteOnly);
    rec_file->write(ui->txtEd_rec->toPlainText().toLatin1());
    rec_file->close();
}

void Dialog_rec::open()
{
    rec_file->setFileName(QFileDialog::getOpenFileName(this,"Aufnahmedatei", QDir::homePath(), "alle Dateien (*.*)"));
    rec_file->open(QIODevice::ReadOnly);
    ui->txtEd_rec->setText(QString(rec_file->readAll()));
    rec_file->close();
}

void Dialog_rec::writeREC(QString str)
{
    if (ui->txtEd_rec->toPlainText().isEmpty())
        ui->txtEd_rec->setPlainText(ui->txtEd_rec->toPlainText() + str );
    else
        ui->txtEd_rec->setPlainText(ui->txtEd_rec->toPlainText() + "\n" + str );
}
