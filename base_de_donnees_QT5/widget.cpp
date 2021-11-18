#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    bd=QSqlDatabase::addDatabase("QMYSQL");
    bd.setHostName("172.18.58.14");
    bd.setDatabaseName("france2015");
    bd.setUserName("snir");
    bd.setPassword("snir");
    if (!bd.open())
    {
        qDebug()<<"pb acces bd "<<bd.lastError();
    }
    else
    {
    qDebug()<<"acces bd ok";
    }
}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_labelNomDep_linkActivated(const QString &link)
{

}

void Widget::on_pushButtonNomDep_clicked()
{
    requetePrepare.prepare("select departement_nom from departement where departement_region_id = :idr ;" );
    requetePrepare.bindValue(":idr",5);
    if (!requetePrepare.exec()){
        qDebug()<<"pb requete "<<requetePrepare.lastError();
    }

    int nbLignesRegion=requetePrepare.size();

}






