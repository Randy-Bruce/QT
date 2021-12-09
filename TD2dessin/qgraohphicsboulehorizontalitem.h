#ifndef QGRAOHPHICSBOULEHORIZONTALITEM_H
#define QGRAOHPHICSBOULEHORIZONTALITEM_H
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>



class QGraohphicsBouleHorizontalItem : public QGraphicsEllipseItem
{
public:
    QGraohphicsBouleHorizontalItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
protected:
    void advance(int step) override;
private:
    qreal dx;

};

#endif // QGRAOHPHICSBOULEHORIZONTALITEM_H
