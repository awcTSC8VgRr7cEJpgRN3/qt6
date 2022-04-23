#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT

private:
    int value;
    void constructMessage() const;

public:
    explicit Test(QObject *parent = nullptr);
    Test(int);
    ~Test();

    int getValue() const;
    operator int() const;
    bool operator==(const Test&) const; // No way, fuck off.

signals:

};

QDebug operator<<(QDebug, QSharedPointer<Test>);

#endif // TEST_H
