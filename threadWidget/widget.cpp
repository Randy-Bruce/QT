#include "widget.h"
#include "ui_widget.h"
#include "monthread.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
     MonThread *tab[5];
     qDebug()<<"nb Thread (avant boucle) "<<MonThread::nbThread;
    for (int i=0;i<5;i++)
    {
        tab[i]=new MonThread(QString::number(i));
        QObject::connect(tab[i],&MonThread::monId,this,&Widget::on_MonThreadMonId);
    }
    qDebug()<<"nb Thread (apres boucle) "<<MonThread::nbThread;
    for (int i=0;i<5;i++)
    {
        tab[i]->start();
    }


}

void Widget::on_MonThreadMonId(quint64 id)
{
    qDebug()<<"signal du thread :"<<QString::number(id,16);
}
