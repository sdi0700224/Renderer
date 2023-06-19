#ifndef DATARENDERER_H
#define DATARENDERER_H
#include <QGraphicsView>
#include <QVector>

class DataRenderer : public QGraphicsView
{
    Q_OBJECT
public:
    explicit DataRenderer(QGraphicsView *parent = nullptr);

    void SetData(const QVector<int> data);
    void SetZoomLevel(int level);

protected:
    void paintEvent(QPaintEvent* event) override;

private:

     QVector<int> Data;
     int ZoomLevel;

     int DetailLevel() const;

signals:

};

#endif // DATARENDERER_H
