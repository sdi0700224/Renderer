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

    MainWindow* mainWindow = new MainWindow();

    QScrollArea* scrollArea = new QScrollArea(mainWindow);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    DataRenderer* dataRenderer = new DataRenderer();
    dataRenderer->SetData(dataImporter.GetData(), dataImporter.GetUnits(), dataImporter.GetTimestep());

    scrollArea->setWidget(dataRenderer);

    mainWindow->setCentralWidget(scrollArea);
    mainWindow->show();

    return app.exec();
}
