#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>

QString loadQss(const QString& path)
{
    QFile file(path);
    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "Failed to open QSS:" << path;
        return "";
    }
    return file.readAll();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString style =
        loadQss("C:/Users/Jake1/Documents/CS Files/Qt/axisem3d_v1/styles/main.qss") +
        loadQss("C:/Users/Jake1/Documents/CS Files/Qt/axisem3d_v1/styles/button.qss");

    a.setStyleSheet(style);

    MainWindow w;
    w.show();

    return QCoreApplication::exec();
}