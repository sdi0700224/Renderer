#ifndef DATARENDERER_H
#define DATARENDERER_H
#include <QGraphicsView>
#include <QVector>

class DataRenderer : public QWidget
{
    Q_OBJECT
public:
    explicit DataRenderer(QWidget *parent = nullptr);
    void SetData(const QVector<int>& data);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
     QVector<int> Data;

signals:

};

#endif // DATARENDERER_H
