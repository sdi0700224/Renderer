#include "datarenderer.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>

DataRenderer::DataRenderer(QWidget *parent) : QWidget(parent)
{
}

void DataRenderer::SetData(const QVector<int>& data, const QString& units, int timestep)
{
    Data = data;
    Units = units;
    Timestep = timestep;
    updateGeometry();
    update();
}

void DataRenderer::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.fillRect(this->rect(), Qt::black);

    if (!Data.isEmpty())
    {
        int middleY = this->height() / 2;
        int rectHeight = 100;
        int rectWidth = 10;
        int lineWidth = 2;

        for (int i = 0; i < Data.size(); ++i)
        {
            painter.setRenderHint(QPainter::Antialiasing);
            QPen pen(Qt::darkGreen);
            pen.setWidth(lineWidth);
            painter.setPen(pen);

            if (Data[i] > 0)
            {
                painter.drawLine(i * rectWidth, middleY - rectHeight, (i * rectWidth) + rectWidth, middleY - rectHeight);
            }
            else
            {
                painter.drawLine(i * rectWidth, middleY, (i * rectWidth) + rectWidth, middleY);
            }

            if (i - 1 > 0 && Data[i] != Data[i - 1])
            {
                painter.drawLine(i * rectWidth, middleY, i * rectWidth, middleY - rectHeight);
            }

            if (i % 10 == 0)
            {
                painter.setPen(Qt::white);
                painter.drawText(QPointF(i * rectWidth, middleY + 20), QString::number(i * Timestep).append(Units));
                painter.setPen(pen);
            }
        }
    }
    QWidget::paintEvent(event);
}

QSize DataRenderer::sizeHint() const
{
    int rectWidth = 10;
    int width = Data.size() * rectWidth;
    int height = this->height();
    return QSize(width, height);
}
