#ifndef KITTEN_H
#define KITTEN_H

#include <QObject>
#include <QDebug>

class Kitten : public QObject
{
    Q_OBJECT
public:
    explicit Kitten(QObject *parent = nullptr);
    ~Kitten();
    void run();
    void meow();

signals:

};

#endif // KITTEN_H
