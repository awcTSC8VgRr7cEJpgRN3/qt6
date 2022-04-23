#include "kitten.h"

Kitten::Kitten(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "constructed" << this->parent();
}

Kitten::~Kitten()
{
    qInfo() << this << "deconstructed" << this->parent();
}

void Kitten::run()
{
    qWarning() << "I am running.";
}

void Kitten::meow()
{
    qWarning() << "I am hungerian.";
}
