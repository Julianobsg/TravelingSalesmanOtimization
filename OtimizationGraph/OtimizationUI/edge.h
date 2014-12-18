#include <qgraphicsitem.h>
#ifndef EDGE_H
#define EDGE_H

class Node;

class Edge: public QGraphicsItem
{
public:
    Edge(Node *sourceNode, Node *destNode);

    Node *sourceNode() const;
    Node *destNode() const;

    void adjust();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    Node *source, *dest;

    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
};

#endif // EDGE_H
