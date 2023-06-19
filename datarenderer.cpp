#include "datarenderer.h"

DataRenderer::DataRenderer(QGraphicsView *parent) : QGraphicsView(parent)
{

}

void DataRenderer::SetData(const QVector<int> data)
{
    Data = data;
}

void DataRenderer::SetZoomLevel(int level)
{
    ZoomLevel = level;
}

void DataRenderer::paintEvent(QPaintEvent* event)
{

}

int DataRenderer::DetailLevel() const
{

}
