#include "compteclient.h"

InterfaceAccesBDBanque CompteClient::bd("172.18.58.14","banque","snir","snir");

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
            bd.MettreAJourLeSolde(numCompte,solde);
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
        bd.MettreAJourLeSolde(numCompte,solde);
    }
}

float CompteClient::ObtenirSolde()
{
    return bd.ObtenirSolde(numCompte);
}

void CompteClient::DefinirNumCompte(const int nc)
{
    bd.CreerCompte(nc);
    solde=bd.ObtenirSolde(nc);
    numCompte=nc;
}

int CompteClient::ObtenirNumCompte()
{
    return numCompte;
}
