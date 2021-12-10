#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFocus();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Left:
        qDebug()<<"gauche";
        break;
    case Qt::Key_Right:
        qDebug()<<"droit";
        break;
    case Qt::Key_Up:
        qDebug()<<"haut";
        break;
    case Qt::Key_Down:
        qDebug()<<"bas";
        break;
    }
}

