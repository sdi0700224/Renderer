#include "mainwindow.h"
#include "dataimporter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DataImporter dataImporter(nullptr, "C:\\Users\\rouss\\Documents\\Qt Projects\\Renderer\\waveform-data.txt");

    if (!dataImporter.Import())
    {
        return EXIT_FAILURE;
    }

    return a.exec();
}
