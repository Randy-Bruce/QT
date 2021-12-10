#ifndef WIDGET_H
#define WIDGET_H
#include "qgraphicsboulehorizontalitem.h"
#include "qgraphicsballecollisionitem.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QRandomGenerator>
#include <QMediaPlayer>
#define LARGEUR 340
#define HAUTEUR 220
#define NBOBSTACLE 50



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButtonPlayExternalSound_clicked();
    void on_pushButtonChooseFile_clicked();

    void onQMediaPlayer_stateChanged(QMediaPlayer::State state);
    void onQMediaPlayer_error(QMediaPlayer::Error error);

private:
    Ui::Widget *ui;
    QGraphicsScene maScene;
    QGraphicsBalleCollisionItem *maBoule;
    QTimer timer;
    QGraphicsRectItem *laRaquette;
    QGraphicsRectItem*obstacles[NBOBSTACLE];
    QMediaPlayer player;
    QString musique;

};
#endif // WIDGET_H
