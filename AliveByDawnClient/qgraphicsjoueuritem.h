#ifndef QGRAPHICSJOUEURITEM_H
#define QGRAPHICSJOUEURITEM_H
#include <QGraphicsPolygonItem>
#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QGraphicsScene>


class QGraphicsJoueurItem : public QGraphicsPolygonItem
{
public:

    QGraphicsJoueurItem(const QPolygonF &polygon, QString _nom,int _pv,int _attaque,int _defense,QGraphicsItem *parent = nullptr);
    bool getMonster() const;

    void setMonster(bool value);

    bool getIsJoueur() const;
    void setIsJoueur(bool value);

private:
    qreal dx;
    qreal dy;
    QTimer *timer;
    bool monster;
    QString nom;
    bool mort;
    int pv;
    int attaque;
    int defense;
    bool isJoueur;

};

#endif // QGRAPHICSJOUEURITEM_H
