#include "mainwindow.h"
#include <QApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Konrad Merkel");
    QCoreApplication::setApplicationName("Moskito");
    QCoreApplication::setApplicationVersion("14.03");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
