#define DEBUGING  0
#define PORT "/dev/ttyACM0"
#include <QCoreApplication>
#include <QtTest/QtTest>
#include "../../lib/Kom_Moskito.h"
#include "../../lib/test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int alpha, beta;
    bool laser, ethernet;
    Kom_Moskito *moskito = new Kom_Moskito;
    Kom_Moskito *moskito_ = new Kom_Moskito;
    Test<bool> *vergl_bool = new Test<bool>;
    Test<int> *vergl_int = new Test<int>;
    //Test<std::string> *vergl_qstring = new Test<std::string>;

    vergl_bool->comp("Initialisierung(PORT)", moskito->init(PORT), true);
    QTest::qSleep(2500);

    /* LASER + SENDEN UND EMPFANGEN */
    vergl_bool->comp("setLaser(bool) (only return)",moskito->setLaser(false), true);
    QTest::qSleep(200);
    //vergl_qstring->comp("QString pos()",moskito->pos().toStdString(), std::string("93#93#0#0"));
    vergl_bool->comp("getLaser() (+ setLaser(bool))",moskito->getLaser(), false);
    vergl_bool->comp("setLaser(bool) (only return)",moskito->setLaser(true), true);
    QTest::qSleep(200);
    //vergl_qstring->comp("QString pos()",moskito->pos().toStdString(), "93#93#1#0");
    vergl_bool->comp("getLaser() (+ setLaser(bool))",moskito->getLaser(), true);
    vergl_bool->comp("setLaser(bool) (only return)",moskito->setLaser(true), true);
    QTest::qSleep(200);
    vergl_bool->comp("getLaser() (+ setLaser(bool))",moskito->getLaser(), true);
    vergl_bool->comp("setLaser(bool) (only return)",moskito->setLaser(false), true);
    QTest::qSleep(200);
    //vergl_qstring->comp("QString pos()",moskito->pos().toStdString(), "93#93#1#0");
    vergl_bool->comp("getLaser() (+ setLaser(bool))",moskito->getLaser(), false);

    /* SENDEN UND EMPFANGEN */
    vergl_bool->comp("standby() (only return)",moskito->standby(),true);
    QTest::qSleep(200);
    //vergl_qstring->comp("QString pos()",moskito->pos().toStdString(), "90#90#0#0");
    vergl_bool->comp("pos(int, int, bool, bool) (only return)", moskito->pos(alpha,beta,laser,ethernet), true);
    vergl_int->comp("alpha: pos(int, int, bool, bool)", alpha,90);
    vergl_int->comp("beta: pos(int, int, bool, bool)", beta,90);
    vergl_bool->comp("laser: pos(int, int, bool, bool)", laser, false);
    vergl_bool->comp("ethernet: pos(int, int, bool, bool)", ethernet, false);

    vergl_bool->comp("send(QString) (only return)",moskito->send("a94#87#0#"),true);
    QTest::qSleep(200);
    //vergl_qstring->comp("QString pos()",moskito->pos().toStdString(), "94#87#0#0");
    vergl_bool->comp("pos(int, int) (only return)", moskito->pos(alpha,beta), true);
    vergl_int->comp("alpha: pos(int, int)", alpha,94);
    vergl_int->comp("beta: pos(int, int)", beta,87);
    vergl_bool->comp("laser: pos(int, int)", laser, false);
    vergl_bool->comp("ethernet: pos(int, int)", ethernet, false);
    alpha = 4;
    beta = 5;
    vergl_bool->comp("pos(int, int, bool, bool) (only return)", moskito->pos(alpha,beta,laser,ethernet), true);
    vergl_int->comp("alpha: pos(int, int, bool, bool)", alpha,94);
    vergl_int->comp("beta: pos(int, int, bool, bool)", beta,87);
    vergl_bool->comp("laser: pos(int, int, bool, bool)", laser, false);
    vergl_bool->comp("ethernet: pos(int, int, bool, bool)", ethernet, false);

    vergl_bool->comp("send(QString) (only return)",moskito->send("f"),true);
    QTest::qSleep(200);
    //vergl_qstring->comp("QString pos()",moskito->pos().toStdString(), "94#87#1#0");
    vergl_bool->comp("pos(int, int) (only return)", moskito->pos(alpha,beta), true);
    vergl_int->comp("alpha: pos(int, int)", alpha,94);
    vergl_int->comp("beta: pos(int, int)", beta,87);
    vergl_bool->comp("laser: pos(int, int)", laser, false);
    vergl_bool->comp("ethernet: pos(int, int)", ethernet, false);
    alpha = 4;
    beta = 5;
    vergl_bool->comp("pos(int, int, bool, bool) (only return)", moskito->pos(alpha,beta,laser,ethernet), true);
    vergl_int->comp("alpha: pos(int, int, bool, bool)", alpha,94);
    vergl_int->comp("beta: pos(int, int, bool, bool)", beta,87);
    vergl_bool->comp("laser: pos(int, int, bool, bool)", laser, true);
    vergl_bool->comp("ethernet: pos(int, int, bool, bool)", ethernet, false);

    vergl_bool->comp("send(QString) (only return)",moskito->send("a280#-34#0#"),true);
    QTest::qSleep(1200);
    //vergl_qstring->comp("QString pos()",moskito->pos().toStdString(), "180#0#0#0");
    vergl_bool->comp("pos(int, int) (only return)", moskito->pos(alpha,beta), true);
    vergl_int->comp("alpha: pos(int, int)", alpha,180);
    vergl_int->comp("beta: pos(int, int)", beta,0);
    vergl_bool->comp("laser: pos(int, int)", laser, true);
    vergl_bool->comp("ethernet: pos(int, int)", ethernet, false);
    alpha = 4;
    beta = 5;
    vergl_bool->comp("pos(int, int, bool, bool) (only return)", moskito->pos(alpha,beta,laser,ethernet), true);
    vergl_int->comp("alpha: pos(int, int, bool, bool)", alpha,180);
    vergl_int->comp("beta: pos(int, int, bool, bool)", beta,0);
    vergl_bool->comp("laser: pos(int, int, bool, bool)", laser, false);
    vergl_bool->comp("ethernet: pos(int, int, bool, bool)", ethernet, false);

    vergl_bool->comp("send(QString) (only return)",moskito->send("a91#78#1#"),true);
    vergl_bool->comp("send(e) (Ethernet) (only return)",moskito->send("e"),true);
    QTest::qSleep(7000);
    //vergl_qstring->comp("QString pos()",moskito->pos().toStdString(), "91#78#1#1");
    vergl_bool->comp("pos(int, int) (only return)", moskito->pos(alpha,beta), true);
    vergl_int->comp("alpha: pos(int, int)", alpha,91);
    vergl_int->comp("beta: pos(int, int)", beta,78);
    vergl_bool->comp("laser: pos(int, int)", laser, false);
    vergl_bool->comp("ethernet: pos(int, int)", ethernet, false);
    alpha = 4;
    beta = 5;
    vergl_bool->comp("pos(int, int, bool, bool) (only return)", moskito->pos(alpha,beta,laser,ethernet), true);
    vergl_int->comp("alpha: pos(int, int, bool, bool)", alpha,91);
    vergl_int->comp("beta: pos(int, int, bool, bool)", beta,78);
    vergl_bool->comp("laser: pos(int, int, bool, bool)", laser, true);
    vergl_bool->comp("ethernet: pos(int, int, bool, bool)", ethernet, true);

    vergl_bool->comp("send(QString) (only return)",moskito->send("a94#87#*#"),true);
    QTest::qSleep(200);
    //vergl_qstring->comp("QString pos()",moskito->pos().toStdString(), "94#87#1#1");
    vergl_bool->comp("send(QString) (only return)",moskito->send("a23#23#0#"),true);
    vergl_bool->comp("send(QString) (only return)",moskito->send("o"),true);
    QTest::qSleep(2000);
    //vergl_qstring->comp("QString pos()",moskito->pos().toStdString(), "23#23#0#0");


    /* ETHERNET + SENDEN UND EMPFANGEN */
    vergl_bool->comp("setEthernet(bool) (only return)",moskito->setEthernet(false), true);
    QTest::qSleep(5000);
    //vergl_qstring->comp("QString pos()",moskito->pos().toStdString(), "93#93#0#0");
    vergl_bool->comp("getEthernet() (+ setEthernet(bool))",moskito->getEthernet(), false);
    vergl_bool->comp("setEthernet(bool) (only return)",moskito->setEthernet(true), true);
    QTest::qSleep(7000);
    //vergl_qstring->comp("QString pos()",moskito->pos().toStdString(), "93#93#0#1");
    vergl_bool->comp("getEthernet() (+ setEthernet(bool))",moskito->getEthernet(), true);
    vergl_bool->comp("setEthernet(bool) (only return)",moskito->setEthernet(true), true);
    QTest::qSleep(7000);
    vergl_bool->comp("getEthernet() (+ setEthernet(bool))",moskito->getEthernet(), true);
    vergl_bool->comp("setEthernet(bool) (only return)",moskito->setEthernet(false), true);
    QTest::qSleep(5000);
    //vergl_qstring->comp("QString pos()",moskito->pos().toStdString(), "93#93#0#1");
    vergl_bool->comp("getEthernet() (+ setEthernet(bool))",moskito->getEthernet(), false);



    /* Testmodus */
    vergl_bool->comp("Initialisierung(Testmodus)", moskito_->init(), true);

    vergl_int->isAnyBug();

    return 0;
}
