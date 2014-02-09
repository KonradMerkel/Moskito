#define DEBUGING  0
#define PORT "/dev/ttyACM0"
#include <QCoreApplication>
#include <QtTest/QtTest>
#include <iostream>
#include "../../../lib/Kom_Moskito.h"
#include "../../../lib/test.h"

using namespace std;
int alpha =0;
int beta = 0;
Kom_Moskito *moskito = new Kom_Moskito;
Test<int> *vergl_int = new Test<int>;


void check_Pos(){
    int alpha_, beta_;
    for(int i=0; i< 100; i++){
        if (moskito->pos(alpha_, beta_))
            break;
        QTest::qWait(200);
    }
    vergl_int->comp("Alpha", alpha_, alpha);
    vergl_int->comp("Beta", beta_, beta);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    moskito = new Kom_Moskito;
    vergl_int = new Test<int>;
    moskito->init(PORT);
    QTest::qSleep(3000);
    moskito->aim_deg(0, 0);
    QTest::qSleep(1000);


    for (int i=0; i<50; i++){
        alpha = qrand()%180;
        beta = qrand()%180;
        moskito->aim_deg(alpha, beta);
        QTest::qWait(500);
        check_Pos();
    }
    for (int i=0; i<50; i++){
        alpha = qrand()%90;
        beta = qrand()%90;
        moskito->aim_deg(alpha, beta, 3);
        QTest::qWait(500);
        check_Pos();
    }
    for (int i=0; i<50; i++){
        alpha = qrand()%90+90;
        beta = qrand()%90+90;
        moskito->aim_deg(alpha, beta);
        QTest::qWait(500);
        check_Pos();
    }

    vergl_int->isAnyBug();

    return 0;
}
