#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,400,300);
    // assoicier la scene à la vue
    ui->maVue->setScene(scene);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonDessiner_clicked()
{
    QColor vert (0,255,0);
    QColor bleu (0,0,255);
    QColor rouge (255,0,0);
    QColor bleuMarine (0,255,255);
    QColor blanc (255,255,255);
    QColor noir (0,0,0);
    /*
    // Rectangle
    QGraphicsRectItem *rectangle=new QGraphicsRectItem(10,10,100,50);
    // definition du bleu
    // Contour
    QPen contour (bleu);
    rectangle->setPen(contour);
    // remplissage
    QBrush remplissage (bleu);
    rectangle->setBrush(remplissage);
    //Bouger l'objet
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);
    */

    /*
    // Tringle
    QPolygon poly;
    poly.setPoints(3,33,0,65,47,1,46);
    QGraphicsPolygonItem *triangle = new QGraphicsPolygonItem(poly);
    //couleur rouge
    //contour
    triangle->setPen(rouge);
    //remplissage
    triangle->setBrush(bleu);
    triangle->setFlag(QGraphicsItem::ItemIsMovable);
    */

    /*
    // Cercle
    QGraphicsEllipseItem *cercle = new QGraphicsEllipseItem(50,50,50,50);
    cercle->setPen(rouge);
    cercle->setBrush(bleuMarine);
    cercle->setFlag(QGraphicsItem::ItemIsMovable);
    */

    /*
    // Ovale
    QGraphicsEllipseItem *ovale = new QGraphicsEllipseItem(50,50,50,20);
    ovale->setBrush(vert);
    ovale->setFlag(QGraphicsItem::ItemIsMovable);
    */


    /*
    // Etoile rayure
    QPolygon poly1;
    poly1.setPoints(10,55,1,67,36,109,37,76,59,87,95,55,74,22,95,33,60,0,38,41,37);
    QGraphicsPolygonItem *etoileRayure = new QGraphicsPolygonItem(poly1);
    //contour
    etoileRayure->setPen(bleu);
    //remplissage
    QBrush interieur (noir);
    interieur.setStyle(Qt::VerPattern);
    // application des parametres de remplissage au polygone
    etoileRayure->setBrush(interieur);

    // Etoile
    QPolygon poly2;
    poly2.setPoints(10,55,1,67,36,109,37,76,59,87,95,55,74,22,95,33,60,0,38,41,37);
    QGraphicsPolygonItem *etoile = new QGraphicsPolygonItem(poly2);
    //contour
    etoile->setPen(bleu);
    etoile->setBrush(vert);
    */

    /*
    //Gradiants rectangle
            QGraphicsRectItem *  rectGradItem = new
            QGraphicsRectItem(10,20,300,100);
            QLinearGradient degrade(0,0,300,100);
            degrade.setColorAt(0,QColor(0,0,0));
            degrade.setColorAt(1,QColor(255,0,0));
            rectGradItem->setBrush(degrade);
            rectGradItem->setFlag(QGraphicsItem::ItemIsMovable);

    */

    /*
    // Cercle Cradient
    QGraphicsEllipseItem *cercleGradient = new QGraphicsEllipseItem(100,100,100,100);
    cercleGradient->setPen(noir);
    QLinearGradient degrade(100,20,150,0);
    degrade.setColorAt(0,QColor(blanc));
    degrade.setColorAt(1,QColor(bleu));
    cercleGradient->setBrush(degrade);
    cercleGradient->setFlag(QGraphicsItem::ItemIsMovable);
    */


    // Flocon de neige
    QPolygon poly3;
    poly3.setPoints(66,304,11,353,11,352,122,440,66,458,106,352,177,352,329,480,254,491,131,529,119,527,222,616,172,653,215,558,265,645,312,623,345,507,293,371,371,505,451,620,395,646,427,556,474,651,528,626,571,527,519,531,623,492,610,482,495,355,413,351,561,454,638,441,668,352,612,353,726,307,726,309,615,217,675,199,632,306,562,308,411,177,487,170,613,130,621,133,519,37,571,9,528,106,470,13,428,35,394,151,448,289,369,156,293,38,345,17,313,105,266,12,210,40,169,133,223,127,120,167,133,180,249,308,331,309,179,203,108,216,65,308,123);
    QGraphicsPolygonItem *flocon = new QGraphicsPolygonItem(poly3);
    //contour
    flocon->setPen(noir);
    flocon->setBrush(bleu);
    flocon->setFlag(QGraphicsItem::ItemIsMovable);
    flocon->setScale(0.5);



    // ajout a la scene

    // scene->addItem(etoile);
    // scene->addItem(etoileRayure);
    // scene->addItem(ovale);
    // scene->addItem(cercle);
    // scene->addItem(triangle);
    // scene->addItem(rectangle);
    // scene->addItem(rectGradItem);
    // scene->addItem(cercleGradient);
     scene->addItem(flocon);


}
























