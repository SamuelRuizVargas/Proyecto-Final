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

    //dibujos
    dibujarMenu();

    //mostrar escena
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

Interfaz::~Interfaz()
{
    delete ui;
}

void Interfaz::dibujarMenu()
{
    menu.append(new Imagenes(250,-100,700,400));
    scene->addItem(menu.back());
}

void Interfaz::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //mirar donde poner esto
}

