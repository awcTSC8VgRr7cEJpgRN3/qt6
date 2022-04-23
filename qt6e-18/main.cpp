/*
    Do not change QDir::currentPath() in recursion,
    because of many functions depend on this static variable,
    such as QFileInfo::absoluteFilePath().
*/

#include <QCoreApplication>
#include <QDir>
//#include <QString>
//#include <QFileInfo>
//#include <QFileInfoList>

QString space_typo(int depth = 0)
{
    QString str;
    QString typo("\x20\x20\x20\x20");
    str.reserve(typo.size() * depth);
    for (int i = 0; i < depth; ++i)
    {
        str += typo;
    }
    return str;
}

//*** Current folder
void show_current()
{
    // Same difference.
    qInfo() << QDir::currentPath();

    QDir dir;
    qInfo() << dir.absolutePath();
}

//*** Listing current folder by default
void like_a_pwd(bool recursive = false, QString path = QDir::currentPath(), int depth = 0)
{
    QDir dir;

    //if (!dir.setCurrent(path))
    dir.setPath(path);
    if (!dir.exists())
    {
        qWarning() << space_typo(depth) + "The current directory does not exist." << path;
        return;
    }

    QFileInfoList list = dir.entryInfoList(QDir::Filter::NoDotAndDotDot | QDir::Filter::AllEntries);

    foreach (QFileInfo fi, list)
    {
        qInfo() << space_typo(depth) + "--------------------";
        qInfo() << space_typo(depth) + "Name" << fi.fileName();
        qInfo() << space_typo(depth) + "Path" << fi.filePath();
        qInfo() << space_typo(depth) + "Absolute" << fi.absoluteFilePath();
        qInfo() << space_typo(depth) + "Created" << fi.birthTime().toString();
        qInfo() << space_typo(depth) + "Modified" << fi.lastModified().toString();
        qInfo() << space_typo(depth) + "Size" << fi.size();
        qInfo() << space_typo(depth) + "Type" << (fi.isDir() ? "Dir" : "File");
        qInfo() << space_typo(depth) + "--------------------";

        if (recursive && fi.isDir()) like_a_pwd(recursive, fi.absoluteFilePath(), depth + 1);
        //if (recursive && fi.isDir()) like_a_pwd(recursive, path + "/" + fi.fileName(), depth + 1);
    }
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    show_current();

    //like_a_pwd();
    like_a_pwd(true);

    //*** Modifying
    QDir dir;
    QString ori("Verga");
    QString mod("Andas Valiendo Verga");
    if (dir.mkdir(ori))
    {
        qInfo() << "Making dir" << ori;
        if (dir.rename(ori, mod))
        {
            qInfo() << "Rename dir" << ori << "to" << mod;
            if (dir.exists(mod))
            {
                qInfo() << "Ready to remove dir" << mod;
                if (dir.rmdir(mod))
                {
                    qInfo() << "Remove dir" << mod;
                }
            }
        }
    }
}
