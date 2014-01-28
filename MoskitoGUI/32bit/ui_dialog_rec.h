/********************************************************************************
** Form generated from reading UI file 'dialog_rec.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_REC_H
#define UI_DIALOG_REC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_rec
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Btn_open;
    QPushButton *Btn_save;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QDoubleSpinBox *dSpinBx_dt;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lEd_send;
    QPushButton *Btn_send;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Btn_rec;
    QPushButton *Btn_play;
    QCheckBox *checkBx_wdh;
    QTextEdit *txtEd_rec;
    QHBoxLayout *horizontalLayout;
    QPushButton *Btn_clear;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_close;

    void setupUi(QDialog *Dialog_rec)
    {
        if (Dialog_rec->objectName().isEmpty())
            Dialog_rec->setObjectName(QString::fromUtf8("Dialog_rec"));
        Dialog_rec->resize(405, 453);
        verticalLayout = new QVBoxLayout(Dialog_rec);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Dialog_rec);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Btn_open = new QPushButton(groupBox);
        Btn_open->setObjectName(QString::fromUtf8("Btn_open"));
        Btn_open->setEnabled(false);
        Btn_open->setAutoDefault(false);

        horizontalLayout_3->addWidget(Btn_open);

        Btn_save = new QPushButton(groupBox);
        Btn_save->setObjectName(QString::fromUtf8("Btn_save"));
        Btn_save->setEnabled(false);
        Btn_save->setAutoDefault(false);

        horizontalLayout_3->addWidget(Btn_save);

        horizontalSpacer_2 = new QSpacerItem(194, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        dSpinBx_dt = new QDoubleSpinBox(groupBox);
        dSpinBx_dt->setObjectName(QString::fromUtf8("dSpinBx_dt"));
        dSpinBx_dt->setMinimum(0.01);
        dSpinBx_dt->setValue(2);

        horizontalLayout_3->addWidget(dSpinBx_dt);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Dialog_rec);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lEd_send = new QLineEdit(groupBox_2);
        lEd_send->setObjectName(QString::fromUtf8("lEd_send"));

        horizontalLayout_2->addWidget(lEd_send);

        Btn_send = new QPushButton(groupBox_2);
        Btn_send->setObjectName(QString::fromUtf8("Btn_send"));
        Btn_send->setDefault(true);

        horizontalLayout_2->addWidget(Btn_send);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Btn_rec = new QPushButton(groupBox_2);
        Btn_rec->setObjectName(QString::fromUtf8("Btn_rec"));
        Btn_rec->setCheckable(true);
        Btn_rec->setChecked(false);

        horizontalLayout_4->addWidget(Btn_rec);

        Btn_play = new QPushButton(groupBox_2);
        Btn_play->setObjectName(QString::fromUtf8("Btn_play"));
        Btn_play->setCheckable(true);

        horizontalLayout_4->addWidget(Btn_play);


        verticalLayout_2->addLayout(horizontalLayout_4);

        checkBx_wdh = new QCheckBox(groupBox_2);
        checkBx_wdh->setObjectName(QString::fromUtf8("checkBx_wdh"));

        verticalLayout_2->addWidget(checkBx_wdh);

        txtEd_rec = new QTextEdit(groupBox_2);
        txtEd_rec->setObjectName(QString::fromUtf8("txtEd_rec"));
        txtEd_rec->setReadOnly(false);

        verticalLayout_2->addWidget(txtEd_rec);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Btn_clear = new QPushButton(Dialog_rec);
        Btn_clear->setObjectName(QString::fromUtf8("Btn_clear"));

        horizontalLayout->addWidget(Btn_clear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Btn_close = new QPushButton(Dialog_rec);
        Btn_close->setObjectName(QString::fromUtf8("Btn_close"));

        horizontalLayout->addWidget(Btn_close);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(lEd_send, Btn_send);
        QWidget::setTabOrder(Btn_send, Btn_rec);
        QWidget::setTabOrder(Btn_rec, Btn_play);
        QWidget::setTabOrder(Btn_play, checkBx_wdh);
        QWidget::setTabOrder(checkBx_wdh, txtEd_rec);
        QWidget::setTabOrder(txtEd_rec, Btn_open);
        QWidget::setTabOrder(Btn_open, Btn_save);
        QWidget::setTabOrder(Btn_save, dSpinBx_dt);
        QWidget::setTabOrder(dSpinBx_dt, Btn_clear);
        QWidget::setTabOrder(Btn_clear, Btn_close);

        retranslateUi(Dialog_rec);
        QObject::connect(Btn_close, SIGNAL(clicked()), Dialog_rec, SLOT(close()));
        QObject::connect(lEd_send, SIGNAL(editingFinished()), Btn_send, SLOT(click()));
        QObject::connect(Btn_clear, SIGNAL(clicked()), txtEd_rec, SLOT(clear()));

        QMetaObject::connectSlotsByName(Dialog_rec);
    } // setupUi

    void retranslateUi(QDialog *Dialog_rec)
    {
        Dialog_rec->setWindowTitle(QApplication::translate("Dialog_rec", "Aufnahme / Protokollierung", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialog_rec", "Aufnahmedatei", 0, QApplication::UnicodeUTF8));
        Btn_open->setText(QApplication::translate("Dialog_rec", "\303\226ffnen", 0, QApplication::UnicodeUTF8));
        Btn_save->setText(QApplication::translate("Dialog_rec", "Speichern", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog_rec", "Zeitabstand", 0, QApplication::UnicodeUTF8));
        dSpinBx_dt->setSuffix(QApplication::translate("Dialog_rec", "s", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Dialog_rec", "Steuerbefehle", 0, QApplication::UnicodeUTF8));
        Btn_send->setText(QApplication::translate("Dialog_rec", "Senden", 0, QApplication::UnicodeUTF8));
        Btn_rec->setText(QApplication::translate("Dialog_rec", "Aufzeichnen", 0, QApplication::UnicodeUTF8));
        Btn_play->setText(QApplication::translate("Dialog_rec", "Wiedergeben", 0, QApplication::UnicodeUTF8));
        checkBx_wdh->setText(QApplication::translate("Dialog_rec", "wiederholt abspielen", 0, QApplication::UnicodeUTF8));
        Btn_clear->setText(QApplication::translate("Dialog_rec", "Clear", 0, QApplication::UnicodeUTF8));
        Btn_close->setText(QApplication::translate("Dialog_rec", "Verstecken", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_rec: public Ui_Dialog_rec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_REC_H
