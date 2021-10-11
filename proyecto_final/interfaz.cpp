#include "interfaz.h"
#include "ui_interfaz.h"

Interfaz::Interfaz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interfaz)
{
    ui->setupUi(this);

    //Se crea la escena
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,1260,650);

    //logo
    QImage im(":/imagenes/logo.png");
    QBrush hola(im);
    logo.push_back(scene->addRect(0,0,700,400,Qt::NoPen,hola));

    //mostrar escena
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

Interfaz::~Interfaz()
{
    delete ui;
}

