/*
 QList
 https://doc.qt.io/qt-6.0/qlistwidget.html
 https://www.qt.io/blog/qlist-changes-in-qt-6
 QList is a templated container
 QList is not a QObject
 QList and QVector are the same thing
 No more 2 gb limit
 QList will auto resize itself
 QObjects and pointers need to be cleaned up
*/

#include <QCoreApplication>
#include <QRandomGenerator64> // ???
//#include <QList>
//#include <QSharedPointer>
//#include <QDebug>
#include "test.h"

#define SmartTest QSharedPointer<Test>
#define SmartTestList QList<SmartTest>

SmartTestList getRandomTestList(QObject *parent = nullptr)
{
    SmartTestList list;

    for (int i = 0; i < QRandomGenerator::global()->bounded(1, 10); ++i)
    {
        QSharedPointer<Test> ptr(new Test(QRandomGenerator::global()->bounded(1, 100))); // Auto memory management
        //list.append(ptr);
        list << ptr;
        //if (!list.isEmpty())
        //{
            list.last()->setParent(parent);
        //}
    }

    return list;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //SmartTestList list = getRandomTestList();
    SmartTestList list = getRandomTestList(&a);

    qInfo() << list;

    // Same difference.
    qInfo() << "Length" << list.length();
    qInfo() << "Count" << list.count();
    qInfo() << "Size" << list.size();

    qInfo() << "List begin";
    for (int i = 0; i < list.length(); ++i)
    {
        qInfo() << i << "=" << *list.at(i) << "or" << *list[i];
    }
    qInfo() << "List end";

    qInfo() << "List begin";
    foreach (SmartTest ptr, list)
    {
        qInfo() << *ptr;
    }
    qInfo() << "List end";

    //direct mod

    //appending
    for (int i = 0; i < 5; ++i)
    {
        SmartTest ptr(new Test(255));
        list << ptr;
    }
    qInfo() << list;

    //Removing
    SmartTest ptr(new Test(255));
    list.removeAll(ptr); // No way, fuck off.
    qInfo() << list;

    //inserting
    for (int i = 0; i < 5; ++i)
    {
        SmartTest ptr(new Test(255));
        list.insert(list.size(), ptr);
    }
    qInfo() << list;

    //--- Searching ---
    int pos = list.indexOf(ptr); // No way, fuck off.
    do // No way, fuck off.
    { // No way, fuck off.
        qInfo() << ptr->getValue() << "At" << pos; // No way, fuck off.
        pos = list.indexOf(ptr, pos + 1); // No way, fuck off.
    } // No way, fuck off.
    while (pos > -1); // No way, fuck off.

    list = list.sliced(0, list.size() - 10);
    qInfo() << list;

    //Remove all
    qInfo() << "Clear";
    list.clear();
    qInfo() << "Size" << list.size();

    //return a.exec();
}
