#include <QDebug>
#include <QThread>
#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "constructed" << QThread::currentThread();
}

Worker::~Worker()
{
    qInfo() << this << "deconstructed" << QThread::currentThread();
}

void Worker::run_aesthetic_fatigue_tempo()
{
    int i = 1;
    int interval = 1000;
    while (interval > 10)
    {
        qInfo() << QThread::currentThread() << "Shitty Trance Tempo" << QString::number(i);
        QThread::currentThread()->msleep(interval);
        i %= 8;
        if (!i) interval /= 2;
        ++i;
    }
    this->deleteLater(); // No parent kills, suicide please.
}
