#include <QGraphicsView>
#include <qmath.h>

#include "../OtimizationGraph/SalesmanGraph.h"
#ifndef GRAPH_H
#define GRAPH_H
class Node;

class GraphWidget : public QGraphicsView
{
public:
    GraphWidget(QWidget *parent = 0);
    void LoadFile(QString filename);

protected:
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
#ifndef QT_NO_WHEELEVENT
    void wheelEvent(QWheelEvent *event);
#endif
    void drawBackground(QPainter *painter, const QRectF &rect);

    void scaleView(qreal scaleFactor);
private:
    int timerId;
    void GenerateNodes(SalesmanGraph *sGraph);
    void GenerateEdges(SalesmanGraph* sGraph);
    QGraphicsScene *scene;
    QList<Node*> nodes;
};

#endif // GRAPH_H
