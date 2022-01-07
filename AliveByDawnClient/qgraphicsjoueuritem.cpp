#include "qgraphicsjoueuritem.h"
#include <QtMath>


QGraphicsJoueurItem::QGraphicsJoueurItem(const QPolygonF &polygon, QString _nom,int _pv,int _attaque,int _defense,QGraphicsItem *parent):
    QGraphicsPolygonItem(polygon,parent),
    nom(_nom), pv(_pv), attaque(_attaque), defense(_defense)
{

    monster = false;
    isJoueur = false;
}

bool QGraphicsJoueurItem::getMonster() const
{
    return monster;
}

void QGraphicsJoueurItem::setMonster(bool value)
{
    monster = value;
}

bool QGraphicsJoueurItem::getIsJoueur() const
{
    return isJoueur;
}

void QGraphicsJoueurItem::setIsJoueur(bool value)
{
    isJoueur = value;
}



