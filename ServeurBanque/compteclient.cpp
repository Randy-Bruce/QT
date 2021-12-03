#include "compteclient.h"

CompteClient::CompteClient(QObject *parent):QTcpSocket(parent),numCompte(0),solde(0.0)
{

}

bool CompteClient::Retirer(const float montant)
{
    bool retour=false;
    if(montant>0)
    {
        if(solde>montant)
        {
            solde=solde-montant;
            retour=true;
        }
    }
    return retour;
}

bool CompteClient::Deposer(const float montant)
{
    if(montant>0)
    {
        solde+=montant;
    }
}

float CompteClient::ObtenirSolde()
{
    return solde;
}

void CompteClient::DefinirNumCompte(const int nc)
{
    solde=200;
    numCompte=nc;
}

int CompteClient::ObtenirNumCompte()
{
    return numCompte;
}
