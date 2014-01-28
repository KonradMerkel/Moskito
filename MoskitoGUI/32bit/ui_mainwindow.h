/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *act_aim;
    QAction *act_fire;
    QAction *act_demo;
    QAction *act_KOsave;
    QAction *act_aboutMoskito;
    QAction *act_aboutQt;
    QAction *act_standby;
    QAction *act_konf;
    QAction *act_rec;
    QAction *act_direct;
    QAction *act_parableN;
    QAction *act_close;
    QAction *act_manual;
    QAction *act_libelle_konf;
    QAction *act_KOclear;
    QAction *act_saveKOFile;
    QAction *act_readKOFile;
    QAction *act_rm;
    QAction *act_edit;
    QAction *act_laser_on_off;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_4;
    QGroupBox *gBox_KOS;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *doubleSpinBox_y;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_z;
    QDoubleSpinBox *doubleSpinBox_x;
    QGroupBox *gBox_man;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLabel *label_4;
    QSpinBox *spinBox_alpha;
    QSpinBox *spinBox_beta;
    QPushButton *Btn_konfig;
    QPushButton *Btn_manual;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *Btn_control;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBx_Kosave;
    QPushButton *Btn_KOsave;
    QGridLayout *gridLayout_6;
    QPushButton *Btn_edit;
    QPushButton *Btn_rm;
    QPushButton *Btn_saveFile;
    QPushButton *Btn_readFile;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *radBtn_direkt;
    QRadioButton *radBtn_parableN;
    QPushButton *Btn_standby;
    QPushButton *Btn_laser;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *Btn_aim;
    QPushButton *Btn_fire;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lb_fail;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lb_status;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QMenu *menuMoskito;
    QMenu *menuZiehloptionen;
    QMenu *menuKoordinatenspeicher;
    QMenu *menuAbout;
    QMenu *menuOptionen;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(723, 509);
        MainWindow->setFocusPolicy(Qt::ClickFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/picture/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        act_aim = new QAction(MainWindow);
        act_aim->setObjectName(QString::fromUtf8("act_aim"));
        act_fire = new QAction(MainWindow);
        act_fire->setObjectName(QString::fromUtf8("act_fire"));
        act_demo = new QAction(MainWindow);
        act_demo->setObjectName(QString::fromUtf8("act_demo"));
        act_KOsave = new QAction(MainWindow);
        act_KOsave->setObjectName(QString::fromUtf8("act_KOsave"));
        act_aboutMoskito = new QAction(MainWindow);
        act_aboutMoskito->setObjectName(QString::fromUtf8("act_aboutMoskito"));
        act_aboutQt = new QAction(MainWindow);
        act_aboutQt->setObjectName(QString::fromUtf8("act_aboutQt"));
        act_standby = new QAction(MainWindow);
        act_standby->setObjectName(QString::fromUtf8("act_standby"));
        act_konf = new QAction(MainWindow);
        act_konf->setObjectName(QString::fromUtf8("act_konf"));
        act_rec = new QAction(MainWindow);
        act_rec->setObjectName(QString::fromUtf8("act_rec"));
        act_direct = new QAction(MainWindow);
        act_direct->setObjectName(QString::fromUtf8("act_direct"));
        act_parableN = new QAction(MainWindow);
        act_parableN->setObjectName(QString::fromUtf8("act_parableN"));
        act_close = new QAction(MainWindow);
        act_close->setObjectName(QString::fromUtf8("act_close"));
        act_manual = new QAction(MainWindow);
        act_manual->setObjectName(QString::fromUtf8("act_manual"));
        act_libelle_konf = new QAction(MainWindow);
        act_libelle_konf->setObjectName(QString::fromUtf8("act_libelle_konf"));
        act_KOclear = new QAction(MainWindow);
        act_KOclear->setObjectName(QString::fromUtf8("act_KOclear"));
        act_saveKOFile = new QAction(MainWindow);
        act_saveKOFile->setObjectName(QString::fromUtf8("act_saveKOFile"));
        act_readKOFile = new QAction(MainWindow);
        act_readKOFile->setObjectName(QString::fromUtf8("act_readKOFile"));
        act_rm = new QAction(MainWindow);
        act_rm->setObjectName(QString::fromUtf8("act_rm"));
        act_edit = new QAction(MainWindow);
        act_edit->setObjectName(QString::fromUtf8("act_edit"));
        act_laser_on_off = new QAction(MainWindow);
        act_laser_on_off->setObjectName(QString::fromUtf8("act_laser_on_off"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gBox_KOS = new QGroupBox(centralwidget);
        gBox_KOS->setObjectName(QString::fromUtf8("gBox_KOS"));
        gBox_KOS->setEnabled(true);
        gBox_KOS->setCheckable(true);
        gBox_KOS->setChecked(true);
        gridLayout_2 = new QGridLayout(gBox_KOS);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        doubleSpinBox_y = new QDoubleSpinBox(gBox_KOS);
        doubleSpinBox_y->setObjectName(QString::fromUtf8("doubleSpinBox_y"));
        doubleSpinBox_y->setEnabled(true);
        doubleSpinBox_y->setDecimals(2);
        doubleSpinBox_y->setMinimum(-1e+09);
        doubleSpinBox_y->setMaximum(1e+09);
        doubleSpinBox_y->setSingleStep(1);

        gridLayout_2->addWidget(doubleSpinBox_y, 1, 1, 1, 1);

        label = new QLabel(gBox_KOS);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gBox_KOS);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(gBox_KOS);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        doubleSpinBox_z = new QDoubleSpinBox(gBox_KOS);
        doubleSpinBox_z->setObjectName(QString::fromUtf8("doubleSpinBox_z"));
        doubleSpinBox_z->setEnabled(true);
        doubleSpinBox_z->setDecimals(2);
        doubleSpinBox_z->setMinimum(-1e+09);
        doubleSpinBox_z->setMaximum(1e+09);
        doubleSpinBox_z->setSingleStep(1);

        gridLayout_2->addWidget(doubleSpinBox_z, 2, 1, 1, 1);

        doubleSpinBox_x = new QDoubleSpinBox(gBox_KOS);
        doubleSpinBox_x->setObjectName(QString::fromUtf8("doubleSpinBox_x"));
        doubleSpinBox_x->setEnabled(true);
        doubleSpinBox_x->setDecimals(2);
        doubleSpinBox_x->setMinimum(-1e+09);
        doubleSpinBox_x->setMaximum(1e+09);
        doubleSpinBox_x->setSingleStep(1);

        gridLayout_2->addWidget(doubleSpinBox_x, 0, 1, 1, 1);


        gridLayout_4->addWidget(gBox_KOS, 0, 0, 1, 1);

        gBox_man = new QGroupBox(centralwidget);
        gBox_man->setObjectName(QString::fromUtf8("gBox_man"));
        gBox_man->setEnabled(true);
        gBox_man->setCheckable(true);
        gBox_man->setChecked(true);
        gridLayout_3 = new QGridLayout(gBox_man);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(gBox_man);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(gBox_man);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(true);

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        spinBox_alpha = new QSpinBox(gBox_man);
        spinBox_alpha->setObjectName(QString::fromUtf8("spinBox_alpha"));
        spinBox_alpha->setEnabled(true);
        spinBox_alpha->setMaximum(180);

        gridLayout_3->addWidget(spinBox_alpha, 0, 1, 1, 1);

        spinBox_beta = new QSpinBox(gBox_man);
        spinBox_beta->setObjectName(QString::fromUtf8("spinBox_beta"));
        spinBox_beta->setEnabled(true);
        spinBox_beta->setMaximum(180);

        gridLayout_3->addWidget(spinBox_beta, 1, 1, 1, 1);


        gridLayout_4->addWidget(gBox_man, 0, 1, 1, 1);

        Btn_konfig = new QPushButton(centralwidget);
        Btn_konfig->setObjectName(QString::fromUtf8("Btn_konfig"));
        Btn_konfig->setEnabled(true);

        gridLayout_4->addWidget(Btn_konfig, 1, 0, 1, 1);

        Btn_manual = new QPushButton(centralwidget);
        Btn_manual->setObjectName(QString::fromUtf8("Btn_manual"));
        Btn_manual->setEnabled(true);

        gridLayout_4->addWidget(Btn_manual, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_4);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setChecked(true);

        verticalLayout_3->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout_3->addWidget(radioButton_3);

        Btn_control = new QPushButton(groupBox);
        Btn_control->setObjectName(QString::fromUtf8("Btn_control"));

        verticalLayout_3->addWidget(Btn_control);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        comboBx_Kosave = new QComboBox(groupBox_2);
        comboBx_Kosave->setObjectName(QString::fromUtf8("comboBx_Kosave"));

        verticalLayout_2->addWidget(comboBx_Kosave);

        Btn_KOsave = new QPushButton(groupBox_2);
        Btn_KOsave->setObjectName(QString::fromUtf8("Btn_KOsave"));

        verticalLayout_2->addWidget(Btn_KOsave);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        Btn_edit = new QPushButton(groupBox_2);
        Btn_edit->setObjectName(QString::fromUtf8("Btn_edit"));

        gridLayout_6->addWidget(Btn_edit, 0, 0, 1, 1);

        Btn_rm = new QPushButton(groupBox_2);
        Btn_rm->setObjectName(QString::fromUtf8("Btn_rm"));

        gridLayout_6->addWidget(Btn_rm, 0, 1, 1, 1);

        Btn_saveFile = new QPushButton(groupBox_2);
        Btn_saveFile->setObjectName(QString::fromUtf8("Btn_saveFile"));

        gridLayout_6->addWidget(Btn_saveFile, 1, 0, 1, 1);

        Btn_readFile = new QPushButton(groupBox_2);
        Btn_readFile->setObjectName(QString::fromUtf8("Btn_readFile"));

        gridLayout_6->addWidget(Btn_readFile, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_6);


        horizontalLayout_2->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radBtn_direkt = new QRadioButton(groupBox_4);
        radBtn_direkt->setObjectName(QString::fromUtf8("radBtn_direkt"));
        radBtn_direkt->setChecked(true);

        verticalLayout->addWidget(radBtn_direkt);

        radBtn_parableN = new QRadioButton(groupBox_4);
        radBtn_parableN->setObjectName(QString::fromUtf8("radBtn_parableN"));
        radBtn_parableN->setEnabled(true);

        verticalLayout->addWidget(radBtn_parableN);

        Btn_standby = new QPushButton(groupBox_4);
        Btn_standby->setObjectName(QString::fromUtf8("Btn_standby"));

        verticalLayout->addWidget(Btn_standby);

        Btn_laser = new QPushButton(groupBox_4);
        Btn_laser->setObjectName(QString::fromUtf8("Btn_laser"));

        verticalLayout->addWidget(Btn_laser);


        horizontalLayout_2->addWidget(groupBox_4);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Btn_aim = new QPushButton(centralwidget);
        Btn_aim->setObjectName(QString::fromUtf8("Btn_aim"));
        Btn_aim->setAutoDefault(true);

        horizontalLayout->addWidget(Btn_aim);

        Btn_fire = new QPushButton(centralwidget);
        Btn_fire->setObjectName(QString::fromUtf8("Btn_fire"));
        Btn_fire->setEnabled(true);
        Btn_fire->setCheckable(false);

        horizontalLayout->addWidget(Btn_fire);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lb_fail = new QLabel(centralwidget);
        lb_fail->setObjectName(QString::fromUtf8("lb_fail"));

        horizontalLayout_6->addWidget(lb_fail);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        lb_status = new QLabel(centralwidget);
        lb_status->setObjectName(QString::fromUtf8("lb_status"));
        lb_status->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        lb_status->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_6->addWidget(lb_status);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_6);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 723, 27));
        menuMoskito = new QMenu(menubar);
        menuMoskito->setObjectName(QString::fromUtf8("menuMoskito"));
        menuZiehloptionen = new QMenu(menuMoskito);
        menuZiehloptionen->setObjectName(QString::fromUtf8("menuZiehloptionen"));
        menuKoordinatenspeicher = new QMenu(menuMoskito);
        menuKoordinatenspeicher->setObjectName(QString::fromUtf8("menuKoordinatenspeicher"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuOptionen = new QMenu(menubar);
        menuOptionen->setObjectName(QString::fromUtf8("menuOptionen"));
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(gBox_KOS, doubleSpinBox_x);
        QWidget::setTabOrder(doubleSpinBox_x, doubleSpinBox_y);
        QWidget::setTabOrder(doubleSpinBox_y, doubleSpinBox_z);
        QWidget::setTabOrder(doubleSpinBox_z, gBox_man);
        QWidget::setTabOrder(gBox_man, spinBox_alpha);
        QWidget::setTabOrder(spinBox_alpha, spinBox_beta);
        QWidget::setTabOrder(spinBox_beta, radioButton_2);
        QWidget::setTabOrder(radioButton_2, radioButton_3);
        QWidget::setTabOrder(radioButton_3, radBtn_direkt);
        QWidget::setTabOrder(radBtn_direkt, radBtn_parableN);
        QWidget::setTabOrder(radBtn_parableN, Btn_standby);

        menubar->addAction(menuMoskito->menuAction());
        menubar->addAction(menuOptionen->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuMoskito->addAction(act_aim);
        menuMoskito->addAction(act_fire);
        menuMoskito->addAction(act_demo);
        menuMoskito->addSeparator();
        menuMoskito->addAction(act_laser_on_off);
        menuMoskito->addAction(act_standby);
        menuMoskito->addAction(menuZiehloptionen->menuAction());
        menuMoskito->addAction(menuKoordinatenspeicher->menuAction());
        menuMoskito->addSeparator();
        menuMoskito->addAction(act_close);
        menuZiehloptionen->addAction(act_direct);
        menuZiehloptionen->addAction(act_parableN);
        menuKoordinatenspeicher->addAction(act_KOsave);
        menuKoordinatenspeicher->addAction(act_edit);
        menuKoordinatenspeicher->addAction(act_rm);
        menuKoordinatenspeicher->addAction(act_readKOFile);
        menuKoordinatenspeicher->addAction(act_saveKOFile);
        menuKoordinatenspeicher->addSeparator();
        menuKoordinatenspeicher->addAction(act_KOclear);
        menuAbout->addAction(act_aboutMoskito);
        menuAbout->addAction(act_aboutQt);
        menuOptionen->addAction(act_manual);
        menuOptionen->addAction(act_rec);
        menuOptionen->addSeparator();
        menuOptionen->addAction(act_konf);

        retranslateUi(MainWindow);
        QObject::connect(Btn_fire, SIGNAL(clicked()), act_fire, SLOT(trigger()));
        QObject::connect(Btn_aim, SIGNAL(clicked()), act_aim, SLOT(trigger()));
        QObject::connect(Btn_KOsave, SIGNAL(clicked()), act_KOsave, SLOT(trigger()));
        QObject::connect(act_direct, SIGNAL(triggered()), radBtn_direkt, SLOT(click()));
        QObject::connect(Btn_standby, SIGNAL(clicked()), act_standby, SLOT(trigger()));
        QObject::connect(act_parableN, SIGNAL(triggered()), radBtn_parableN, SLOT(click()));
        QObject::connect(Btn_konfig, SIGNAL(clicked()), act_konf, SLOT(trigger()));
        QObject::connect(radioButton_2, SIGNAL(toggled(bool)), gBox_KOS, SLOT(setChecked(bool)));
        QObject::connect(radioButton_3, SIGNAL(toggled(bool)), gBox_man, SLOT(setChecked(bool)));
        QObject::connect(gBox_KOS, SIGNAL(toggled(bool)), radioButton_2, SLOT(setChecked(bool)));
        QObject::connect(gBox_man, SIGNAL(toggled(bool)), radioButton_3, SLOT(setChecked(bool)));
        QObject::connect(Btn_manual, SIGNAL(clicked()), act_manual, SLOT(trigger()));
        QObject::connect(Btn_readFile, SIGNAL(clicked()), act_readKOFile, SLOT(trigger()));
        QObject::connect(Btn_saveFile, SIGNAL(clicked()), act_saveKOFile, SLOT(trigger()));
        QObject::connect(Btn_rm, SIGNAL(clicked()), act_rm, SLOT(trigger()));
        QObject::connect(Btn_edit, SIGNAL(clicked()), act_edit, SLOT(trigger()));
        QObject::connect(Btn_control, SIGNAL(clicked()), act_rec, SLOT(trigger()));
        QObject::connect(Btn_laser, SIGNAL(clicked()), act_laser_on_off, SLOT(trigger()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Moskito Kontroll System", 0, QApplication::UnicodeUTF8));
        act_aim->setText(QApplication::translate("MainWindow", "&zielen", 0, QApplication::UnicodeUTF8));
        act_fire->setText(QApplication::translate("MainWindow", "&feuern", 0, QApplication::UnicodeUTF8));
        act_demo->setText(QApplication::translate("MainWindow", "&Demo", 0, QApplication::UnicodeUTF8));
        act_KOsave->setText(QApplication::translate("MainWindow", "neue &Koordinaten speichern", 0, QApplication::UnicodeUTF8));
        act_aboutMoskito->setText(QApplication::translate("MainWindow", "\303\234ber Moskito", 0, QApplication::UnicodeUTF8));
        act_aboutQt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
        act_standby->setText(QApplication::translate("MainWindow", "stand&by", 0, QApplication::UnicodeUTF8));
        act_konf->setText(QApplication::translate("MainWindow", "Konfigurationsmodus", 0, QApplication::UnicodeUTF8));
        act_rec->setText(QApplication::translate("MainWindow", "Steuerbefehle", 0, QApplication::UnicodeUTF8));
        act_direct->setText(QApplication::translate("MainWindow", "direkt anpeilen", 0, QApplication::UnicodeUTF8));
        act_parableN->setText(QApplication::translate("MainWindow", "Wurfparabel einberechnen", 0, QApplication::UnicodeUTF8));
        act_close->setText(QApplication::translate("MainWindow", "Beenden", 0, QApplication::UnicodeUTF8));
        act_manual->setText(QApplication::translate("MainWindow", "manuelle Bedienung", 0, QApplication::UnicodeUTF8));
        act_libelle_konf->setText(QApplication::translate("MainWindow", "Libelle konfiguerien", 0, QApplication::UnicodeUTF8));
        act_KOclear->setText(QApplication::translate("MainWindow", "gespeicherte Koordinaten l\303\266schen", 0, QApplication::UnicodeUTF8));
        act_saveKOFile->setText(QApplication::translate("MainWindow", "in Datei schreiben", 0, QApplication::UnicodeUTF8));
        act_readKOFile->setText(QApplication::translate("MainWindow", "aus Datei lesen", 0, QApplication::UnicodeUTF8));
        act_rm->setText(QApplication::translate("MainWindow", "l\303\266schen", 0, QApplication::UnicodeUTF8));
        act_edit->setText(QApplication::translate("MainWindow", "\303\244ndern", 0, QApplication::UnicodeUTF8));
        act_laser_on_off->setText(QApplication::translate("MainWindow", "Laser on / off", 0, QApplication::UnicodeUTF8));
        gBox_KOS->setTitle(QApplication::translate("MainWindow", "Koordinaten", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_y->setSuffix(QApplication::translate("MainWindow", "cm", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "X-Koordinaten", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Y-Koordinaten", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Z-Koordinaten", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_z->setSuffix(QApplication::translate("MainWindow", "cm", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_x->setSuffix(QApplication::translate("MainWindow", "cm", 0, QApplication::UnicodeUTF8));
        gBox_man->setTitle(QApplication::translate("MainWindow", "Manuell", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Beta", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Alpha", 0, QApplication::UnicodeUTF8));
        spinBox_alpha->setSuffix(QApplication::translate("MainWindow", "\302\260", 0, QApplication::UnicodeUTF8));
        spinBox_beta->setSuffix(QApplication::translate("MainWindow", "\302\260", 0, QApplication::UnicodeUTF8));
        spinBox_beta->setPrefix(QString());
        Btn_konfig->setText(QApplication::translate("MainWindow", "Moskito konfigurieren", 0, QApplication::UnicodeUTF8));
        Btn_manual->setText(QApplication::translate("MainWindow", "manuell", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Steuerung", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindow", "Koordinaten", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("MainWindow", "Manuell", 0, QApplication::UnicodeUTF8));
        Btn_control->setText(QApplication::translate("MainWindow", "Steuerbefehle", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Gespeicherte Koordinaten", 0, QApplication::UnicodeUTF8));
        Btn_KOsave->setText(QApplication::translate("MainWindow", "Koordinaten speichnern", 0, QApplication::UnicodeUTF8));
        Btn_edit->setText(QApplication::translate("MainWindow", "\303\244ndern", 0, QApplication::UnicodeUTF8));
        Btn_rm->setText(QApplication::translate("MainWindow", "l\303\266schen", 0, QApplication::UnicodeUTF8));
        Btn_saveFile->setText(QApplication::translate("MainWindow", "in Datei schreiben", 0, QApplication::UnicodeUTF8));
        Btn_readFile->setText(QApplication::translate("MainWindow", "Datei \303\266ffnen", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Optionen", 0, QApplication::UnicodeUTF8));
        radBtn_direkt->setText(QApplication::translate("MainWindow", "Direkt anpeilen", 0, QApplication::UnicodeUTF8));
        radBtn_parableN->setText(QApplication::translate("MainWindow", "Wurfparabel einberechnen ", 0, QApplication::UnicodeUTF8));
        Btn_standby->setText(QApplication::translate("MainWindow", "standby", 0, QApplication::UnicodeUTF8));
        Btn_laser->setText(QApplication::translate("MainWindow", "Laser an / aus", 0, QApplication::UnicodeUTF8));
        Btn_aim->setText(QApplication::translate("MainWindow", "zielen", 0, QApplication::UnicodeUTF8));
        Btn_fire->setText(QApplication::translate("MainWindow", "Zielen & Schie\303\237en", 0, QApplication::UnicodeUTF8));
        lb_fail->setText(QApplication::translate("MainWindow", "<html><head/><body><p>FAIL</p></body></html>", 0, QApplication::UnicodeUTF8));
        lb_status->setText(QApplication::translate("MainWindow", "status", 0, QApplication::UnicodeUTF8));
        menuMoskito->setTitle(QApplication::translate("MainWindow", "&Moskito", 0, QApplication::UnicodeUTF8));
        menuZiehloptionen->setTitle(QApplication::translate("MainWindow", "Zieloptionen", 0, QApplication::UnicodeUTF8));
        menuKoordinatenspeicher->setTitle(QApplication::translate("MainWindow", "Koordinatenspeicher", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        menuOptionen->setTitle(QApplication::translate("MainWindow", "&Optionen", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
