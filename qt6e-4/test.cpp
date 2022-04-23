#include <QDebug> // Put it in source, good habit.
#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{

}
/*
void Test::doany()
{
    qInfo() << "doany";
    // Do what you connect to in main function so no code here.
}
*/
void Test::dostuff()
{
    qInfo() << "dostuff";
    emit doany();
}
