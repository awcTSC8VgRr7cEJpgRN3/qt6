/*
  What
  Reading and writing text files
  Why
  We want to make plain text files
  How
  QFile and QTextStream
 */

#include <QCoreApplication>
#include <QFile>
//#include <QTextStream>

bool createFile(QString filename)
{
    QFile file(filename);
    if (file.exists()) return true;
    if (!file.open(QIODevice::WriteOnly))
    {
        qCritical() << "Could not open file!";
        qCritical() << file.errorString();
        return false;
    }
    file.close();
    return true;
}

bool writeFile(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
    {
        qCritical() << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    for (int i = 0; i < 5; ++i)
    {
        stream << QString::number(i) << " Hello World\n";
    }
    //file.flush();
    file.close();
    return true;
}

bool readFile(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        qCritical() << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    //QString data = stream.readAll();
    while (!stream.atEnd())
    {
        qInfo() << stream.readLine();
    }
    //file.flush();
    file.close();
    return true;
}

bool deleteFile(QString filename)
{
    QFile file(filename);
    if (!file.exists())
    {
        return true;
    }
    if (!file.remove())
    {
        return false;
    }
    //file.close();
    return true;
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    if (!createFile("test.txt")) return 3345678;
    if (!writeFile("test.txt")) return 3345679;
    if (!readFile("test.txt")) return 3345680;
    if (!deleteFile("test.txt")) return 3345681;
}
