/*
 QTextStream
 Viewer request: please show the Qt way of doing user input and output
 Facebook group: voidrealms
 */

#include <QCoreApplication>
//#include <QTextStream>

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    //--- QTextStream
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    //--- endl
    qout << "Please enter your age, please:" << Qt::endl;
    bool valid;
    //---Reading
    int age = qin.readLine().toInt(&valid);
    if (valid) qout << "You are " << age << " year(s) old but not too old maybe.";
    else qout << "Not a digit.";
    //--- Flushing
    qout.flush();
}
