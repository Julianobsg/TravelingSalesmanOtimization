#include "graphwidget.h"
#include "node.h"
#include "edge.h"
static const double Pi = 3.14159265358979323846264338327950288419717;

#include "../OtimizationGraph/TravelingSalesmanSimplex.h"


GraphWidget::GraphWidget(QWidget *parent) : QGraphicsView(parent), timerId(0)
{
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -200, 600, 400);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(400, 400);
    setWindowTitle(tr("Traveling Salesman graph"));
}

void GraphWidget::keyPressEvent(QKeyEvent *event)
{

}

void GraphWidget::timerEvent(QTimerEvent *event)
{

}

void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect)
{

    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
        painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
        painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);

    // Text
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                    sceneRect.width() - 4, sceneRect.height() - 4);
  //  QString message(tr("Click and drag the nodes around, and zoom with the mouse "
   //                    "wheel or the '+' and '-' keys"));

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
    painter->setPen(Qt::lightGray);
   // painter->drawText(textRect.translated(2, 2), message);
    painter->setPen(Qt::black);
   // painter->drawText(textRect, message);


}
//! [4]

#ifndef QT_NO_WHEELEVENT
//! [5]
void GraphWidget::wheelEvent(QWheelEvent *event)
{
}
//! [5]
#endif

void GraphWidget::scaleView(qreal scaleFactor)
{

}

void GraphWidget::LoadFile(QString filename)
{
    TravelingSalesmanSimplex* tss = new TravelingSalesmanSimplex(filename.toLocal8Bit().data());
    tss->Solve();
    SalesmanGraph* sGraph = tss->CreateGraph();
    GenerateNodes(sGraph);
    GenerateEdges(sGraph);
    free(tss);
    free(sGraph);
}

void GraphWidget::GenerateNodes(SalesmanGraph* sGraph)
{
    int size = sGraph->size;
   // SNodes* sNodes = sGraph->nodes;
    int radius = 100;
    double circ = 2 * Pi;
    double arcAngle = circ / size;

    for (int i = 0; i < size; ++i) {
        Node *node = new Node(i);
        scene->addItem(node);
        node->setPos( qSin(i * arcAngle) * radius, qCos(i * arcAngle) * radius);
        nodes << node;
    }
}

void GraphWidget::GenerateEdges(SalesmanGraph* sGraph)
{
    SNodes* sNodes = sGraph->nodes;
    for (int i = 0; i < sGraph->size; ++i) {
        int source = sNodes[i].id;
        int destiny = sNodes[i].edge->id;
        Edge *edge = new Edge(nodes[source], nodes[destiny]);
        scene->addItem(edge);
    }
}


