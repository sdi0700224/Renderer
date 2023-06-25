#ifndef DATARENDERER_H
#define DATARENDERER_H
#include <QGraphicsView>
#include <QVector>
#include "dataimporter.h"

class DataRenderer : public QWidget
{
    Q_OBJECT
public:
    explicit DataRenderer(QWidget *parent = nullptr);
    void SetData(const QVector<int>& data, const QString& units, int timestep);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
     QVector<int> Data;
     QString Units;
     int Timestep;

signals:

};

#endif // DATARENDERER_H
