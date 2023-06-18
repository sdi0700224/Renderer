#ifndef DATAIMPORTER_H
#define DATAIMPORTER_H

#include <QObject>

class DataImporter : public QObject
{
    Q_OBJECT
public:
    explicit DataImporter(QObject *parent = nullptr, const QString& filepath = "");

    void Import();

private:

    QString Filepath;

signals:

};

#endif // DATAIMPORTER_H
