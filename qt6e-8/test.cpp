#include <QDebug>
#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    //qInfo() << this << "constructed" << this->parent();
    qInfo() << this << "constructed" << parent;
}

Test::~Test()
{
    qInfo() << this << "deconstructed" << this->parent();
}

void Test::message(QString str)
{
    qInfo() << str;
}
