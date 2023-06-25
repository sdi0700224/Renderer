#ifndef DATAIMPORTER_H
#define DATAIMPORTER_H
#include <QObject>
#include <QString>
#include <QVector>

class DataImporter : public QObject
{
    Q_OBJECT
public:
    explicit DataImporter(QObject *parent = nullptr, const QString& filepath = "");
    bool Import();
    void DataPrint();
    QVector<int> GetData();

private:
    QString Filepath;
    int Timestep;
    QString Units;
    QVector<int> Data;

signals:

};

#endif // DATAIMPORTER_H
