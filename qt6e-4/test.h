#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    void dostuff(); // It doesn't matter if it's slot or not

public slots:

signals:
    void doany();

};

#endif // TEST_H
