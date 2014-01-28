/********************************************************************************
** Form generated from reading UI file 'manual.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUAL_H
#define UI_MANUAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Manual
{
public:
    QGridLayout *gridLayout;
    QPushButton *Btn_down;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *Btn_up;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *Btn_right;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_left;
    QPushButton *Btn_close;

    void setupUi(QDialog *Manual)
    {
        if (Manual->objectName().isEmpty())
            Manual->setObjectName(QString::fromUtf8("Manual"));
        Manual->resize(285, 260);
        gridLayout = new QGridLayout(Manual);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Btn_down = new QPushButton(Manual);
        Btn_down->setObjectName(QString::fromUtf8("Btn_down"));

        gridLayout->addWidget(Btn_down, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(82, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(82, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(82, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        Btn_up = new QPushButton(Manual);
        Btn_up->setObjectName(QString::fromUtf8("Btn_up"));

        gridLayout->addWidget(Btn_up, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(82, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 2, 1, 1);

        Btn_right = new QPushButton(Manual);
        Btn_right->setObjectName(QString::fromUtf8("Btn_right"));

        gridLayout->addWidget(Btn_right, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(82, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        Btn_left = new QPushButton(Manual);
        Btn_left->setObjectName(QString::fromUtf8("Btn_left"));

        gridLayout->addWidget(Btn_left, 1, 0, 1, 1);

        Btn_close = new QPushButton(Manual);
        Btn_close->setObjectName(QString::fromUtf8("Btn_close"));

        gridLayout->addWidget(Btn_close, 3, 2, 1, 1);

        QWidget::setTabOrder(Btn_up, Btn_down);
        QWidget::setTabOrder(Btn_down, Btn_left);
        QWidget::setTabOrder(Btn_left, Btn_right);
        QWidget::setTabOrder(Btn_right, Btn_close);

        retranslateUi(Manual);
        QObject::connect(Btn_close, SIGNAL(clicked()), Manual, SLOT(close()));

        QMetaObject::connectSlotsByName(Manual);
    } // setupUi

    void retranslateUi(QDialog *Manual)
    {
        Manual->setWindowTitle(QApplication::translate("Manual", "Manuelle Bedienung", 0, QApplication::UnicodeUTF8));
        Btn_down->setText(QApplication::translate("Manual", "down", 0, QApplication::UnicodeUTF8));
        Btn_up->setText(QApplication::translate("Manual", "up", 0, QApplication::UnicodeUTF8));
        Btn_right->setText(QApplication::translate("Manual", "right", 0, QApplication::UnicodeUTF8));
        Btn_left->setText(QApplication::translate("Manual", "left", 0, QApplication::UnicodeUTF8));
        Btn_close->setText(QApplication::translate("Manual", "Verstecken", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Manual: public Ui_Manual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUAL_H
