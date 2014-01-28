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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGroupBox *gBx_horizontal;
    QGridLayout *gridLayout_2;
    QComboBox *cBx_vertikal_h;
    QPushButton *Btn_horizontal;
    QLabel *label_3;
    QComboBox *cBx_horiz_h;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *spinBx_horiz_h;
    QSpinBox *spinBx_n_h;
    QDoubleSpinBox *spinBx_abst_h;
    QDoubleSpinBox *spinBx_vertikal_h;
    QLabel *label_6;
    QCheckBox *cBx_ganzeWand_h;
    QGroupBox *gBx_vertikal;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QComboBox *cBx_vertikal_v;
    QPushButton *Btn_vertikal;
    QLabel *label_7;
    QComboBox *cBx_horiz_v;
    QDoubleSpinBox *spinBx_horiz_v;
    QDoubleSpinBox *spinBx_abst_v;
    QDoubleSpinBox *spinBx_vertikal_v;
    QLabel *label_9;
    QSpinBox *spinBx_n_v;
    QLabel *label_10;
    QCheckBox *cBx_ganzeWand_v;
    QGroupBox *gBx_single;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *cBx_vertikal;
    QDoubleSpinBox *spinBx_vertikal;
    QComboBox *cBx_horiz;
    QDoubleSpinBox *spinBx_horiz;
    QLabel *label_2;
    QPushButton *Btn_single;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *Btn_middle;
    QPushButton *Btn_aboutQt;
    QSpacerItem *verticalSpacer;
    QLabel *lb_fail;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(811, 491);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gBx_horizontal = new QGroupBox(centralWidget);
        gBx_horizontal->setObjectName(QString::fromUtf8("gBx_horizontal"));
        gBx_horizontal->setCheckable(false);
        gridLayout_2 = new QGridLayout(gBx_horizontal);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        cBx_vertikal_h = new QComboBox(gBx_horizontal);
        cBx_vertikal_h->setObjectName(QString::fromUtf8("cBx_vertikal_h"));

        gridLayout_2->addWidget(cBx_vertikal_h, 2, 1, 1, 1);

        Btn_horizontal = new QPushButton(gBx_horizontal);
        Btn_horizontal->setObjectName(QString::fromUtf8("Btn_horizontal"));

        gridLayout_2->addWidget(Btn_horizontal, 7, 0, 1, 3);

        label_3 = new QLabel(gBx_horizontal);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        cBx_horiz_h = new QComboBox(gBx_horizontal);
        cBx_horiz_h->setObjectName(QString::fromUtf8("cBx_horiz_h"));

        gridLayout_2->addWidget(cBx_horiz_h, 1, 1, 1, 1);

        label_4 = new QLabel(gBx_horizontal);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(gBx_horizontal);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 3, 0, 1, 2);

        spinBx_horiz_h = new QDoubleSpinBox(gBx_horizontal);
        spinBx_horiz_h->setObjectName(QString::fromUtf8("spinBx_horiz_h"));
        spinBx_horiz_h->setDecimals(2);
        spinBx_horiz_h->setMaximum(100);
        spinBx_horiz_h->setSingleStep(0.1);

        gridLayout_2->addWidget(spinBx_horiz_h, 1, 2, 1, 1);

        spinBx_n_h = new QSpinBox(gBx_horizontal);
        spinBx_n_h->setObjectName(QString::fromUtf8("spinBx_n_h"));

        gridLayout_2->addWidget(spinBx_n_h, 3, 2, 1, 1);

        spinBx_abst_h = new QDoubleSpinBox(gBx_horizontal);
        spinBx_abst_h->setObjectName(QString::fromUtf8("spinBx_abst_h"));
        spinBx_abst_h->setDecimals(2);
        spinBx_abst_h->setMaximum(100);
        spinBx_abst_h->setSingleStep(0.1);

        gridLayout_2->addWidget(spinBx_abst_h, 5, 2, 1, 1);

        spinBx_vertikal_h = new QDoubleSpinBox(gBx_horizontal);
        spinBx_vertikal_h->setObjectName(QString::fromUtf8("spinBx_vertikal_h"));
        spinBx_vertikal_h->setDecimals(2);
        spinBx_vertikal_h->setMaximum(100);
        spinBx_vertikal_h->setSingleStep(0.1);

        gridLayout_2->addWidget(spinBx_vertikal_h, 2, 2, 1, 1);

        label_6 = new QLabel(gBx_horizontal);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 5, 0, 1, 2);

        cBx_ganzeWand_h = new QCheckBox(gBx_horizontal);
        cBx_ganzeWand_h->setObjectName(QString::fromUtf8("cBx_ganzeWand_h"));

        gridLayout_2->addWidget(cBx_ganzeWand_h, 6, 0, 1, 2);


        gridLayout_4->addWidget(gBx_horizontal, 0, 0, 1, 1);

        gBx_vertikal = new QGroupBox(centralWidget);
        gBx_vertikal->setObjectName(QString::fromUtf8("gBx_vertikal"));
        gBx_vertikal->setCheckable(false);
        gridLayout_3 = new QGridLayout(gBx_vertikal);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_8 = new QLabel(gBx_vertikal);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        cBx_vertikal_v = new QComboBox(gBx_vertikal);
        cBx_vertikal_v->setObjectName(QString::fromUtf8("cBx_vertikal_v"));

        gridLayout_3->addWidget(cBx_vertikal_v, 2, 1, 1, 1);

        Btn_vertikal = new QPushButton(gBx_vertikal);
        Btn_vertikal->setObjectName(QString::fromUtf8("Btn_vertikal"));

        gridLayout_3->addWidget(Btn_vertikal, 6, 0, 1, 3);

        label_7 = new QLabel(gBx_vertikal);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        cBx_horiz_v = new QComboBox(gBx_vertikal);
        cBx_horiz_v->setObjectName(QString::fromUtf8("cBx_horiz_v"));

        gridLayout_3->addWidget(cBx_horiz_v, 1, 1, 1, 1);

        spinBx_horiz_v = new QDoubleSpinBox(gBx_vertikal);
        spinBx_horiz_v->setObjectName(QString::fromUtf8("spinBx_horiz_v"));
        spinBx_horiz_v->setDecimals(2);
        spinBx_horiz_v->setMaximum(100);
        spinBx_horiz_v->setSingleStep(0.1);

        gridLayout_3->addWidget(spinBx_horiz_v, 1, 2, 1, 1);

        spinBx_abst_v = new QDoubleSpinBox(gBx_vertikal);
        spinBx_abst_v->setObjectName(QString::fromUtf8("spinBx_abst_v"));
        spinBx_abst_v->setDecimals(2);
        spinBx_abst_v->setMaximum(100);
        spinBx_abst_v->setSingleStep(0.1);

        gridLayout_3->addWidget(spinBx_abst_v, 4, 2, 1, 1);

        spinBx_vertikal_v = new QDoubleSpinBox(gBx_vertikal);
        spinBx_vertikal_v->setObjectName(QString::fromUtf8("spinBx_vertikal_v"));
        spinBx_vertikal_v->setDecimals(2);
        spinBx_vertikal_v->setMaximum(100);
        spinBx_vertikal_v->setSingleStep(0.1);

        gridLayout_3->addWidget(spinBx_vertikal_v, 2, 2, 1, 1);

        label_9 = new QLabel(gBx_vertikal);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 4, 0, 1, 2);

        spinBx_n_v = new QSpinBox(gBx_vertikal);
        spinBx_n_v->setObjectName(QString::fromUtf8("spinBx_n_v"));

        gridLayout_3->addWidget(spinBx_n_v, 3, 2, 1, 1);

        label_10 = new QLabel(gBx_vertikal);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 3, 0, 1, 2);

        cBx_ganzeWand_v = new QCheckBox(gBx_vertikal);
        cBx_ganzeWand_v->setObjectName(QString::fromUtf8("cBx_ganzeWand_v"));

        gridLayout_3->addWidget(cBx_ganzeWand_v, 5, 0, 1, 3);


        gridLayout_4->addWidget(gBx_vertikal, 0, 1, 1, 1);

        gBx_single = new QGroupBox(centralWidget);
        gBx_single->setObjectName(QString::fromUtf8("gBx_single"));
        gBx_single->setCheckable(false);
        gridLayout = new QGridLayout(gBx_single);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(gBx_single);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cBx_vertikal = new QComboBox(gBx_single);
        cBx_vertikal->setObjectName(QString::fromUtf8("cBx_vertikal"));

        gridLayout->addWidget(cBx_vertikal, 1, 1, 1, 1);

        spinBx_vertikal = new QDoubleSpinBox(gBx_single);
        spinBx_vertikal->setObjectName(QString::fromUtf8("spinBx_vertikal"));
        spinBx_vertikal->setDecimals(2);
        spinBx_vertikal->setMaximum(100);
        spinBx_vertikal->setSingleStep(0.1);

        gridLayout->addWidget(spinBx_vertikal, 1, 2, 1, 1);

        cBx_horiz = new QComboBox(gBx_single);
        cBx_horiz->setObjectName(QString::fromUtf8("cBx_horiz"));

        gridLayout->addWidget(cBx_horiz, 0, 1, 1, 1);

        spinBx_horiz = new QDoubleSpinBox(gBx_single);
        spinBx_horiz->setObjectName(QString::fromUtf8("spinBx_horiz"));
        spinBx_horiz->setDecimals(2);
        spinBx_horiz->setMaximum(100);
        spinBx_horiz->setSingleStep(0.1);

        gridLayout->addWidget(spinBx_horiz, 0, 2, 1, 1);

        label_2 = new QLabel(gBx_single);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        Btn_single = new QPushButton(gBx_single);
        Btn_single->setObjectName(QString::fromUtf8("Btn_single"));

        gridLayout->addWidget(Btn_single, 2, 0, 1, 3);


        gridLayout_4->addWidget(gBx_single, 1, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Btn_middle = new QPushButton(groupBox);
        Btn_middle->setObjectName(QString::fromUtf8("Btn_middle"));

        verticalLayout->addWidget(Btn_middle);

        Btn_aboutQt = new QPushButton(groupBox);
        Btn_aboutQt->setObjectName(QString::fromUtf8("Btn_aboutQt"));

        verticalLayout->addWidget(Btn_aboutQt);


        gridLayout_4->addWidget(groupBox, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 2, 0, 1, 1);

        lb_fail = new QLabel(centralWidget);
        lb_fail->setObjectName(QString::fromUtf8("lb_fail"));

        gridLayout_4->addWidget(lb_fail, 3, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 811, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(cBx_ganzeWand_h, SIGNAL(toggled(bool)), spinBx_abst_h, SLOT(setDisabled(bool)));
        QObject::connect(cBx_ganzeWand_v, SIGNAL(toggled(bool)), spinBx_abst_v, SLOT(setDisabled(bool)));
        QObject::connect(cBx_ganzeWand_h, SIGNAL(toggled(bool)), spinBx_horiz_h, SLOT(setDisabled(bool)));
        QObject::connect(cBx_ganzeWand_v, SIGNAL(toggled(bool)), spinBx_horiz_v, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "WALL", 0, QApplication::UnicodeUTF8));
        gBx_horizontal->setTitle(QApplication::translate("MainWindow", "horizontale Linie", 0, QApplication::UnicodeUTF8));
        cBx_vertikal_h->clear();
        cBx_vertikal_h->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "von oben", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "von unten", 0, QApplication::UnicodeUTF8)
        );
        Btn_horizontal->setText(QApplication::translate("MainWindow", "Ersten Punkt anzeichnen", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Horizontal(ersterPunkt)", 0, QApplication::UnicodeUTF8));
        cBx_horiz_h->clear();
        cBx_horiz_h->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "von rechts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "von links", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("MainWindow", "Vertikal", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Anzahl der Punkte", 0, QApplication::UnicodeUTF8));
        spinBx_horiz_h->setSuffix(QApplication::translate("MainWindow", "cm", 0, QApplication::UnicodeUTF8));
        spinBx_abst_h->setSuffix(QApplication::translate("MainWindow", "cm", 0, QApplication::UnicodeUTF8));
        spinBx_vertikal_h->setSuffix(QApplication::translate("MainWindow", "cm", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Abstand zwischen den Punkten", 0, QApplication::UnicodeUTF8));
        cBx_ganzeWand_h->setText(QApplication::translate("MainWindow", "Punkt auf die gesamte Wand verteilen", 0, QApplication::UnicodeUTF8));
        gBx_vertikal->setTitle(QApplication::translate("MainWindow", "vertikale Linie", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Vertikal (erster Punkt)", 0, QApplication::UnicodeUTF8));
        cBx_vertikal_v->clear();
        cBx_vertikal_v->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "von oben", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "von unten", 0, QApplication::UnicodeUTF8)
        );
        Btn_vertikal->setText(QApplication::translate("MainWindow", "Ersten Punkt anzeichnen", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Horizontal", 0, QApplication::UnicodeUTF8));
        cBx_horiz_v->clear();
        cBx_horiz_v->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "von rechts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "von links", 0, QApplication::UnicodeUTF8)
        );
        spinBx_horiz_v->setSuffix(QApplication::translate("MainWindow", "cm", 0, QApplication::UnicodeUTF8));
        spinBx_abst_v->setSuffix(QApplication::translate("MainWindow", "cm", 0, QApplication::UnicodeUTF8));
        spinBx_vertikal_v->setSuffix(QApplication::translate("MainWindow", "cm", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Abstand zwischen den Punkten", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Anzahl der Punkte", 0, QApplication::UnicodeUTF8));
        cBx_ganzeWand_v->setText(QApplication::translate("MainWindow", "Punkt auf die gesamte Wand verteilen", 0, QApplication::UnicodeUTF8));
        gBx_single->setTitle(QApplication::translate("MainWindow", "einzelne Punkte", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Horizontal", 0, QApplication::UnicodeUTF8));
        cBx_vertikal->clear();
        cBx_vertikal->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "von oben", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "von unten", 0, QApplication::UnicodeUTF8)
        );
        spinBx_vertikal->setSuffix(QApplication::translate("MainWindow", "cm", 0, QApplication::UnicodeUTF8));
        cBx_horiz->clear();
        cBx_horiz->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "von rechts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "von links", 0, QApplication::UnicodeUTF8)
        );
        spinBx_horiz->setSuffix(QApplication::translate("MainWindow", "cm", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Vertikal", 0, QApplication::UnicodeUTF8));
        Btn_single->setText(QApplication::translate("MainWindow", "Anzeichnen", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Sonstiges", 0, QApplication::UnicodeUTF8));
        Btn_middle->setText(QApplication::translate("MainWindow", "Mittelpunkt anzeigen lassen", 0, QApplication::UnicodeUTF8));
        Btn_aboutQt->setText(QApplication::translate("MainWindow", "about Qt", 0, QApplication::UnicodeUTF8));
        lb_fail->setText(QApplication::translate("MainWindow", "FAIL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
