#ifndef DATAIMPORTER_H
#define DATAIMPORTER_H

#include <QObject>

class DataImporter : public QObject
{
    Q_OBJECT
public:
    explicit DataImporter(QObject *parent = nullptr, const QString& filepath = "");

    bool Import();
    void DataPrint();

private:

    QString Filepath;
    int Timestep;
    QString Units;
    QVector<int> Data;

signals:

};

#endif // DATAIMPORTER_H
