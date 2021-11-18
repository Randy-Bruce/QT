#ifndef SERVEURWIDGET_H
#define SERVEURWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QAbstractSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class ServeurWidget; }
QT_END_NAMESPACE

class ServeurWidget : public QWidget
{
    Q_OBJECT

public:
    ServeurWidget(QWidget *parent = nullptr);
    ~ServeurWidget();

private slots:
    void on_pushButtonLancementServ_clicked();

    void onQTcpServer_newConnection();

    void onQTcpSocket_readyRead();

    void onQTcpSocket_disconnected();


private:
    Ui::ServeurWidget *ui;
    QTcpServer *socketEcouteServeur;
    QTcpSocket *socketDialogueClient;
};
#endif // SERVEURWIDGET_H
