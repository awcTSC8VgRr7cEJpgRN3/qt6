#include <QCoreApplication>
// #include <QTextStream>
// #include <QString>
// #include <QDebug>

#include <iostream>
#include <string>

void do_cpp()
{
    std::string name;
    std::cout << "Please enter your name: ";
    // std::getline(std::cin, name);
    std::cin >> name;
    std::cout << "Hello, " << name << std::endl;
}

void do_qt()
{
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    QString name;
    qout << "Please enter your name: ";
    qout.flush();
    // name = qin.readLine();
    qin >> name;
    qout << "Hello, " << name << "\n";
    qout.flush();
}

void do_mixed()
{
    QTextStream qin(stdin);
    QString name;
    qInfo() << "Please enter your name: ";
    qin >> name;
    qInfo() << "Hello, " << name << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // do_cpp();
    // do_qt();
    do_mixed();

    return a.exec();
}
