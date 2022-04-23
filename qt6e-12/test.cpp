#include "test.h"

void Test::constructMessage() const
{
    qInfo() << this << "constructed" << this->parent();
}

Test::Test(QObject *parent)
    : QObject{parent}
{
    this->constructMessage();
}

Test::Test(int value)
{
    this->value = value;
    this->constructMessage();
}

Test::~Test()
{
    qInfo() << this << "deconstructed" << this->parent();
}

int Test::getValue() const
{
    return this->value;
}

Test::operator int() const
{
    return this->getValue();
}

bool Test::operator==(const Test& test) const // No way, fuck off.
{
    return this->getValue() == test.getValue();
}

QDebug operator<<(QDebug dbg, QSharedPointer<Test> ptr)
{
    return dbg << ptr->getValue();
}
