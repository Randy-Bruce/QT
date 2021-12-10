#ifndef SERVEURBANQUE_H
#define SERVEURBANQUE_H
#include <QObject>
#include <QTcpServer>
#include "compteclient.h"

class ServeurBanque : public QTcpServer
{
    Q_OBJECT
public:
    ServeurBanque(QObject *parent = nullptr);
    void Start();
    void Stop();
    void EnvoyerMessage(QString message,CompteClient *client);
private slots :
    void onServeurBanque_newConnection();
    void onCompteClient_readyRead();
    void onCompteClient_disconnected();
private:
    QList <CompteClient*>lesConnexionClients;
};

#endif // SERVEURBANQUE_H
