#include "serveurbanque.h"
#include <QMessageBox>
#include <QBuffer>

ServeurBanque::ServeurBanque(QObject *parent):QTcpServer(parent)
{
    if (!QObject::connect(this,&QTcpServer::newConnection,this,&ServeurBanque::onServeurBanque_newConnection))
    {
        QMessageBox msgBox;
        msgBox.setText("Erreur association signal/slot");
        msgBox.exec();
    }
}

void ServeurBanque::Start()
{
    if (!listen(QHostAddress::Any,8888))
    {
        QMessageBox msgBox;
        msgBox.setText("Erreur listen sur le port 8888 : "
                       +errorString());
        msgBox.exec();
        close();
    }
}

void ServeurBanque::Stop()
{
    close();
}

void ServeurBanque::EnvoyerMessage(QString message, CompteClient *client)
{
    // construction de la trame
    quint16 taille=0;
    QBuffer tampon;
    tampon.open(QIODevice::WriteOnly);
    // association du tampon au flux de sortie
    QDataStream out(&tampon);
    // construction de la trame
    out<<taille<<message;
    // calcul de la taille de la trame
    taille=(static_cast<quint16>(tampon.size()))-sizeof (taille);
    // placement sur la premiere position du flux pour pouvoir modifier la taille
    tampon.seek(0);
    // modification de la trame avec la taille reel de la trame
    out<<taille;
    // envoi du QByteArray du tampon via la socket
    client->write(tampon.buffer());

}

void ServeurBanque::onServeurBanque_newConnection()
{
    while(this->hasPendingConnections())
    {
        CompteClient *client=(CompteClient*)this->nextPendingConnection();
        connect(client,&CompteClient::readyRead,this,&ServeurBanque::onCompteClient_readyRead);
        connect(client,&CompteClient::disconnected,this,&ServeurBanque::onCompteClient_disconnected);
        lesConnexionClients.append(client);
        EnvoyerMessage("Veuillez donner votre numéro de compte",client);
    }
}

void ServeurBanque::onCompteClient_readyRead()
{
    CompteClient *client=(CompteClient*)sender();
    quint16 taille=0;
    QChar commande;
    float valeurOperation;
    int numeroCompte;
    QString message;
    // j'ai moins autant de donnés que l'en-tête taille des trames
    if (client->bytesAvailable()>=(quint64)sizeof (taille))
    {
        QDataStream in(client); // flux du client dans "in"
        // recuperation de la taille
        in>>taille;
        // les donnes dispos font au moins la taille
        // des donnes attendues
        if (client->bytesAvailable()>=(quint64)taille)
        {
            in>>commande;
            switch (commande.toLatin1())
            {
            case 'N':
                in>>numeroCompte;
                client->DefinirNumCompte(numeroCompte);
                message="Bienvenu sur le compte"+QString::number(numeroCompte);
                EnvoyerMessage(message,client);
                break;
            case 'R':
                in>>valeurOperation;
                if(client->Retirer(valeurOperation))
                {
                    message="Nouveau solde : "+QString::number(client->ObtenirSolde());
                }
                else
                {
                    message = "Solde insuffisant";
                }
                break;
            case 'D':
                in>>valeurOperation;
                client->Retirer(valeurOperation);
                message="Nouveau solde : "+QString::number(client->ObtenirSolde());
                break;
            case 'S':
                message="Solde : "+QString::number(client->ObtenirSolde());
                break;
            default:
                message="Operation non comprise";
                break;

            }
            EnvoyerMessage(message,client);
        }
    }
}

void ServeurBanque::onCompteClient_disconnected()
{
    CompteClient *client=(CompteClient*)sender();
    if (!client)
    {
        QMessageBox msg;
        msg.setText("erreur deconnexion : "+client->errorString());
        msg.exec();
    }
    else
    {
        lesConnexionClients.removeOne(client);
        client->deleteLater();
    }
}
