/*
Threaded Exmaple
Create a QThread
Move a class to it
Can not have a parent!
*/

#include <QCoreApplication>
#include <QThread>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    QThread thread1(QThread::currentThread());
    thread1.setObjectName("Worker Thread 1");
    QThread thread2(QThread::currentThread());
    thread2.setObjectName("Worker Thread 2");

    Worker* worker1 = new Worker(/* No parent kills, suicide please. */);
    Worker* worker2 = new Worker(/* No parent kills, suicide please. */);

    worker1->moveToThread(&thread1);
    worker2->moveToThread(&thread2);

    QObject::connect(&thread1, &QThread::started, worker1, &Worker::run_aesthetic_fatigue_tempo);
    QObject::connect(&thread2, &QThread::started, worker2, &Worker::run_aesthetic_fatigue_tempo);

    thread1.start();
    QThread::currentThread()->msleep(16000);
    thread2.start();

    return a.exec();
}
