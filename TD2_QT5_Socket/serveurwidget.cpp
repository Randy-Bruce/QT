#include "serveurwidget.h"
#include "ui_serveurwidget.h"

ServeurWidget::ServeurWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServeurWidget)
{
    ui->setupUi(this);

}

ServeurWidget::~ServeurWidget()
{
    delete ui;
}



void ServeurWidget::on_pushButtonLancementServ_clicked()
{

}

void ServeurWidget::onQTcpServer_newConnection()
{

}

void ServeurWidget::onQTcpSocket_readyRead()
{

}

void ServeurWidget::onQTcpSocket_disconnected()
{

}
