#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QColor bleu (255,0,0);
    ui->setupUi(this);
    maScene.setSceneRect(0,0,340,220);
    // creation de la raquette
    laRaquette=new QGraphicsRectItem(LARGEUR/2,HAUTEUR-20,100,10);
    laRaquette->setBrush(QBrush(Qt::red));
    maScene.addItem(laRaquette);

    // creation de mon objet ayant advance et gestion de collision
    maBoule=new QGraphicsBalleCollisionItem(0,0,10,10,laRaquette);
    maBoule->setBrush(QBrush(Qt::green));
    maBoule->setPos(150,200);
    maScene.addItem(maBoule);

    // creation de 50 obstacles
    for (int i=0;i<NBOBSTACLE;i++)
    {
        obstacles[i]=new QGraphicsRectItem(0,0,10,10);
        // positionnement aleatoire dans les limites de la scene
        obstacles[i]->setPos(1+QRandomGenerator::global()->bounded(LARGEUR-10),1+QRandomGenerator::global()->bounded(HAUTEUR-10));
        maScene.addItem(obstacles[i]);
    }

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
    connect(&player,&QMediaPlayer::stateChanged,this,&Widget::onQMediaPlayer_stateChanged);
    connect(&player,QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error),this,&Widget::onQMediaPlayer_error);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    // lancement du timer -> timeout toutes les 30 millisecondes
    timer.start(10);
}

void Widget::on_pushButtonPlayExternalSound_clicked()
{
    player.setMedia(QUrl::fromLocalFile(musique));
    player.setVolume(100);
    player.play();
}

void Widget::on_pushButtonChooseFile_clicked()
{
    musique = QFileDialog::getOpenFileName();
}

void Widget::onQMediaPlayer_stateChanged(QMediaPlayer::State state)
{
    QString etat;
    switch(state)
    {
    case QMediaPlayer::StoppedState :etat="stopped";break;
    case QMediaPlayer::PlayingState :etat="playing";break;
    case QMediaPlayer::PausedState :etat="paused";break;
    }
    qDebug()<<etat;
}

void Widget::onQMediaPlayer_error(QMediaPlayer::Error error)
{
    qDebug()<<player.errorString();
}
