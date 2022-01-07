#include "clientwidget.h"
#include "ui_clientwidget.h"
#include "qgraphicsjoueuritem.h"
bool Oreo = false;
bool Croco = false;
bool Lupin = false;
bool Arsene = false;



ClientWidget::ClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    socketDeDialogueAvecServeur=new QTcpSocket(this);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::connected,this,&ClientWidget::onQTcpSocket_connected);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::disconnected,this,&ClientWidget::onQTcpSocket_disconnected);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::hostFound,this,&ClientWidget::onQTcpSocket_hostFound);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::bytesWritten,this,&ClientWidget::onQTcpSocket_bytesWritten);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::readyRead,this,&ClientWidget::onQTcpSocket_readyRead);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::aboutToClose,this,&ClientWidget::onQTcpSocket_aboutToClose);
    connect(socketDeDialogueAvecServeur,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&ClientWidget::onQTcpSocket_error);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::stateChanged,this,&ClientWidget::onQTcpSocket_stateChanged);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::readChannelFinished,this,&ClientWidget::onQTcpSocket_readChannelFinished);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,680,510);
    // assoicier la scene à la vue
    ui->maVue->setScene(scene);
    /*   QColor vert (0,255,0);
    QColor bleu (0,0,255);
    QColor rouge (255,0,0);
    QColor bleuMarine (0,255,255);
    QColor blanc (255,255,255);
    QColor noir (0,0,0);

    // joueur 1

    QPolygon poly;
    poly.setPoints(12,60,13,135,13,134,85,178,85,178,183,133,183,133,298,62,298,61,184,22,184,19,85,61,86);
    QGraphicsPolygonItem *joueur1 = new QGraphicsPolygonItem(poly);
    //contour
    joueur1->setBrush(bleu);
    joueur1->setFlag(QGraphicsItem::ItemIsMovable);
    joueur1->setScale(0.5);
    scene->addItem(joueur1);


    // joueur 2
    QPolygon poly1;
    poly1.setPoints(12,60,13,135,13,134,85,178,85,178,183,133,183,133,298,62,298,61,184,22,184,19,85,61,86);
    QGraphicsPolygonItem *joueur2 = new QGraphicsPolygonItem(poly1);
    //contour
    joueur2->setBrush(rouge);
    joueur2->setFlag(QGraphicsItem::ItemIsMovable);
    joueur2->setScale(0.5);
    scene->addItem(joueur2);

    // joueur 3
    QPolygon poly2;
    poly2.setPoints(12,60,13,135,13,134,85,178,85,178,183,133,183,133,298,62,298,61,184,22,184,19,85,61,86);
    QGraphicsPolygonItem *joueur3 = new QGraphicsPolygonItem(poly2);
    //contour
    joueur3->setBrush(bleuMarine);
    joueur3->setFlag(QGraphicsItem::ItemIsMovable);
    joueur3->setScale(0.5);
    scene->addItem(joueur3);

    // joueur 4
    QPolygon poly3;
    poly3.setPoints(12,60,13,135,13,134,85,178,85,178,183,133,183,133,298,62,298,61,184,22,184,19,85,61,86);
    QGraphicsPolygonItem *joueur4 = new QGraphicsPolygonItem(poly3);
    //contour
    joueur4->setBrush(vert);
    joueur4->setFlag(QGraphicsItem::ItemIsMovable);
    joueur4->setScale(0.5);
    scene->addItem(joueur4);

    // joueur 5
    QPolygon poly4;
    poly4.setPoints(12,60,13,135,13,134,85,178,85,178,183,133,183,133,298,62,298,61,184,22,184,19,85,61,86);
    QGraphicsPolygonItem *joueur5 = new QGraphicsPolygonItem(poly4);
    //contour
    joueur5->setBrush(noir);
    joueur5->setFlag(QGraphicsItem::ItemIsMovable);
    joueur5->setScale(0.5);
    scene->addItem(joueur5);
*/
    playlist.addMedia(QUrl("qrc:/[No Copyright Music] Broken Piano Horror Music Royalty Free Music.m4a"));
    playlist.setPlaybackMode(QMediaPlaylist::Loop);
    player.setPlaylist(&playlist);
    player.setVolume(100);
    player.play();

}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::envoyerDonnees( QString pseudo, QChar commande,bool monster)
{
    quint16 taille=0;

    QBuffer tampon;
    //association du tampon au flux de sortie
    tampon.open(QIODevice::WriteOnly);
    //association du tampon au flux de sortie
    QDataStream out(&tampon);

    //construction de la trame
    out << taille << pseudo << commande << monster;
    //calcul de la taille de la trame
    taille = tampon.size()-sizeof(taille);
    //placement sur la première position du flux pour pouvoir modifier la taille
    tampon.seek(0);
    //modification de la trame avec la taille réel de la trame
    out << taille;
    //envoi du QByteArray du tampon via la socket
    socketDeDialogueAvecServeur->write(tampon.buffer());
}


void ClientWidget::on_pushButtonConnexion_clicked()
{
    if (ui->pushButtonConnexion->text()=="Connexion")
    {
        socketDeDialogueAvecServeur->connectToHost(ui->lineEditAdresseIPServeur->text(),ui->lineEditPort->text().toInt());
    }
    else
    {
        socketDeDialogueAvecServeur->disconnectFromHost();
    }
    playlist2.addMedia(QUrl("qrc:/Horror Ambience (Free Background Music).m4a"));
    playlist2.setPlaybackMode(QMediaPlaylist::Loop);
    player.setPlaylist(&playlist2);
    player.setVolume(100);
    player.play();


}

void ClientWidget::onQTcpSocket_connected()
{
    ui->textEditEtat->append("Connecté au serveur");

    ui->pushButtonConnexion->setText("Déconnexion");
    ui->lineEditAdresseIPServeur->setEnabled(false);
    ui->lineEditPort->setEnabled(false);
}

void ClientWidget::onQTcpSocket_disconnected()
{
    ui->textEditEtat->append("Déconnecté du serveur");
    ui->pushButtonConnexion->setText("Connexion"); ui->lineEditAdresseIPServeur->setEnabled(true);
    ui->lineEditPort->setEnabled(true);
}

void ClientWidget::onQTcpSocket_error(QAbstractSocket::SocketError socketError)
{
    ui->textEditEtat->append(socketDeDialogueAvecServeur->errorString());
}

void ClientWidget::onQTcpSocket_hostFound()
{
    ui->textEditEtat->append("hostfound");
}

void ClientWidget::onQTcpSocket_stateChanged(QAbstractSocket::SocketState socketState)
{
    QString etat;
    switch (socketState) {
    case QAbstractSocket::UnconnectedState: etat="The socket isn't connected.";break;
    case QAbstractSocket::HostLookupState: etat="The socket is performing a host name lookup";break;
    case QAbstractSocket::ConnectingState: etat="The socket has started establishing a connection";break;
    case QAbstractSocket::ConnectedState: etat="A connection id established";break;
    case QAbstractSocket::BoundState: etat="The socket is bound to an adreess and port";break;
    case QAbstractSocket::ListeningState: etat="For internal use only";break;
    case QAbstractSocket::ClosingState: etat="The socket is about to close";break;

    }
}

void ClientWidget::onQTcpSocket_aboutToClose()
{

}

void ClientWidget::onQTcpSocket_bytesWritten(qint64 bytes)
{

}

void ClientWidget::onQTcpSocket_readChannelFinished()
{

}

void ClientWidget::onQTcpSocket_readyRead()
{
    QList <QGraphicsItem*>listeDesObjets = scene->items();
    foreach(QGraphicsItem *ptr, listeDesObjets)
    {
        scene->removeItem(ptr);
        delete ptr;
    }

    quint16 taille=0;
    QString message;
    QList<QPoint> listepositionDecor;
    QList<QPoint> listepositionJoueur;
    QList<QPoint> listepositionArtefact;

    QChar decor, joueur, artefact, nbClient;
    int clientNb;
    double distance;
    //si le nombre d'octers recu est au moins egal a celui de la taille de que l'on doit recevoir
    if(socketDeDialogueAvecServeur->bytesAvailable()>=(quint64)sizeof (taille)){
        //association de la socket au flux d'entree
        QDataStream in(socketDeDialogueAvecServeur);
        //extraire la taille de ce que l'on doit recevoir
        in >> taille;
        //si le nombre d'octets recu est au moin egal a celui  de ce que l'on foit recevoir
        if(socketDeDialogueAvecServeur->bytesAvailable()>=(quint64)taille){
            //extraire le reste
            in >>decor >>listepositionDecor>>joueur>>listepositionJoueur>>artefact>>listepositionArtefact>>nbClient>>clientNb;
            qDebug()<<listepositionDecor<<endl<<listepositionJoueur<<endl<<listepositionArtefact;
            AfficherObjet(message,listepositionDecor,listepositionJoueur,listepositionArtefact,clientNb);
        }

    }
}

void ClientWidget::on_pushButtonJouer_clicked()
{

}

void ClientWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()){
    case Qt::Key_Q:
        qDebug()<<"gauche";
        envoyerDonnees(ui->lineEditPseudo->text(),'q',false);
        break;
    case Qt::Key_D:
        qDebug()<<"droite";
        envoyerDonnees(ui->lineEditPseudo->text(),'d',false);
        break;
    case Qt::Key_Z:
        qDebug()<<"haut";
        envoyerDonnees(ui->lineEditPseudo->text(),'z',false);
        break;
    case Qt::Key_S:
        qDebug()<<"bas";
        envoyerDonnees(ui->lineEditPseudo->text(),'s',false);
        break;
    }
}

void ClientWidget::AfficherObjet(QString nom, QList<QPoint> listepositionsDecor,
                                 QList<QPoint> listepositionsJoueur,QList<QPoint> listepositionsArtefact, int nbClient)
{
    QColor vert (0,255,0);
    QColor bleu (0,0,255);
    QColor rouge (255,0,0);
    QColor bleuMarine (0,255,255);
    QColor blanc (255,255,255);
    QColor noir (0,0,0);

    if (nbClient == 1){
            // joueur 1

            QPolygon poly;
            poly.setPoints(12,60,13,135,13,134,85,178,85,178,183,133,183,133,298,62,298,61,184,22,184,19,85,61,86);
            QGraphicsJoueurItem *croco = new QGraphicsJoueurItem(poly,"croco",5,10,10);
            //contour
            croco->setBrush(bleu);
            croco->setFlag(QGraphicsItem::ItemIsMovable);
            croco->setScale(0.1);
            croco->setIsJoueur(true);
            scene->addItem(croco);
            croco->setPos(listepositionsJoueur.at(0));

        }
        else if(nbClient == 2){
            // joueur 2
            QPolygon poly1;
            poly1.setPoints(12,60,13,135,13,134,85,178,85,178,183,133,183,133,298,62,298,61,184,22,184,19,85,61,86);
            QGraphicsJoueurItem *lupin = new QGraphicsJoueurItem(poly1,"lupin",5,10,10);
            //contour
            lupin->setBrush(rouge);
            lupin->setFlag(QGraphicsItem::ItemIsMovable);
            lupin->setScale(0.1);
            lupin->setIsJoueur(true);
            scene->addItem(lupin);
            lupin->setPos(listepositionsJoueur.at(1));

        }

        else if(nbClient == 3){
            // joueur 3
            QPolygon poly2;
            poly2.setPoints(12,60,13,135,13,134,85,178,85,178,183,133,183,133,298,62,298,61,184,22,184,19,85,61,86);
            QGraphicsJoueurItem *oreo = new QGraphicsJoueurItem(poly2,"oreo",5,10,10);
            //contour
            oreo->setBrush(bleuMarine);
            oreo->setFlag(QGraphicsItem::ItemIsMovable);
            oreo->setScale(0.1);
            scene->addItem(oreo);
            oreo->setPos(listepositionsJoueur.at(2));

        }

        else if(nbClient == 4){
            // joueur 4
            QPolygon poly3;
            poly3.setPoints(12,60,13,135,13,134,85,178,85,178,183,133,183,133,298,62,298,61,184,22,184,19,85,61,86);
            QGraphicsJoueurItem *arsene = new QGraphicsJoueurItem(poly3,"oreo",5,10,10);
            //contour
            arsene->setBrush(vert);
            arsene->setFlag(QGraphicsItem::ItemIsMovable);
            arsene->setScale(0.1);
            arsene->setIsJoueur(true);
            scene->addItem(arsene);
            arsene->setPos(listepositionsJoueur.at(3));


        }


        else if(nbClient == 5){
            // joueur 5
            QPolygon poly4;
            poly4.setPoints(12,60,13,135,13,134,85,178,85,178,183,133,183,133,298,62,298,61,184,22,184,19,85,61,86);
            QGraphicsJoueurItem *joueur5 =new QGraphicsJoueurItem(poly4,"tueur",5,10,10);
            //contour
            joueur5->setBrush(noir);
            joueur5->setFlag(QGraphicsItem::ItemIsMovable);
            joueur5->setScale(0.1);
            joueur5->setIsJoueur(true);
            joueur5->setMonster(true);
            scene->addItem(joueur5);
            joueur5->setPos(listepositionsJoueur.at(4));

        }

    QPoint pt;
    for (int i=0;i<20;i++){
        obstacles[i]=new QGraphicsRectItem(0,0,10,10);
        // positionnement aleatoire dans les limites de la scene
        obstacles[i]->setPos(1+QRandomGenerator::global()->bounded(680-10),1+QRandomGenerator::global()->bounded(510-150));
        obstacles[i]->setBrush(QBrush(Qt::blue));
        obstacles[i]->setPos(listepositionsDecor.at(i));
        scene->addItem(obstacles[i]);
    }


}


void ClientWidget::on_pushButtonMonster_clicked()
{
    ui->textEditEtat->append("Vous etes un Monstre");
}


void ClientWidget::on_pushButtonCroco_clicked()
{
    Croco = true;
    Lupin = false;
    Oreo = false;
    Arsene = false;
    ui->textEditSurvivor->setText("Croco");
}

void ClientWidget::on_pushButtonLupin_clicked()
{
    Croco = false;
    Lupin = true;
    Oreo = false;
    Arsene = false;
    ui->textEditSurvivor->setText("Lupin");
}

void ClientWidget::on_pushButtonOreo_clicked()
{
    Croco = false;
    Lupin = false;
    Oreo = true;
    Arsene = false;
    ui->textEditSurvivor->setText("Oreo");
}

void ClientWidget::on_pushButtonArsene_clicked()
{
    Croco = false;
    Lupin = false;
    Oreo = false;
    Arsene = true;
    ui->textEditSurvivor->setText("Arsene");
}

void ClientWidget::onQMediaPlayer_stateChanged(QMediaPlayer::State state)
{
    QString etat;
    switch (state) {
    case QMediaPlayer::StoppedState : etat="stopped";break;
    case QMediaPlayer::PlayingState : etat="playing";break;
    case QMediaPlayer::PausedState : etat="stopped";break;
    }
    qDebug()<<etat;
}

void ClientWidget::onQMediaPlayer_error(QMediaPlayer::Error error)
{
    qDebug()<<player.errorString();
}
