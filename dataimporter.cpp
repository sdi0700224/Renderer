#include "dataimporter.h"
#include <QDebug>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

DataImporter::DataImporter(QObject *parent, const QString& filepath) : QObject(parent)
{
    Filepath = filepath;
}

void DataImporter::Import()
{
    fstream dataFile;

    dataFile.open(Filepath.toStdString(), ios::in);
    if (dataFile.is_open())
    {
        string tp;
        while(getline(dataFile, tp))
        {
            cout << tp << endl;
        }
        dataFile.close();
    }
}
