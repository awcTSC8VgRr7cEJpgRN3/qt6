#ifndef TEST_H
#define TEST_H

#include <QObject>
//#include <QString>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    ~Test();
    void message(QString str);
signals:

};

#endif // TEST_H
