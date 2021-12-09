#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    maScene.setSceneRect(0,0,640,560);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    // Rebondi Horizontalement
    // creation de mon objet ayant advance
    maBoule=new QGraohphicsBouleHorizontalItem(0,0,10,10);
    maBoule->setPos(20,60);
    QColor bleu (0,0,255);
    QBrush remplissage (bleu);
    maBoule->setBrush(remplissage);
    maScene.addItem(maBoule);
    ui->maVues->fitInView(maScene.sceneRect(),Qt::KeepAspectRatio);
    ui->maVues->setScene(&maScene);
    // association de timeout du timer au slot advance des objects
    connect(&timer,&QTimer::timeout,&maScene,&QGraphicsScene::advance);
    // lancement du timer -> timeout toutes les 30 millisecondes
    timer.start(10);
}
