/*
  Qt memory managment
  QScopedPointer
  QSharedPointer
  QT Smart pointers
  https://www.qt.io/blog/2009/08/25/count-with-me-how-many-smart-pointer-classes-does-qt-have
  C++ STD Smart Pointers along with boost are there as well, but see the article
*/

#include <QCoreApplication>
//#include <QScopedPointer>
//#include <QSharedPointer>
#include "test.h"

void finish(QSharedPointer<Test> ptr)
{
    ptr->message("QSharedPointer finished.");
}

void finish(std::shared_ptr<Test> ptr)
{
    ptr->message("std::shared_ptr finished.");
}

void work(QSharedPointer<Test> ptr)
{
    ptr->message("QSharedPointer working.");
}

void work(std::shared_ptr<Test> ptr)
{
    ptr->message("std::shared_ptr working.");
}

void step(QSharedPointer<Test> ptr)
{
    ptr->message("QSharedPointer stepping.");
    for (int i = 0; i < 3; ++i)
    {
        work(ptr);
    }
    finish(ptr);
}

void step(std::shared_ptr<Test> ptr)
{
    ptr->message("std::shared_ptr stepping.");
    for (int i = 0; i < 3; ++i)
    {
        work(ptr);
    }
    finish(ptr);
}

void testQScoped(Test* test)
{
    QScopedPointer<Test> ptr(test);
    ptr->message("QScopedPointer test.");
}

void testQShared(Test* test)
{
    QSharedPointer<Test> ptr(test);
    ptr->message("QSharedPointer test.");
    step(ptr);
}

void testUnique(Test* test)
{
    std::unique_ptr<Test> ptr(test);
    ptr->message("std::unique_ptr test.");
}

void testShared(Test* test)
{
    std::shared_ptr<Test> ptr(test);
    ptr->message("std::shared_ptr test.");
    step(ptr);
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    testQScoped(new Test());

    testQShared(new Test());

    testUnique(new Test());

    testShared(new Test());

    return 0;
}
