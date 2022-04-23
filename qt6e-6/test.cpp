#include <QDebug>
#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "constructed" << this->parent();
    //qInfo() << this << "constructed" << parent;

    for (QObject* child: this->children()) // C++11
    //foreach (QObject* child, this->children()) // Qt
    {
        qInfo() << this << "has a child" << child;
    }
}

Test::~Test()
{
    //qInfo() << this << "deconstructed" << parent();
    qInfo() << this << "deconstructed" << this->parent();

    for (QObject* child: this->children()) // C++11
    //foreach (QObject* child, this->children()) // Qt
    {
        qInfo() << this << "has a child" << child;
    }
}
