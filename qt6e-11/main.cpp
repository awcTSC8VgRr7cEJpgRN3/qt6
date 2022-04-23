/*
  QByteArray
  Best array ever :)
 */

#include <typeinfo>
#include <QCoreApplication>
//#include <QString>
//#include <QByteArray>
//#include <QDebug>

void stats(const QByteArray& data)
{
    qInfo() << &data << data;
    qInfo() << "Size" << data.size() << "Capacity" << data.capacity();
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    //--- Creating an array ---
    qInfo() << "Empty constructor";
    QByteArray data;
    stats(data);

    qInfo() << "8bit style constructor";
    data = QByteArray(QString("Hello").toLocal8Bit());
    stats(data);

    qInfo() << "Fill constructor";
    QByteArray buffer = QByteArray(4, '\x20');
    stats(buffer);

    qInfo() << "Char pointer constructor";
    data = QByteArray("Hello", 4);
    stats(data);

    //--- Sizing the array ---
    qInfo() << "Reserve buffer to 7 bytes";
    buffer.reserve(7);
    stats(buffer);

    qInfo() << "Resize buffer to 11 bytes";
    buffer.resize(11);
    stats(buffer);

    qInfo() << "Truncate buffer to 8 bytes";
    buffer.truncate(8);
    stats(buffer);

    qInfo() << "Re-resize buffer to 11 bytes";
    buffer.resize(11);
    stats(buffer);

    qInfo() << "Clear buffer";
    buffer.clear();
    stats(buffer);

    //--- Modifying the data ---
    qInfo() << "Fill 4 spaces to buffer";
    buffer.fill('\x20', 4);
    stats(buffer);

    qInfo() << "Append 5 chars to data";
    data.append("World");
    stats(data);

    qInfo() << "Insert a space to data";
    data.insert(4, "\x20");
    stats(data);

    qInfo() << "Replace Hell to wonderful";
    data.replace(0, 4, "Hello");
    stats(data);

    qInfo() << "Remove 6 chars of data";
    data.remove(5, 6);
    stats(data);

    //--- Reading the data ---
    qInfo() << "Hell is like a shadow";
    int first = data.indexOf("H");
    int last = data.lastIndexOf("l");
    qInfo() << data.mid(first, (last - first + 1));

    qInfo() << "Iterate each elephant";
    for(int i = 0; i < data.size(); ++i)
    {
        qInfo() << "At" << data.at(i) << "or" << data[i];
    }

    qInfo() << "Iterate with char";
    foreach(char c, data)
    {
        qInfo() << "Char" << c;
    }

    qInfo() << "Iterate with split";
    foreach(auto item, data.split(' '))
    {
        qInfo() << typeid(item).name() << item;
    }

    //--- Encoding the data ---
//    qInfo() << "Normal" << data;
//    qInfo() << "Repeat" << data.repeated(3);

//    data.append(QByteArray("\t\r\n"));
//    data.insert(0,QByteArray("          \t\t\t"));
//    qInfo() << "Trimmed" << data.trimmed();
//    qInfo() << "Actual" << data;
//    data = data.trimmed();
//    qInfo() << "Actual" << data;

//    QByteArray hex = data.toHex();
//    qInfo() << "Hex" << hex;
//    QByteArray from_hex = QByteArray::fromHex(hex);
//    qInfo() << "From Hex" << from_hex;

//    QByteArray base64 = data.toBase64();
//    qInfo() << "base64" << base64;
//    QByteArray from_base64 = QByteArray::fromBase64(base64);
//    qInfo() << "From base64" << from_base64;
}
