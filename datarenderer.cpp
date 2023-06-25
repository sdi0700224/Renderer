#include "datarenderer.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>

DataRenderer::DataRenderer(QWidget *parent) : QWidget(parent)
{
}

void DataRenderer::SetData(const QVector<int>& data)
{
    Data = data;
    update();
}

void DataRenderer::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.fillRect(this->rect(), Qt::black);

    if (!Data.isEmpty())
    {
        int middleY = this->height() / 2;
        int rectHeight = 50;
        int rectWidth = 10;
        int lineWidth = 2;

        for (int i = 0; i < Data.size(); ++i)
        {
            painter.setRenderHint(QPainter::Antialiasing);

            if (Data[i] > 0)
            {
                QPen pen(Qt::darkGreen);
                painter.setPen(pen);
                painter.setBrush(Qt::darkGreen);
                painter.drawRect(i * rectWidth, middleY - rectHeight, rectWidth, rectHeight);
            }


            QPen pen(Qt::darkGreen);
            pen.setWidth(2);
            painter.setPen(pen);
            painter.setBrush(Qt::NoBrush);
            painter.drawLine(i * rectWidth, middleY, (i * rectWidth) + rectWidth, middleY);

        }
    }
    QWidget::paintEvent(event);
}
