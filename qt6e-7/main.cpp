/*
  Qt memory managment
  qDeleteall
  Note the STL functions starting with Qt 5
  https://doc.qt.io/archives/qt-5.9/qtalgorithms.html#qDeleteAll
*/

#include <QCoreApplication>
//#include <QString>
//#include <QList>
//#include <QDebug>
#include "test.h"

typedef QList<Test*> testlist; // QObject can not be copied.

testlist getTestList(int index)
{
    testlist list;
    for (int i = 0; i < index; ++i)
    {
        list.append(new Test()); // QObject without parent.
        // The item being appended must be last, better than "list.at(i)".
        list.last()->setObjectName("Test" + QString::number(i)); // Dummy.
    }
    return list; // QList can be copied.
}

void displayTestList(testlist list) // QList can be copied.
{
    qInfo() << "Display testlist begin.";

    //for (Test* item: list)
    foreach (Test* item, list)
    {
        qInfo() << item;
    }

    qInfo() << "Display testlist end.";
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    testlist list = getTestList(5);

    displayTestList(list);

    // Release QObject without parent manually.
/*
    //for (Test* item: list)
    foreach (Test* item, list)
    {
        delete item;
    }
*/
    //qDeleteAll(list);
    qDeleteAll(list.begin(), list.end());

    //displayTestList(list); // exit with non-zero code.

    list.clear();

    displayTestList(list);

    return 0;
}
