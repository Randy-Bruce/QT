#include "interfaceaccesbdbanque.h"
#include <QSqlQuery>
#include <QSqlError>
#include<QDebug>

/*InterfaceAccesBDBanque::InterfaceAccesBDBanque()
{
}
*/

InterfaceAccesBDBanque::InterfaceAccesBDBanque(QString hote, QString bd, QString login, QString mdp)
{
    bdd=QSqlDatabase::addDatabase("QMYSQL");
    bdd.setHostName(hote);
    bdd.setDatabaseName(bd);
    bdd.setUserName(login);
    bdd.setPassword(mdp);
    if (!bdd.open())
    {
        qDebug()<<"Erreur ouverture bdd : "<<bdd.lastError();
    }
    else
    {
        qDebug()<<"Ouverture bdd ok ";
    }

}

float InterfaceAccesBDBanque::ObtenirSolde(int numCompte)
{
    QSqlQuery requete;
    float solde;
    bool retour;
    requete.prepare("select solde from comptes where idCompte=:id;");
    requete.bindValue(":id",numCompte);
    requete.exec();
    if (retour)
    {
        requete.next();
        solde=requete.value("solde").toFloat();
    }
    else
    {
        qDebug()<<"pb obtenir solde "<<requete.lastError();
    }
    return solde;
}

void InterfaceAccesBDBanque::MettreAJourLeSolde(int numCompte, float nouveauSolde)
{
    QSqlQuery requete;
    bool retour;
    requete.prepare("update comptes set solde=:solde where idCompte=:id;");
    requete.bindValue(":solde",nouveauSolde);
    requete.bindValue(":id",numCompte);
    requete.exec();
    if (!retour)
    {
        qDebug()<<"pb creation de compte "<<requete.lastError();
    }

}

void InterfaceAccesBDBanque::CreerCompte(int numCompte)
{
    if (CompteExiste(numCompte))
    {
        qDebug()<<"Le compte existe deja";
    }
    else
    {
        QSqlQuery requete;
        bool retour;
        requete.prepare("insert into comptes (idCompte,solde,nom,prenom) values(:id,0,'bidon','pbidon');");
        requete.bindValue(":id",numCompte);
        requete.exec();
        if (!retour)
        {
            qDebug()<<"pb creation de compte "<<requete.lastError();
        }
    }
}

bool InterfaceAccesBDBanque::CompteExiste(int numCompte)
{
    QSqlQuery requete;
    bool existe=false;
    requete.prepare("select solde from comptes where idCompte=:id;");
    requete.bindValue(":id",numCompte);

    if (!requete.exec())
    {
        qDebug()<<"pb requete compte existe "<<requete.lastError();
    }
    // si le compte existe on passe existe a vrai
    if (requete.size()!=0)
    {
        existe=true;
    }
    return existe;











}











