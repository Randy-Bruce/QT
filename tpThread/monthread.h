#ifndef MONTHREAD_H
#define MONTHREAD_H
#include <QThread>


class MonThread : public QThread
{
public:
    MonThread(QString _nom);
    void run() override;
private :
    QString nom;
};

#endif // MONTHREAD_H
