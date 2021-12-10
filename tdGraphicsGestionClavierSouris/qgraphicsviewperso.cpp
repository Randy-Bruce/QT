#include "qgraphicsviewperso.h"
#include "widget.h"

QGraphicsViewPerso::QGraphicsViewPerso(QWidget *parent):QGraphicsView(parent)
{
    setMouseTracking(true);
    setAlignment(Qt::AlignLeft|Qt::AlignTop);
}

void QGraphicsViewPerso::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"dans event souris de la vue : "<<event->pos();
    emit positionSouris(event->pos());
}
