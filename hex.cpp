#include "hex.h"

Hex::Hex(QGraphicsItem *parent)
{
    // draw the polygon
    // Point: (1,0), (2,0), (3,1), (2,2), (1,2), (0,1)
    QVector <QPointF> hexPoints;
    hexPoints << QPointF(1,0)
              << QPointF(2,0)
              << QPointF(3,1)
              << QPointF(2,2)
              << QPointF(1,2)
              << QPointF(0,1);

    // Scale the polygon
    int SCALE_BY = 40;
    for (int i = 0; i < 6; ++i)
        hexPoints[i] *= SCALE_BY;

    // create a polygon with the scaled points
    QPolygonF hexagon(hexPoints);

    // draw the poly
    setPolygon(hexagon);

}
