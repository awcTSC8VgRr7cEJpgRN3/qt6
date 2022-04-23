/*
    QStringView
    https://doc.qt.io/qt-5/qstringview.html#details
    A QStringView references a contiguous portion of a UTF-16 string it does not own.
    It acts as an interface type to all kinds of UTF-16 string, without the
    need to construct a QString first.
    Why: Its faster than copying a QString, and its read only!
 */

#include <QCoreApplication>
//#include <QString>
//#include <QStringView>
//#include <QDebug>
#include <QRegularExpression>

void readString(QString str)
{
    str.insert(0, "String: ");
    qInfo() << str << str.data();
}

void readOnlyString(const QString& str)
{
    qInfo() << str << str.data();
}

void readStringView(QStringView str)
{
    qInfo() << str << str.data();
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    char charHead = 'A';
    char charTail = 'Z';
    QString str;
    str.reserve(charTail - charHead);
    for (char c = charHead; c <= charTail; c++) // C++
    {
        str += QChar(c);
    }

    //---Read only, no copy
    readString(str);
    readOnlyString(str);
    readStringView(str);
    qInfo() << "Original" << str << str.data();

    //--- Basic parsing
    foreach (QStringView part, QStringView(str).split(QRegularExpression("[AEIOUaeiou]"), Qt::SkipEmptyParts))
    {
        //readStringView(part.mid(0, 1));
        readStringView(part.sliced(0, 1));
    }
}
