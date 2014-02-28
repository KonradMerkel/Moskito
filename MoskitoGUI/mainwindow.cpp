#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this); // GUI erstellen
  dialog_man  = new Manual;
  dialog_rec  = new Dialog_rec;
  dialog_konf = new Konf;
  sKO = new QList<spezialKoord>;
  sKO_file = new QFile;
  moskito = new Kom_Moskito;
  timer = new QTimer(this);

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

  connect(this,SIGNAL(currentPos(int,int)),dialog_konf, SLOT(currentAlphaBeta(int,int)));
  connect(ui->act_konf,SIGNAL(triggered()),dialog_konf,SLOT(show()));

  connect(dialog_man,SIGNAL(sendToMoskito(QString)), this, SIGNAL(sendToMoskito(QString)));
  connect(this,SIGNAL(sendToMoskito(QString)), moskito, SLOT(send(QString)));

  connect(ui->act_KOsave,SIGNAL(triggered()),this,SLOT(saveKO()));
  connect(ui->comboBx_Kosave,SIGNAL(activated(int)),this, SLOT(openKO(int)));
  connect(ui->comboBx_Kosave,SIGNAL(currentIndexChanged(int)),this, SLOT(openKO(int)));
  connect(ui->act_manual,SIGNAL(triggered()),dialog_man, SLOT(show()));
  connect(ui->act_aim,SIGNAL(triggered()),this, SLOT(aim()));
  connect(ui->act_standby,SIGNAL(triggered()),moskito, SLOT(standby()));
  connect(ui->act_close,SIGNAL(triggered()),this,SLOT(close()));
  connect(ui->act_aboutMoskito,SIGNAL(triggered()),this,SLOT(about()));
  connect(ui->act_aboutQt,SIGNAL(triggered()),this,SLOT(aboutQt()));
  connect(ui->act_rec,SIGNAL(triggered()),dialog_rec,SLOT(show()));
  connect(ui->act_KOclear,SIGNAL(triggered()),this,SLOT(sKO_clear()));
  connect(ui->act_readKOFile,SIGNAL(triggered()),this,SLOT(readKOFile_dialog()));
  connect(ui->act_saveKOFile,SIGNAL(triggered()),this,SLOT(saveKOFile_dialog()));
  connect(ui->act_edit,SIGNAL(triggered()),this,SLOT(editKO()));
  connect(ui->act_rm,SIGNAL(triggered()),this,SLOT(rmKO()));
  connect(ui->act_fire,SIGNAL(triggered()),this,SLOT(fire()));
  connect(ui->act_laser_on_off,SIGNAL(triggered()),this,SLOT(laser()));
  connect(ui->act_webPasswd,SIGNAL(triggered()),this,SLOT(setWebPasswd()));

  connect(dialog_rec,SIGNAL(rec_start(bool)),this,SLOT(REC(bool)));
  connect(dialog_rec,SIGNAL(sendToMoskito(QString)),this,SIGNAL(sendToMoskito(QString)));
  connect(timer, SIGNAL(timeout()), this, SLOT(currentPos()));

  readSettings();

  ui->gBox_man->setChecked(false);
  timer->start(CURRENT_POS_TIME);
  ui->lb_fail->setText("");
}

MainWindow::~MainWindow(){
    writeSettings();
    delete moskito;
    delete sKO;
    delete dialog_rec;
    delete dialog_konf;
    delete dialog_man;
    delete ui;
}

void MainWindow::aim(int laser){
#if DEBUGING
    cout << "aim (int) ausgelöst";
#endif
    if (ui->gBox_KOS->isChecked()) {
        Koord target;
        target.x = ui->doubleSpinBox_x->value();
        target.y = ui->doubleSpinBox_y->value();
        target.z = ui->doubleSpinBox_z->value();
        moskito->aim_Koord(target,laser);
        double dy, dz;
        if (moskito->variation(target, dy, dz)){
            QMessageBox::warning(this,"Fehlerberechnung des Zielvorgangs", QString("Der horizontale Fehler dy liegt bei ") + QString::number(dy) + QString("\nDer vertikale Fehler dz liegt bei ") + QString::number(dz));
        }

    }else if (ui->gBox_man->isChecked()) {
        moskito->aim_deg(ui->spinBox_alpha->value(), ui->spinBox_beta->value(),laser);
    }
}

void MainWindow::fire()
{
    aim(1);
}

void MainWindow::laser()
{
    moskito->setLaser(!moskito->getLaser());
}

void MainWindow::currentPos()
{
    int alpha=0, beta=0;
    if (moskito->pos(alpha, beta))
        emit currentPos(alpha, beta);
    ui->lb_status->setText(QString("Alpha: " + QString::number(alpha) + " Beta: " + QString::number(beta)));
}

void MainWindow::about()
{
    QMessageBox::about(this,QString::fromUtf8("Über Moskito"),QString::fromUtf8("<h1>"+ QCoreApplication::applicationName().toLatin1() +"</h1><p>"+ QCoreApplication::applicationVersion().toLatin1() +"</p><b>Moskito for Fedora (32/64 bit)</b><br>Ziel des Projektes ist es ein Mulitifunktionsgerät namens Moskito, bestehend aus mehreren Modulen und einer entsprechenden Software, zu entwickeln. Das dabei entstandene Gerät kann durch mehrschichtige Softwarearchitekturen, einem einfachen Aufbau, sowie mathematischen Beschreibung als Vermessungssystem und als Unterhaltungsgerät eingesetzt werden. "
                                                                               "Der Forschungsschwerpunkt des Projektes liegt vor allem auf der mathematischen Beschreibung und dem Softwaredesign. "
                                                                                "Hard- und Softwareentwickler: Konrad Merkel"));

}

void MainWindow::setWebPasswd()
{
    bool ok;
    QString passwd = QInputDialog::getText(this,"Webident setzen","Passwort und Nutzername bitte in folgendem Format UND in Base64 verschluesselt eingeben\nFormat: Nutzername:Passwort (z.B. admin:admin --> mit Base64: YWRtaW46YWRtaW4=)", QLineEdit::Normal, "YWRtaW46YWRtaW4=", &ok);

    if (!ok || passwd.isEmpty())                                                // keinen Port für die serielle Kommunikation
        return ;

    moskito->setWebPasswd(passwd);
}

void MainWindow::aboutQt()
{
    QMessageBox::aboutQt(this,"About Qt");
}

 void MainWindow::REC(bool isREC)
 {
     if (isREC){
         connect(moskito,SIGNAL(sendedToMoskito(QString)),dialog_rec,SLOT(writeREC(QString)));
     }else{
         disconnect(moskito,SIGNAL(sendedToMoskito(QString)),dialog_rec,SLOT(writeREC(QString)));
     }
 }

 void MainWindow::readSettings()
 {
     QSettings settings(QCoreApplication::organizationName(),QCoreApplication::applicationName());

     dialog_konf->setRadius(settings.value("radius",RADIUS).toDouble());
     dialog_konf->setHigh(settings.value("high",HIGH).toDouble());
     dialog_konf->setV(settings.value("v", DEFAULT_V).toDouble());
     readKOFile((settings.value("sKO_file",QString(QDir::homePath()) + QString("/target.aim")).toString()));
     openKO(0);
 }

 void MainWindow::writeSettings()
 {
     QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
     settings.clear();

     settings.setValue("radius",dialog_konf->getRadius());
     settings.setValue("high",dialog_konf->getHigh());
     settings.setValue("sKO_file",sKO_file->fileName());
     settings.setValue("v",dialog_konf->getV());
 }

 void MainWindow::saveKO()
 {
     bool ok;
     spezialKoord nKoord;
     nKoord.name = QInputDialog::getText(this,"Koordinaten speichern","Name unter den die Koordinaten gespeichert werden sollen", QLineEdit::Normal, "Target1", &ok);
     if (!ok)
         return;
     nKoord.alpha = ui->spinBox_alpha->value();
     nKoord.beta = ui->spinBox_beta->value();
     nKoord.KO.x = ui->doubleSpinBox_x->value();
     nKoord.KO.y = ui->doubleSpinBox_y->value();
     nKoord.KO.z = ui->doubleSpinBox_z->value();

     if(ui->gBox_man->isChecked())
         nKoord.isAct = 'M';
     else
         nKoord.isAct = 'K';

     sKO->append(nKoord);
     ui->comboBx_Kosave->addItem(nKoord.name);
 }

 void MainWindow::openKO(int item)
 {
     if( sKO->value(item).name != ui->comboBx_Kosave->itemText(item)){
         QMessageBox::critical(this,"Fehler bei der Rekonstruktion der Koordinaten","Die Wiederherstellung der Koordinaten aus der Speicherung ist nicht gelungen. Die Liste wird jetzt geleer. Bitte geben Sie danach die Koordinaten erneut ein.");
         sKO->clear();
         ui->comboBx_Kosave->clear();
         return;
     }
     ui->spinBox_alpha->setValue(sKO->value(item).alpha);
     ui->spinBox_beta->setValue(sKO->value(item).beta);
     ui->doubleSpinBox_x->setValue(sKO->value(item).KO.x);
     ui->doubleSpinBox_y->setValue(sKO->value(item).KO.y);
     ui->doubleSpinBox_z->setValue(sKO->value(item).KO.z);

     if (sKO->value(item).isAct == 'M')
         ui->gBox_man->setChecked(true);
     else
         ui->gBox_KOS->setChecked(true);
 }

 void MainWindow::sKO_clear()
 {
     sKO->clear();
     ui->comboBx_Kosave->clear();
 }


 bool MainWindow::readKOFile(QString filename)
 {
     if (!sKO->isEmpty()){
         if (QMessageBox::Yes == QMessageBox::warning(this,"Koordinaten vor dem Öffnen einer neuen speichern?","Möchten sie die aktuell gespeicherten Koordinaten in eine Datei schreiben?",QMessageBox::Yes,QMessageBox::No,QMessageBox::Abort))
             saveKOFile_dialog();
     }
     sKO_file->setFileName(filename);
     if (!sKO_file->exists())
         return false;
     if (!sKO_file->open(QIODevice::ReadOnly))
         return false;
     sKO_clear();
     QDataStream in(sKO_file);
     in.setVersion(QDataStream::Qt_4_8);
     int length;
     in >> length;
     spezialKoord Koord;
     for (int i=0; i < length; i++){
         in >> Koord.name >> Koord.alpha >> Koord.beta >> Koord.KO.x >> Koord.KO.y >> Koord.KO.z >> Koord.isAct;
         sKO->append(Koord);
     }
     sKO_file->close();
     for (int i=0; i < sKO->length(); i++){
         ui->comboBx_Kosave->addItem(sKO->value(i).name);
     }
     ui->comboBx_Kosave->setCurrentIndex(0);
     return true;
 }

 bool MainWindow::saveKOFile(QString filename)
 {
     sKO_file->setFileName(filename);
     if (!sKO_file->open(QIODevice::WriteOnly))
         return false;
     QDataStream out(sKO_file);
     out.setVersion(QDataStream::Qt_4_8);
     out << sKO->length();
     for (int i=0; i < sKO->length(); i++)
         out << sKO->value(i).name << sKO->value(i).alpha << sKO->value(i).beta << sKO->value(i).KO.x << sKO->value(i).KO.y << sKO->value(i).KO.z << sKO->value(i).isAct;
     sKO_file->close();
     return true;
 }

 bool MainWindow::saveKOFile_dialog()
 {
     return saveKOFile(QFileDialog::getSaveFileName(this,"Koordinaten speichern", sKO_file->fileName(), "alle Dateien (*.*)"));
 }

 bool MainWindow::readKOFile_dialog()
 {
     return readKOFile(QFileDialog::getOpenFileName(this,"Koordinaten speichern", sKO_file->fileName(), "alle Dateien (*.*)"));
 }

 void MainWindow::rmKO()
 {
     sKO->removeAt(ui->comboBx_Kosave->currentIndex());
     ui->comboBx_Kosave->removeItem(ui->comboBx_Kosave->currentIndex());
 }

 void MainWindow::editKO()
 {
     if(ui->comboBx_Kosave->currentText().isEmpty()){
         saveKO();
         return;
     }
     spezialKoord nKoord;
     bool ok;
     nKoord.name = QInputDialog::getText(this,"Koordinaten ändern","Name unter den die Koordinaten gespeichert werden sollen", QLineEdit::Normal, sKO->value(ui->comboBx_Kosave->currentIndex()).name, &ok);
     if (!ok)
         return;
     nKoord.alpha = ui->spinBox_alpha->value();
     nKoord.beta = ui->spinBox_beta->value();
     nKoord.KO.x = ui->doubleSpinBox_x->value();
     nKoord.KO.y = ui->doubleSpinBox_y->value();
     nKoord.KO.z = ui->doubleSpinBox_z->value();

     if(ui->gBox_man->isChecked())
         nKoord.isAct = 'M';
     else
         nKoord.isAct = 'K';
     sKO->replace(ui->comboBx_Kosave->currentIndex(),nKoord);
     ui->comboBx_Kosave->clear();
     for (int i=0; i < sKO->length(); i++){
         ui->comboBx_Kosave->addItem(sKO->value(i).name);
     }
 }
