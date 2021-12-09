#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    maScene.setSceneRect(0,0,340,220);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    // Rebondi Horizontalement
    // creation de mon objet ayant advance
    maBoule=new QGraphicsBouleHorizontalItem(0,0,10,10);
    maBoule->setPos(20,60);
    QColor bleu (0,0,255);
    QColor rouge (255,0,0);
    QBrush remplissage (rouge);
    maBoule->setBrush(remplissage);
    maScene.addItem(maBoule);
    ui->maVues->fitInView(maScene.sceneRect(),Qt::KeepAspectRatio);
    ui->maVues->setScene(&maScene);
    ui->maVues2->fitInView(maScene.sceneRect(),Qt::KeepAspectRatio);
    ui->maVues2->setScene(&maScene);
    QRadialGradient soleil (160,230,150);
    soleil.setColorAt(0,QColor(255,255,255));
    soleil.setColorAt(0.5,QColor(255,255,0));
    soleil.setColorAt(1,QColor(255,0,0));
    ui->maVues2->setBackgroundBrush(QBrush(soleil));
    ui->maVues3->fitInView(maScene.sceneRect(),Qt::KeepAspectRatio);
    ui->maVues3->setScene(&maScene);
    ui->maVues3->rotate(180);

    QBrush remplissage2;
    remplissage2.setStyle(Qt::Dense5Pattern);
    remplissage2.setColor(bleu);

    ui->maVues4->fitInView(maScene.sceneRect(),Qt::KeepAspectRatio);
    ui->maVues4->setBackgroundBrush(QBrush(remplissage2));
    ui->maVues4->setScene(&maScene);

    // association de timeout du timer au slot advance des objects
    connect(&timer,&QTimer::timeout,&maScene,&QGraphicsScene::advance);
    // lancement du timer -> timeout toutes les 30 millisecondes
    timer.start(10);
}
