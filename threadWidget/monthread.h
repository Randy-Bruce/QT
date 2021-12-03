#ifndef MONTHREAD_H
#define MONTHREAD_H
#include <QThread>
#include <QBuffer>
#include <QMutex>


class MonThread : public QThread
{
    Q_OBJECT
public:
    MonThread(QString _nom);
    void run() override;
    static unsigned int nbThread;
private :
    QString nom;
    static QBuffer zoneCommune;
    static QMutex verrou;
    void afficherZone();
signals:
    void monId(quint64 id);
};

#endif // MONTHREAD_H
