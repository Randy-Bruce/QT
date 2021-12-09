#include "qgraohphicsboulehorizontalitem.h"

QGraohphicsBouleHorizontalItem::QGraohphicsBouleHorizontalItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
    QGraphicsEllipseItem(x,y,width,height,parent),dx(2)
{

}

void QGraohphicsBouleHorizontalItem::advance(int step)
{
    moveBy(dx,0);
    qreal largeurBoule=rect().width();
    qreal largeurScene=scene()->width();
    // boule arrive sur bord gauche, on avance
    if(x()<=2)
    {
        dx=2;
    }
    //boule arrive sur bord droit, on recule
    if(x()>=(largeurScene-largeurBoule))
    {
        dx=-2;
    }

}
