#include "dataimporter.h"
#include <QDebug>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

DataImporter::DataImporter(QObject *parent, const QString& filepath) : QObject(parent)
{
    Filepath = filepath;
    Timestep = -1;
    ImportData();
}

bool DataImporter::ImportData()
{
    Data.clear();
    fstream dataFile;

    dataFile.open(Filepath.toStdString(), ios::in);
    if (dataFile.is_open())
    {
        string tp;
        while(getline(dataFile, tp))
        {
            QString line = QString::fromStdString(tp);
            if (line.contains("TIMESTEP", Qt::CaseInsensitive))
            {
                Timestep = line.split(';')[1].toInt();
            }
            else if (line.contains("UNITS", Qt::CaseInsensitive))
            {
                Units = line.split(';')[1];
            }
            else if (line.contains("DATA", Qt::CaseInsensitive))
            {
                continue;
            }
            else
            {
                Data.push_back(line.split(';')[0].toInt());
            }
        }
        dataFile.close();

        if (Timestep < 1 || Units.size() == 0 || Data.count() == 0)
        {
            qDebug() << "File is not in proper format";
            return false;
        }

        return true;
    }
    else
    {
        qDebug() << "File not found or could not be opened";
        return false;
    }
}

void DataImporter::PrintData()
{
    for (int i = 0; i < Data.count(); i++)
    {
        qDebug() << Data[i];
    }
}

QVector<int> DataImporter::GetData()
{
    return Data;
}

QString DataImporter::GetUnits()
{
    return Units;
}

int DataImporter::GetTimestep()
{
    return Timestep;
}

bool DataImporter::IsDataImported()
{
    return Data.count() > 0 && Units.count() > 0 && Timestep > 0;
}
