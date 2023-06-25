#include "mainwindow.h"
#include "dataimporter.h"
#include "datarenderer.h"
#include <QApplication>
#include <QDebug>
#include <QScrollArea>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (argc != 2)
    {
        qDebug() << "Arguments number should be 1";
        return EXIT_FAILURE;
    }

    DataImporter dataImporter(nullptr, argv[1]);
    if (!dataImporter.IsDataImported())
    {
        qDebug() << "Data could not be Imported from file";
        return EXIT_FAILURE;
    }




    DataRenderer* dataRenderer = new DataRenderer();
    dataRenderer->SetData(dataImporter.GetData(), dataImporter.GetUnits(), dataImporter.GetTimestep());

    MainWindow* mainWindow = new MainWindow(dataRenderer);
    mainWindow->show();

    return app.exec();
}
