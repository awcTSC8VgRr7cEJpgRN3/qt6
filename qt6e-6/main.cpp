/*
  Qt memory managment
  Parent child relationship
*/

#include <QCoreApplication>
#include <QTimer>
//#include <QDebug>
#include <test.h>

Test* getTest(QObject *parent = nullptr)
{
    return new Test(parent); // If Test has parent, it will be released imo.
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer timer;
    timer.singleShot(3000, &a, QCoreApplication::quit); // Like a fine wine.

    Test* cat = getTest(&a);
    cat->setObjectName("cat");

    Test* fenix = getTest(cat);
    fenix->setObjectName("Fenix");

    Test* superfenix = getTest();
    superfenix->setParent(fenix);
    superfenix->setObjectName("Super Fenix");

    int value = a.exec();

    qInfo() << "Exit value:" << value;

    return value;
}
