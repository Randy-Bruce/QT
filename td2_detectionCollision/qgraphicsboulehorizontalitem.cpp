#include "qgraphicsboulehorizontalitem.h"

QGraphicsBouleHorizontalItem::QGraphicsBouleHorizontalItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
    QGraphicsEllipseItem(x,y,width,height,parent),dx(2),dy(2) // dy =  boule n'importe ou
{

}

void QGraphicsBouleHorizontalItem::advance(int step)
{
    moveBy(dx,dy);   // dy = boule n'importe ou
    qreal largeurBoule=rect().width();
    qreal hauteurBoule=rect().height();
    qreal largeurScene=scene()->width();
    qreal hauteurScene=scene()->height();
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

    // dy =  boule n'importe ou
    // boule arrive sur bord haut
    if(y()<=2)
    {
        dy=2;
    }
    //boule arrive sur bord bas
    if(y()>=(hauteurScene-hauteurBoule))
    {
        dy=-2;
    }

}
