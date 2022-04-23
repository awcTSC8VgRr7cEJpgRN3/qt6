/*
  QMap
  key and value pairs
 */

#include <QCoreApplication>
#include <QRandomGenerator64> // ???
//#include <QMap>
//#include <QDebug>
//#include <QSharedPointer>
#include "cat.h"

#define SmartCat QSharedPointer<Cat>
#define SmartCatMap QMap<QString, SmartCat>

//--- Adding and inserting
void addCat(SmartCatMap& cats, const QString& name, int age)
{
    QString keyPrefix = "pet";
    int keySerial;
    do keySerial = QRandomGenerator::global()->bounded(100, 999);
    while (cats.contains(keyPrefix + QString::number(keySerial)));
    SmartCat ptr(new Cat(name, age));
    //cats[keyPrefix + QString::number(keySerial)] = ptr;
    cats.insert(keyPrefix + QString::number(keySerial), ptr);
    //cats.insert("pet" + QString::number(i), new Cat("Unknown", QRandomGenerator::global()->bounded(1, 5)));
}

template <typename Key, typename T>
Key randomPickMapKey(const QMap<Key, T>& map)
{
    typename QMap<Key, T>::key_iterator iterator = map.keyBegin();
    for (int i = 0; i < QRandomGenerator::global()->bounded(map.size()); ++i)
    {
        ++iterator;
    }
    return *iterator;
}

//--- Creating a QMap
SmartCatMap getCatMap()
{
    SmartCatMap cats;
    for (int i = 0; i < 5; ++i)
    {
        //SmartCat ptr(new Cat());
        //ptr->setName("Unknown");
        //ptr->setAge(QRandomGenerator::global()->bounded(1, 5));
        addCat(cats, "Unknown", QRandomGenerator::global()->bounded(1, 5));
    }
    return cats;
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    qInfo() << "Create cats";
    SmartCatMap cats = getCatMap();
    qInfo() << cats;

    // Pick 'n' Mod
    qInfo() << "Randomly pick a cat and modify";
    QString key = randomPickMapKey(cats);
    cats[key]->setName("Fluffy");
    cats[key]->setAge(99);
    qInfo() << cats;

    //--- Removing an item
    qInfo() << "Randomly remove cats iteratively";
    while (!cats.isEmpty())
    {
        cats.remove(randomPickMapKey(cats));
        qInfo() << cats;
    }
}
