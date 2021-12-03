#include "monthread.h"
#include <QDebug>

MonThread::MonThread(QString _nom):nom(_nom)
{

}

void MonThread::run()
{
    qDebug()<<"je suis le thread"<<nom;
    qDebug()<<"mon id est  "<< currentThreadId();
}
