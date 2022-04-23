#ifndef CAT_H
#define CAT_H

#include <QObject>
#include <QDebug>
//#include <QMap>
//#include <QString>
//#include <QSharedPointer>

class Cat : public QObject
{
    Q_OBJECT

private:
    QString name_;
    int age_;
    void constructMessage() const;
public:
    explicit Cat(QObject *parent = nullptr);
    Cat(const QString&, int);
    ~Cat();
    void setName(const QString&);
    void setAge(int);
    QString getName() const;
    int getAge() const;
signals:

};

//class CatMap : public QMap<QString, QSharedPointer<Cat>>
//{
//public:
//    void insert(const QString&, Cat*);
//};

//--- Displaying a QMap
QDebug operator<<(QDebug, QSharedPointer<Cat>);

#endif // CAT_H
