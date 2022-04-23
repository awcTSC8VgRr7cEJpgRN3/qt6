#include "cat.h"

void Cat::constructMessage() const
{
    qInfo() << this << "constructed" << this->getName() << this->getAge();
}

Cat::Cat(QObject *parent)
    : QObject{parent}
{
    this->constructMessage();
}

Cat::Cat(const QString & name, int age)
{
    this->setName(name);
    this->setAge(age);
    this->constructMessage();
}

Cat::~Cat()
{
    qInfo() << this << "deconstructed" << this->getName() << this->getAge();
}

void Cat::setName(const QString& name)
{
    this->name_ = name;
}

void Cat::setAge(int age)
{
    this->age_ = age;
}

QString Cat::getName() const
{
    return this->name_;
}

int Cat::getAge() const
{
    return this->age_;
}

QDebug operator<<(QDebug dbg, QSharedPointer<Cat> ptr)
{
    return dbg << ptr->getName() << ptr->getAge() << "year(s)";
}
