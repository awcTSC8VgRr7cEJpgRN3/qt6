/*
 Intercepting QDebug
 https://doc-snapshots.qt.io/qt6-dev/qtglobal.html
 Message types
 https://doc-snapshots.qt.io/qt6-dev/qtglobal.html#QtMsgType-enum
 QtMessageHandler is a typedef
 https://doc-snapshots.qt.io/qt6-dev/qtglobal.html#QtMessageHandler-typedef
 qInstallMessageHandler installs the handler
 https://doc-snapshots.qt.io/qt6-dev/qtglobal.html#qInstallMessageHandler
 */

#include <QCoreApplication>
//#include <QDebug>
//#include <QTextStream>
#include "kitten.h"

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    }
}

void test(Kitten& kitty)
{
    kitty.run();

    qDebug("Debug message.");
    qInfo("Info message.");

    qWarning() << "Warning message.";
    qCritical() << "Critical message.";
}

void testFatal(Kitten& kitty)
{
    kitty.meow();

    qFatal("Fatal message.");
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    //--- Setup (and copy the code)
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    qout << "Starting" << Qt::endl;

    Kitten mochi;
    bool running = true;
    do
    {
        qout << "Enter a command (start, stop, test, testfatal, or exit)" << Qt::endl;
        QString command = qin.readLine();
        qInfo() << "You entered:" << command;

        //--- Install
        if(command.toUpper() == "START") qInstallMessageHandler(myMessageOutput);

        //--- Uninstall
        else if(command.toUpper() == "STOP") qInstallMessageHandler(0);

        //--- Test
        else if(command.toUpper() == "TEST") test(mochi);
        else if(command.toUpper() == "TESTFATAL") testFatal(mochi);

        //--- Exit the loop
        else if(command.toUpper() == "EXIT") running = false;

        else qWarning() << "Excuse me, sir. What da invalid comando.";
    }
    while (running);

    qout << "Finished" << Qt::endl;
}
