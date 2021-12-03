#include "monthread.h"
#include <QDebug>
#include <QDataStream>
QBuffer MonThread::zoneCommune;
QMutex MonThread::verrou;
unsigned int MonThread::nbThread=0;

MonThread::MonThread(QString _nom):nom(_nom)
{
    nbThread++;
}

void MonThread::run()
{
    verrou.lock();
    qDebug()<<"je suis le thread"<<nom;
    qDebug()<<"mon id est  "<< currentThreadId();
    /* if (nom.toInt()%2==0)
    {
        emit monId((quint64)currentThreadId());
    }*/

    zoneCommune.open(QIODevice::ReadWrite);
    QDataStream out (&zoneCommune);
    out<<(quint64)currentThreadId()<<nom;
    verrou.unlock();
    afficherZone();

}

void MonThread::afficherZone()
{
    verrou.lock();
    zoneCommune.open(QIODevice::ReadOnly);
    QDataStream in (&zoneCommune);
    quint64 ptr;
    QString chaine;
    in>>ptr>>chaine;
    qDebug()<<"Thread "<<nom<<"zone commune "<<chaine<<"id : "<<QString::number(ptr,16);
    verrou.unlock();
}
