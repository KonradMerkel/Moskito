/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *Btn_left;
    QPushButton *Btn_up;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *Btn_right;
    QPushButton *Btn_down;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *Btn_ro;
    QFrame *line;
    QPushButton *Btn_lo;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QDoubleSpinBox *spinBx_abstand;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *Btn_lu;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Btn_ru;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Btn_cancel;
    QPushButton *Btn_next;

    void setupUi(QDialog *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QString::fromUtf8("settings"));
        settings->resize(371, 466);
        verticalLayout = new QVBoxLayout(settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(settings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 4);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        Btn_left = new QPushButton(groupBox_2);
        Btn_left->setObjectName(QString::fromUtf8("Btn_left"));

        gridLayout_2->addWidget(Btn_left, 1, 0, 1, 1);

        Btn_up = new QPushButton(groupBox_2);
        Btn_up->setObjectName(QString::fromUtf8("Btn_up"));

        gridLayout_2->addWidget(Btn_up, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 2, 1, 1);

        Btn_right = new QPushButton(groupBox_2);
        Btn_right->setObjectName(QString::fromUtf8("Btn_right"));

        gridLayout_2->addWidget(Btn_right, 1, 2, 1, 1);

        Btn_down = new QPushButton(groupBox_2);
        Btn_down->setObjectName(QString::fromUtf8("Btn_down"));

        gridLayout_2->addWidget(Btn_down, 2, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 2, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 2, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 5, 0, 1, 3);

        Btn_ro = new QPushButton(groupBox);
        Btn_ro->setObjectName(QString::fromUtf8("Btn_ro"));
        Btn_ro->setCheckable(true);

        gridLayout->addWidget(Btn_ro, 0, 2, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 4, 0, 1, 3);

        Btn_lo = new QPushButton(groupBox);
        Btn_lo->setObjectName(QString::fromUtf8("Btn_lo"));
        Btn_lo->setCheckable(true);

        gridLayout->addWidget(Btn_lo, 0, 0, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 6, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        spinBx_abstand = new QDoubleSpinBox(groupBox);
        spinBx_abstand->setObjectName(QString::fromUtf8("spinBx_abstand"));
        spinBx_abstand->setDecimals(2);
        spinBx_abstand->setMinimum(0.01);
        spinBx_abstand->setMaximum(99999);
        spinBx_abstand->setSingleStep(0.1);

        horizontalLayout_3->addWidget(spinBx_abstand);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 4);

        Btn_lu = new QPushButton(groupBox);
        Btn_lu->setObjectName(QString::fromUtf8("Btn_lu"));
        Btn_lu->setCheckable(true);

        gridLayout->addWidget(Btn_lu, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 1, 1, 1);

        Btn_ru = new QPushButton(groupBox);
        Btn_ru->setObjectName(QString::fromUtf8("Btn_ru"));
        Btn_ru->setCheckable(true);

        gridLayout->addWidget(Btn_ru, 3, 2, 1, 1);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        Btn_cancel = new QPushButton(settings);
        Btn_cancel->setObjectName(QString::fromUtf8("Btn_cancel"));

        horizontalLayout->addWidget(Btn_cancel);

        Btn_next = new QPushButton(settings);
        Btn_next->setObjectName(QString::fromUtf8("Btn_next"));

        horizontalLayout->addWidget(Btn_next);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(spinBx_abstand, Btn_left);
        QWidget::setTabOrder(Btn_left, Btn_right);
        QWidget::setTabOrder(Btn_right, Btn_up);
        QWidget::setTabOrder(Btn_up, Btn_down);
        QWidget::setTabOrder(Btn_down, Btn_lo);
        QWidget::setTabOrder(Btn_lo, Btn_ro);
        QWidget::setTabOrder(Btn_ro, Btn_cancel);
        QWidget::setTabOrder(Btn_cancel, Btn_next);

        retranslateUi(settings);
        QObject::connect(Btn_next, SIGNAL(clicked()), settings, SLOT(accept()));
        QObject::connect(Btn_cancel, SIGNAL(clicked()), settings, SLOT(reject()));
        QObject::connect(Btn_lo, SIGNAL(toggled(bool)), Btn_ro, SLOT(setDisabled(bool)));
        QObject::connect(Btn_ro, SIGNAL(toggled(bool)), Btn_lo, SLOT(setDisabled(bool)));
        QObject::connect(Btn_ro, SIGNAL(toggled(bool)), Btn_ru, SLOT(setDisabled(bool)));
        QObject::connect(Btn_ru, SIGNAL(toggled(bool)), Btn_ro, SLOT(setDisabled(bool)));
        QObject::connect(Btn_lu, SIGNAL(toggled(bool)), Btn_ru, SLOT(setDisabled(bool)));
        QObject::connect(Btn_ru, SIGNAL(toggled(bool)), Btn_lu, SLOT(setDisabled(bool)));
        QObject::connect(Btn_lu, SIGNAL(toggled(bool)), Btn_lo, SLOT(setDisabled(bool)));
        QObject::connect(Btn_lo, SIGNAL(toggled(bool)), Btn_lu, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QDialog *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("settings", "An einer Wand ausrichten", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("settings", "<html><head/><body><p align=\"center\">Bitte ziehlen Sie mit dem LASER auf die Eckpunkte</p><p align=\"center\">der Wand und klicken Sie auf den</p><p align=\"center\">entsprechenden Button.</p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("settings", "Manuelle Bedienung", 0, QApplication::UnicodeUTF8));
        Btn_left->setText(QApplication::translate("settings", "links", 0, QApplication::UnicodeUTF8));
        Btn_up->setText(QApplication::translate("settings", "oben", 0, QApplication::UnicodeUTF8));
        Btn_right->setText(QApplication::translate("settings", "rechts", 0, QApplication::UnicodeUTF8));
        Btn_down->setText(QApplication::translate("settings", "unten", 0, QApplication::UnicodeUTF8));
        Btn_ro->setText(QApplication::translate("settings", "rechts oben", 0, QApplication::UnicodeUTF8));
        Btn_lo->setText(QApplication::translate("settings", "links oben", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("settings", "Abstand zur Wand", 0, QApplication::UnicodeUTF8));
        spinBx_abstand->setSuffix(QApplication::translate("settings", "cm", 0, QApplication::UnicodeUTF8));
        Btn_lu->setText(QApplication::translate("settings", "links unten", 0, QApplication::UnicodeUTF8));
        Btn_ru->setText(QApplication::translate("settings", "rechts unten", 0, QApplication::UnicodeUTF8));
        Btn_cancel->setText(QApplication::translate("settings", "Abbrechen", 0, QApplication::UnicodeUTF8));
        Btn_next->setText(QApplication::translate("settings", "Weiter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
