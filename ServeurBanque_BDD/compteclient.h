#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H
#include <QObject>
#include <QTcpSocket>
#include "interfaceaccesbdbanque.h"

class CompteClient : public QTcpSocket
{
public:
    CompteClient(QObject *parent = nullptr);
    bool Retirer(const float montant);
    bool Deposer(const float montant);
    float ObtenirSolde();
    void DefinirNumCompte(const int nc);
    int ObtenirNumCompte();
    static InterfaceAccesBDBanque bd;
private:
    int numCompte;
    float solde;
};

#endif // COMPTECLIENT_H
