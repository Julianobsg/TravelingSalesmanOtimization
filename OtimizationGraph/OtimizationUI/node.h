#ifndef NODE_H
#define NODE_H


#include <QGraphicsItem>
class GraphWidget;
class Edge;

class Node : public QGraphicsItem
{
public:
    int id;
    Node(int id);
    void addEdge(Edge *edge);
    QList<Edge *> edges() const;

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

public slots:
private:
    QList<Edge *> edgeList;
};

#endif // NODE_H
