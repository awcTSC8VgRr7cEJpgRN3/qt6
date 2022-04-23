#include <QCoreApplication>
//#include <QDebug>
#include <test.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;

    // Connect the signal and the slot.
    //QObject::connect(&test, &Test::doany, &a, &QCoreApplication::quit, Qt::QueuedConnection);
    test.connect(&test, &Test::doany, &a, &QCoreApplication::quit, Qt::QueuedConnection);
    test.connect(&test, SIGNAL(doany()), &a, SLOT(quit()), Qt::QueuedConnection);

    test.dostuff();

    int value = a.exec();

    qInfo() << "Exit value:" << value;

    return value;
}
