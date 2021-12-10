#include "qgraphicsballecollisionitem.h"
#include <QtMath>
#include <QFileDialog>

QGraphicsBalleCollisionItem::QGraphicsBalleCollisionItem(qreal x, qreal y, qreal width, qreal height,QGraphicsRectItem *_raquette, QGraphicsItem *parent):
    QGraphicsEllipseItem(x,y,width,height,parent),raquette(_raquette),dx(2),dy(2)
{
      nomFichier = QFileDialog::getOpenFileName();
}

void QGraphicsBalleCollisionItem::advance(int step)
{
    moveBy(dx,dy);  // deplacement de dx pixel horizontalement
    qreal largeurBoule=rect().width();
    qreal largeurScene=scene()->width();
    qreal hauteurScene=scene()->height();

    // boule arrive sur bord gauche ou droit on inverse le sens horizontal
    if(x()<=qFabs(dx) || x()>=(largeurScene-largeurBoule))
    {
        dx=-dx;
    }
    if(y()<=qFabs(dy) || y()>=(hauteurScene-largeurBoule))
    {
        dy=-dy;
    }

    // gestion des collisions
    QList<QGraphicsItem*> listeDesObjetsEnCollisions=this->collidingItems();
    if (listeDesObjetsEnCollisions.count()>0)
    {
        foreach (QGraphicsItem *objet, listeDesObjetsEnCollisions) {
            // si l'objet n'est pas la raquette,le supprimer de la scene
            // et inverser la trajectoire de la balle
            if (objet!=raquette)
            {
                scene()->removeItem(objet);
                dx=-dx;
                dy=-dy;
                player.setMedia(QUrl::fromLocalFile(nomFichier));
                player.setVolume(100);
                player.play();
            }
            else        // si c'est la raquette, change le sens de la balle
            {
                dy=-dy;
            }
        }
    }
}
