#ifndef QGRAOHPHICSBOULEHORIZONTALITEM_H
#define QGRAOHPHICSBOULEHORIZONTALITEM_H
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>



class QGraphicsBouleHorizontalItem : public QGraphicsEllipseItem
{
public:
    QGraphicsBouleHorizontalItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
protected:
    void advance(int step) override;
private:
    qreal dx;           // valeur du pas et sens de deplacement
                        // si < 0 de droite à gauche
                        // si > 0 de gouche à droite
    qreal dy;           // boule n'importe ou

};

#endif // QGRAOHPHICSBOULEHORIZONTALITEM_H
