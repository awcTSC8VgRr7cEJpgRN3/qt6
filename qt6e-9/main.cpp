#include <QCoreApplication>
//#include <QDebug>
//#include <QStringList>
//#include <QString>
//#include <QChar>
#include <iostream>

// --------------------------- Maybe it's best to use the same template --------------------------- //

void printEachChar(QString str) // QString is not QObject and can be copied, but no copy due to Implicit Sharing in fact.
{
    qInfo() << "Reading each char:";
    foreach (QChar c, str)
    {
        qInfo() << c;
    }
}

void printStringList(QStringList list) // QStringList is not QObject and can be copied, but no copy due to Implicit Sharing in fact.
{
    qInfo() << "Reading string list:";
    foreach (QString str, list)
    {
        qInfo() << str.trimmed();
    }
}

// --------------------------- Maybe it's best to use the same template --------------------------- //

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    QString hello("Hello World."); // QString::QString(const char *str)
    qInfo() << hello;
    hello = "Hell World?"; // QString &QString::operator=(const char *str)
    qInfo() << hello;
    hello = QString("Hello World!"); // QString &QString::operator=(const QString &other)
    qInfo() << hello;

    qInfo() << "Compare" << hello.compare("hello world!", Qt::CaseSensitivity::CaseInsensitive);
    qInfo() << "Starts" << hello.startsWith("hello", Qt::CaseInsensitive);
    qInfo() << "Ends" << hello.endsWith("world!", Qt::CaseSensitivity::CaseSensitive);
    qInfo() << "Contains" << hello.contains("hell", Qt::CaseSensitive);
    qInfo() << "Index" << hello.indexOf('l');

    printEachChar(hello);

    int pos = 99;
    int max = 100;
    hello.append(QString("\r\nProcessing file %1 of %2.").arg(pos).arg(max));
    qInfo() << "Escape" << hello;

    hello += "\r\n<i>Warning: </i>99% processing forever.<br>"; // QString &QString::operator+=(const char *str)
    qInfo() << "Html" << hello.toHtmlEscaped();

    hello.replace("World", "ザ・ワールド");
    qInfo() << "Replaced" << hello;

    qInfo() << "Upper" << hello.toUpper();
    qInfo() << "Lower" << hello.toLower();
    qInfo() << "Mid" << hello.mid(6, 7);

    QStringList list = hello.split("\n");
    printStringList(list);

    std::cout << "std" << std::endl << hello.toStdString() << std::endl;

    qInfo() << "UTF-8" << hello.toUtf8();
    qInfo() << "UTF-8 hex" << hello.toUtf8().toHex();
    qInfo() << "Base64" << hello.toUtf8().toBase64();
    qInfo() << "Base64 hex" << hello.toUtf8().toBase64().toHex();

    //return 0;
}
