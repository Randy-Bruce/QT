#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    //creation de la socket
    socketDeDialogueAvecServuer=new QTcpSocket(this);

    //association des evenements liés à la socket avec les slots appelés
    connect(socketDeDialogueAvecServuer,&QTcpSocket::connected,this,&ClientWidget::onQTcpSocket_connected);
    connect(socketDeDialogueAvecServuer,&QTcpSocket::disconnected,this,&ClientWidget::onQTcpSocket_disconnected);
    connect(socketDeDialogueAvecServuer,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&ClientWidget::onQTcpSocket_error);
    connect(socketDeDialogueAvecServuer,&QTcpSocket::hostFound,this,&ClientWidget::onQTcpSocket_hostFound);
    connect(socketDeDialogueAvecServuer,&QTcpSocket::stateChanged,this,&ClientWidget::onQTcpSocket_stateChange);
    connect(socketDeDialogueAvecServuer,&QTcpSocket::aboutToClose,this,&ClientWidget::onQTcpSocket_aboutToClose);
    connect(socketDeDialogueAvecServuer,&QTcpSocket::bytesWritten,this,&ClientWidget::onQTcpSocket_bytesWritten);
    connect(socketDeDialogueAvecServuer,&QTcpSocket::readChannelFinished,this,&ClientWidget::onQTcpSocket_readChannelFinished);
    connect(socketDeDialogueAvecServuer,&QTcpSocket::readyRead,this,&ClientWidget::onQTcpSocket_readyRead);

}

ClientWidget::~ClientWidget()
{
    delete ui;
}


void ClientWidget::on_pushButtonConnec_clicked()
{
    if(ui->pushButtonConnec->text()=="Connexion"){
        socketDeDialogueAvecServuer->connectToHost(ui->lineEditIPServ->text(), ui->lineEditNroPort->text().toInt());
    }else{
        socketDeDialogueAvecServuer->disconnectFromHost();
    }
}

void ClientWidget::on_pushButtonOrdinateur_clicked()
{
    typeDeDemande="c";
    socketDeDialogueAvecServuer->write(typeDeDemande.toLatin1());
}

void ClientWidget::on_pushButtonUtilisateur_clicked()
{
    typeDeDemande="u";
    socketDeDialogueAvecServuer->write(typeDeDemande.toLatin1());
}

void ClientWidget::on_pushButtonArchitecture_clicked()
{
    typeDeDemande="a";
    socketDeDialogueAvecServuer->write(typeDeDemande.toLatin1());
}

void ClientWidget::on_pushButtonOs_clicked()
{
    typeDeDemande="o";
    socketDeDialogueAvecServuer->write(typeDeDemande.toLatin1());
}

void ClientWidget::onQTcpSocket_connected()
{
    ui->textEditEtatConnec->append("connected");

    ui->pushButtonConnec->setText("deconnexion");
    ui->lineEditIPServ->setEnabled(false);
    ui->lineEditNroPort->setEnabled(false);
    ui->groupBoxInfoClient->setEnabled(true);

    ui->lineEditAchiProces->clear();
    ui->lineEditNomOrdi->clear();
    ui->lineEditOSOrdi->clear();
    ui->lineEditNomUser->clear();
}

void ClientWidget::onQTcpSocket_disconnected()
{

}

void ClientWidget::onQTcpSocket_error(QAbstractSocket::SocketError SocketError)
{
    ui->textEditEtatConnec->append(socketDeDialogueAvecServuer->errorString());
}

void ClientWidget::onQTcpSocket_hostFound()
{
    ui->textEditEtatConnec->append("hostfound");
}

void ClientWidget::onQTcpSocket_stateChange(QAbstractSocket::SocketState SocketState)
{
    QString etat;

    switch(SocketState){
    case QAbstractSocket::UnconnectedState: etat="The socket is not connected.";break;
    case QAbstractSocket::HostLookupState: etat="The socket is performing a host name lookup";break;
    case QAbstractSocket::ConnectingState: etat="The socket has started establishing a connecyion";break;
    case QAbstractSocket::ConnectedState: etat="A connection is established";break;
    case QAbstractSocket::BoundState: etat="The socket is bound to an address and port";break;
    case QAbstractSocket::ListeningState: etat="For internal use only";break;
    case QAbstractSocket::ClosingState: etat="The socket is about to close";break;
    }
    ui->textEditEtatConnec->append(etat);
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
    QByteArray buffer;

    if( socketDeDialogueAvecServuer->bytesAvailable() > 0 )
    {
        buffer = socketDeDialogueAvecServuer->readAll();
    }

    if (typeDeDemande=="u")
    {
        ui->lineEditNomUser->setText(buffer.data());         //QString::fromUtf8(buffer.data() )
    }

    if (typeDeDemande=="c")
    {
        ui->lineEditNomOrdi->setText(buffer.data());         //QString::fromUtf8(buffer.data() )
    }

    if (typeDeDemande=="o")
    {
        ui->lineEditOSOrdi->setText(buffer.data());          //QString::fromUtf8(buffer.data() )
    }

    if (typeDeDemande=="a")
    {
        ui->lineEditAchiProces->setText(buffer.data());      //QString::fromUtf8(buffer.data() )
    }


}
