#include "mainwindow.h"
#include "dataimporter.h"
#include "datarenderer.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;

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
    QVector<int> data = dataImporter.GetData();

    DataRenderer dataRenderer;
    dataRenderer.SetData(data);

    mainWindow.setCentralWidget(&dataRenderer);
    mainWindow.show();

    return app.exec();
}
