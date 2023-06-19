#include "mainwindow.h"
#include "dataimporter.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    if (argc != 2)
    {
        qDebug() << "Arguments number should be 1";
        return EXIT_FAILURE;
    }

    DataImporter dataImporter(nullptr, argv[1]);

    if (!dataImporter.Import())
    {
        qDebug() << "Data could not be Imported from file";
        return EXIT_FAILURE;
    }

    return a.exec();
}
