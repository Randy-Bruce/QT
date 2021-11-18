#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QAbstractSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWidget; }
QT_END_NAMESPACE

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    void on_pushButtonConnec_clicked();

    void on_pushButtonOrdinateur_clicked();

    void on_pushButtonUtilisateur_clicked();

    void on_pushButtonArchitecture_clicked();

    void on_pushButtonOs_clicked();

    void onQTcpSocket_connected();

    void onQTcpSocket_disconnected();

    void onQTcpSocket_error(QAbstractSocket::SocketError SocketError);

    void onQTcpSocket_hostFound();

    void onQTcpSocket_stateChange(QAbstractSocket::SocketState SocketState);

    void onQTcpSocket_aboutToClose();

    void onQTcpSocket_bytesWritten(qint64 bytes);

    void onQTcpSocket_readChannelFinished();

    void onQTcpSocket_readyRead();


private:
    Ui::ClientWidget *ui;
    QTcpSocket *socketDeDialogueAvecServuer;
    QString typeDeDemande;


};
#endif // CLIENTWIDGET_H
