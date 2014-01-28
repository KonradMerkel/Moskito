/********************************************************************************
** Form generated from reading UI file 'konf.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KONF_H
#define UI_KONF_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Konf
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *dSpinBx_z_2;
    QDoubleSpinBox *dSpinBx_calcHigh;
    QLabel *label_11;
    QDoubleSpinBox *dSpinBx_y_2;
    QLabel *label_2;
    QPushButton *Btn_Hchange;
    QLabel *label_10;
    QLabel *lb_beta;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *dSpinBx_x_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_12;
    QDoubleSpinBox *dSpinBx_calcRadius;
    QLabel *lb_alpha;
    QDoubleSpinBox *dSpinBx_y;
    QLabel *label_5;
    QLabel *label_3;
    QPushButton *Btn_Rchange;
    QDoubleSpinBox *dSpinBx_z;
    QLabel *label;
    QLabel *label_4;
    QDoubleSpinBox *dSpinBx_x;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLabel *label_14;
    QDoubleSpinBox *dSpinBx_energie;
    QDoubleSpinBox *dSpinBx_calcV;
    QPushButton *Btn_Vchange;
    QLabel *label_15;
    QDoubleSpinBox *dSpinBx_mass;
    QLabel *label_16;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QDoubleSpinBox *dspinBx_high;
    QDoubleSpinBox *dSpinBx_v;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_13;
    QDoubleSpinBox *dspinBx_radius;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *Konf)
    {
        if (Konf->objectName().isEmpty())
            Konf->setObjectName(QString::fromUtf8("Konf"));
        Konf->resize(742, 530);
        verticalLayout = new QVBoxLayout(Konf);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_3 = new QGroupBox(Konf);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        dSpinBx_z_2 = new QDoubleSpinBox(groupBox_3);
        dSpinBx_z_2->setObjectName(QString::fromUtf8("dSpinBx_z_2"));
        dSpinBx_z_2->setDecimals(3);
        dSpinBx_z_2->setMinimum(-1e+09);
        dSpinBx_z_2->setMaximum(0);
        dSpinBx_z_2->setSingleStep(0.1);
        dSpinBx_z_2->setValue(0);

        gridLayout_3->addWidget(dSpinBx_z_2, 4, 1, 1, 1);

        dSpinBx_calcHigh = new QDoubleSpinBox(groupBox_3);
        dSpinBx_calcHigh->setObjectName(QString::fromUtf8("dSpinBx_calcHigh"));
        dSpinBx_calcHigh->setReadOnly(true);
        dSpinBx_calcHigh->setDecimals(4);
        dSpinBx_calcHigh->setMaximum(1e+09);
        dSpinBx_calcHigh->setSingleStep(0.1);

        gridLayout_3->addWidget(dSpinBx_calcHigh, 5, 1, 1, 1);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 4, 0, 1, 1);

        dSpinBx_y_2 = new QDoubleSpinBox(groupBox_3);
        dSpinBx_y_2->setObjectName(QString::fromUtf8("dSpinBx_y_2"));
        dSpinBx_y_2->setDecimals(3);
        dSpinBx_y_2->setMinimum(-1e+09);
        dSpinBx_y_2->setMaximum(1e+09);
        dSpinBx_y_2->setSingleStep(0.1);
        dSpinBx_y_2->setValue(0);

        gridLayout_3->addWidget(dSpinBx_y_2, 2, 1, 2, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        Btn_Hchange = new QPushButton(groupBox_3);
        Btn_Hchange->setObjectName(QString::fromUtf8("Btn_Hchange"));
        Btn_Hchange->setAutoDefault(false);

        gridLayout_3->addWidget(Btn_Hchange, 6, 0, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        label_10->setFont(font);

        gridLayout_3->addWidget(label_10, 5, 0, 1, 1);

        lb_beta = new QLabel(groupBox_3);
        lb_beta->setObjectName(QString::fromUtf8("lb_beta"));

        gridLayout_3->addWidget(lb_beta, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 2, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 3, 0, 1, 1);

        dSpinBx_x_2 = new QDoubleSpinBox(groupBox_3);
        dSpinBx_x_2->setObjectName(QString::fromUtf8("dSpinBx_x_2"));
        dSpinBx_x_2->setDecimals(3);
        dSpinBx_x_2->setMinimum(-1e+09);
        dSpinBx_x_2->setMaximum(1e+09);
        dSpinBx_x_2->setSingleStep(0.1);
        dSpinBx_x_2->setValue(0);

        gridLayout_3->addWidget(dSpinBx_x_2, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 1, 1, 2, 1);

        groupBox_2 = new QGroupBox(Konf);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 3, 0, 1, 1);

        dSpinBx_calcRadius = new QDoubleSpinBox(groupBox_2);
        dSpinBx_calcRadius->setObjectName(QString::fromUtf8("dSpinBx_calcRadius"));
        dSpinBx_calcRadius->setReadOnly(true);
        dSpinBx_calcRadius->setDecimals(4);
        dSpinBx_calcRadius->setMaximum(1e+09);
        dSpinBx_calcRadius->setSingleStep(0.1);

        gridLayout_2->addWidget(dSpinBx_calcRadius, 5, 1, 1, 1);

        lb_alpha = new QLabel(groupBox_2);
        lb_alpha->setObjectName(QString::fromUtf8("lb_alpha"));

        gridLayout_2->addWidget(lb_alpha, 0, 1, 1, 1);

        dSpinBx_y = new QDoubleSpinBox(groupBox_2);
        dSpinBx_y->setObjectName(QString::fromUtf8("dSpinBx_y"));
        dSpinBx_y->setDecimals(3);
        dSpinBx_y->setMinimum(-1e+09);
        dSpinBx_y->setMaximum(1e+09);
        dSpinBx_y->setSingleStep(0.1);
        dSpinBx_y->setValue(0);

        gridLayout_2->addWidget(dSpinBx_y, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout_2->addWidget(label_5, 4, 0, 2, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        Btn_Rchange = new QPushButton(groupBox_2);
        Btn_Rchange->setObjectName(QString::fromUtf8("Btn_Rchange"));
        Btn_Rchange->setAutoDefault(false);

        gridLayout_2->addWidget(Btn_Rchange, 6, 0, 1, 1);

        dSpinBx_z = new QDoubleSpinBox(groupBox_2);
        dSpinBx_z->setObjectName(QString::fromUtf8("dSpinBx_z"));
        dSpinBx_z->setDecimals(3);
        dSpinBx_z->setMinimum(-1e+09);
        dSpinBx_z->setMaximum(0);
        dSpinBx_z->setSingleStep(0.1);
        dSpinBx_z->setValue(0);

        gridLayout_2->addWidget(dSpinBx_z, 3, 1, 2, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        dSpinBx_x = new QDoubleSpinBox(groupBox_2);
        dSpinBx_x->setObjectName(QString::fromUtf8("dSpinBx_x"));
        dSpinBx_x->setDecimals(3);
        dSpinBx_x->setMinimum(-1e+09);
        dSpinBx_x->setMaximum(1e+09);
        dSpinBx_x->setSingleStep(0.1);
        dSpinBx_x->setValue(0);

        gridLayout_2->addWidget(dSpinBx_x, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(Konf);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 0, 0, 1, 1);

        dSpinBx_energie = new QDoubleSpinBox(groupBox_4);
        dSpinBx_energie->setObjectName(QString::fromUtf8("dSpinBx_energie"));
        dSpinBx_energie->setDecimals(4);
        dSpinBx_energie->setMinimum(0);
        dSpinBx_energie->setMaximum(1e+09);
        dSpinBx_energie->setSingleStep(0.1);
        dSpinBx_energie->setValue(0);

        gridLayout_4->addWidget(dSpinBx_energie, 0, 1, 1, 1);

        dSpinBx_calcV = new QDoubleSpinBox(groupBox_4);
        dSpinBx_calcV->setObjectName(QString::fromUtf8("dSpinBx_calcV"));
        dSpinBx_calcV->setReadOnly(true);
        dSpinBx_calcV->setDecimals(4);
        dSpinBx_calcV->setMinimum(0);
        dSpinBx_calcV->setMaximum(1e+09);
        dSpinBx_calcV->setSingleStep(0.1);
        dSpinBx_calcV->setValue(0);

        gridLayout_4->addWidget(dSpinBx_calcV, 2, 1, 1, 1);

        Btn_Vchange = new QPushButton(groupBox_4);
        Btn_Vchange->setObjectName(QString::fromUtf8("Btn_Vchange"));
        Btn_Vchange->setAutoDefault(false);

        gridLayout_4->addWidget(Btn_Vchange, 4, 0, 1, 1);

        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_4->addWidget(label_15, 1, 0, 1, 1);

        dSpinBx_mass = new QDoubleSpinBox(groupBox_4);
        dSpinBx_mass->setObjectName(QString::fromUtf8("dSpinBx_mass"));
        dSpinBx_mass->setDecimals(4);
        dSpinBx_mass->setMinimum(0);
        dSpinBx_mass->setMaximum(1e+09);
        dSpinBx_mass->setSingleStep(0.1);
        dSpinBx_mass->setValue(0);

        gridLayout_4->addWidget(dSpinBx_mass, 1, 1, 1, 1);

        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);

        gridLayout_4->addWidget(label_16, 2, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_4, 0, 1, 1, 1);

        groupBox = new QGroupBox(Konf);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dspinBx_high = new QDoubleSpinBox(groupBox);
        dspinBx_high->setObjectName(QString::fromUtf8("dspinBx_high"));
        dspinBx_high->setDecimals(4);
        dspinBx_high->setMaximum(1e+09);
        dspinBx_high->setSingleStep(0.1);

        gridLayout->addWidget(dspinBx_high, 1, 1, 1, 1);

        dSpinBx_v = new QDoubleSpinBox(groupBox);
        dSpinBx_v->setObjectName(QString::fromUtf8("dSpinBx_v"));
        dSpinBx_v->setDecimals(4);
        dSpinBx_v->setMaximum(1e+09);
        dSpinBx_v->setSingleStep(0.1);

        gridLayout->addWidget(dSpinBx_v, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 2, 0, 1, 1);

        dspinBx_radius = new QDoubleSpinBox(groupBox);
        dspinBx_radius->setObjectName(QString::fromUtf8("dspinBx_radius"));
        dspinBx_radius->setDecimals(4);
        dspinBx_radius->setMaximum(1e+09);
        dspinBx_radius->setSingleStep(0.1);

        gridLayout->addWidget(dspinBx_radius, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 2, 1);


        verticalLayout->addLayout(gridLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pushButton = new QPushButton(Konf);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setAutoDefault(false);

        horizontalLayout_6->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_6);

        QWidget::setTabOrder(dSpinBx_x, dSpinBx_y);
        QWidget::setTabOrder(dSpinBx_y, dSpinBx_z);
        QWidget::setTabOrder(dSpinBx_z, dSpinBx_calcRadius);
        QWidget::setTabOrder(dSpinBx_calcRadius, Btn_Rchange);
        QWidget::setTabOrder(Btn_Rchange, dSpinBx_x_2);
        QWidget::setTabOrder(dSpinBx_x_2, dSpinBx_y_2);
        QWidget::setTabOrder(dSpinBx_y_2, dSpinBx_z_2);
        QWidget::setTabOrder(dSpinBx_z_2, dSpinBx_calcHigh);
        QWidget::setTabOrder(dSpinBx_calcHigh, Btn_Hchange);
        QWidget::setTabOrder(Btn_Hchange, dSpinBx_energie);
        QWidget::setTabOrder(dSpinBx_energie, dSpinBx_mass);
        QWidget::setTabOrder(dSpinBx_mass, Btn_Vchange);
        QWidget::setTabOrder(Btn_Vchange, pushButton);

        retranslateUi(Konf);
        QObject::connect(pushButton, SIGNAL(clicked()), Konf, SLOT(close()));
        QObject::connect(dSpinBx_x, SIGNAL(valueChanged(double)), dSpinBx_x_2, SLOT(setValue(double)));
        QObject::connect(dSpinBx_y, SIGNAL(valueChanged(double)), dSpinBx_y_2, SLOT(setValue(double)));
        QObject::connect(dSpinBx_x_2, SIGNAL(valueChanged(double)), dSpinBx_x, SLOT(setValue(double)));
        QObject::connect(dSpinBx_y_2, SIGNAL(valueChanged(double)), dSpinBx_y, SLOT(setValue(double)));
        QObject::connect(dSpinBx_z, SIGNAL(valueChanged(double)), dSpinBx_z_2, SLOT(setValue(double)));
        QObject::connect(dSpinBx_z_2, SIGNAL(valueChanged(double)), dSpinBx_z, SLOT(setValue(double)));

        QMetaObject::connectSlotsByName(Konf);
    } // setupUi

    void retranslateUi(QDialog *Konf)
    {
        Konf->setWindowTitle(QApplication::translate("Konf", "Konfigurationsmodus", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Konf", "Bestimmung der H\303\266he", 0, QApplication::UnicodeUTF8));
        dSpinBx_z_2->setSuffix(QApplication::translate("Konf", "cm", 0, QApplication::UnicodeUTF8));
        dSpinBx_calcHigh->setSuffix(QApplication::translate("Konf", "cm", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Konf", "Z-Koordinate (max 0m)", 0, QApplication::UnicodeUTF8));
        dSpinBx_y_2->setSuffix(QApplication::translate("Konf", "cm", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Konf", "Beta:", 0, QApplication::UnicodeUTF8));
        Btn_Hchange->setText(QApplication::translate("Konf", "\303\274bernehmen", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Konf", "H\303\266he =", 0, QApplication::UnicodeUTF8));
        lb_beta->setText(QApplication::translate("Konf", "x", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Konf", "X-Koordinate", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Konf", "Y-Koordinate", 0, QApplication::UnicodeUTF8));
        dSpinBx_x_2->setSuffix(QApplication::translate("Konf", "cm", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Konf", "Bestimmung des Radius", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Konf", "Z-Koordinate (max 0m)", 0, QApplication::UnicodeUTF8));
        dSpinBx_calcRadius->setSuffix(QApplication::translate("Konf", "cm", 0, QApplication::UnicodeUTF8));
        lb_alpha->setText(QApplication::translate("Konf", "x", 0, QApplication::UnicodeUTF8));
        dSpinBx_y->setSuffix(QApplication::translate("Konf", "cm", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Konf", "Radius = ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Konf", "X-Koordinate", 0, QApplication::UnicodeUTF8));
        Btn_Rchange->setText(QApplication::translate("Konf", "\303\274bernehmen", 0, QApplication::UnicodeUTF8));
        dSpinBx_z->setSuffix(QApplication::translate("Konf", "cm", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Konf", "Alpha:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Konf", "Y-Koordinate", 0, QApplication::UnicodeUTF8));
        dSpinBx_x->setSuffix(QApplication::translate("Konf", "cm", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Konf", "Bestimmung der Geschwindigkeit", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Konf", "<html><head/><body><p>Federspann-<br/>energie</p></body></html>", 0, QApplication::UnicodeUTF8));
        dSpinBx_energie->setPrefix(QString());
        dSpinBx_energie->setSuffix(QApplication::translate("Konf", "J", 0, QApplication::UnicodeUTF8));
        dSpinBx_calcV->setSuffix(QApplication::translate("Konf", "cm/s", 0, QApplication::UnicodeUTF8));
        Btn_Vchange->setText(QApplication::translate("Konf", "\303\274bernehmen", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Konf", "Masse", 0, QApplication::UnicodeUTF8));
        dSpinBx_mass->setSuffix(QApplication::translate("Konf", "g", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Konf", "v = ", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Konf", "Moskito-Ma\303\237e", 0, QApplication::UnicodeUTF8));
        dspinBx_high->setSuffix(QApplication::translate("Konf", "cm", 0, QApplication::UnicodeUTF8));
        dSpinBx_v->setSuffix(QApplication::translate("Konf", "cm/s", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Konf", "Radius", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Konf", "H\303\266he", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Konf", "<html><head/><body><p>Geschwindigkeit<br/>des Geschlosses</p></body></html>", 0, QApplication::UnicodeUTF8));
        dspinBx_radius->setSuffix(QApplication::translate("Konf", "cm", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Konf", "Verstecken", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Konf: public Ui_Konf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KONF_H
