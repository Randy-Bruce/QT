#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QBuffer>
#include <QGraphicsPolygonItem>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QMediaPlayer>
#include <QMediaPlaylist>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWidget; }
QT_END_NAMESPACE

class ClientWidget : public QWidget
{
    Q_OBJECT

public:

    ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

    void envoyerDonnees(QString pseudo, QChar commande, bool monster);
    void AfficherObjet(QString nom, QList<QPoint> listepositionsDecor,
                       QList<QPoint> listepositionsJoueur,QList<QPoint> listepositionsArtefact, int nbClient);

private slots:


    void on_pushButtonConnexion_clicked();

    void onQTcpSocket_connected();

    void onQTcpSocket_disconnected();

    void onQTcpSocket_error(QAbstractSocket::SocketError socketError);

    void onQTcpSocket_hostFound();

    void onQTcpSocket_stateChanged(QAbstractSocket::SocketState socketState);

    void onQTcpSocket_aboutToClose();

    void onQTcpSocket_bytesWritten(qint64 bytes);

    void onQTcpSocket_readChannelFinished();

    void onQTcpSocket_readyRead();

    void on_pushButtonJouer_clicked();

    void on_pushButtonMonster_clicked();

    void on_pushButtonCroco_clicked();

    void on_pushButtonLupin_clicked();

    void on_pushButtonOreo_clicked();

    void on_pushButtonArsene_clicked();

    void onQMediaPlayer_stateChanged(QMediaPlayer::State state);

    void onQMediaPlayer_error(QMediaPlayer::Error error);

private:
    Ui::ClientWidget *ui;
    QTcpSocket *socketDeDialogueAvecServeur;
    QGraphicsScene *scene;
    QGraphicsRectItem *obstacles[20];
    void keyPressEvent(QKeyEvent *event);
    QMediaPlayer player;
    QMediaPlaylist playlist;
    QMediaPlaylist playlist2;
    QString nomFichier;
};
#endif // CLIENTWIDGET_H
