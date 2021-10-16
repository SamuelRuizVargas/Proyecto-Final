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

//Login de usuarios
void Interfaz::dibujarMenu()
{

    menu.append(new Imagenes(-11,0,1281,651,2)); // Background
    menu.append(new Imagenes(275,-100,700,400,1)); // Logo

    QList<Imagenes*>::iterator it;
    int cont = 0;
    for(it = menu.begin(); it!= menu.end(); it++){
        scene->addItem(menu.at(cont));
        cont++;
    }
    boton_p = new botones;
    scene->addItem(boton_p);


}

void Interfaz::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //mirar donde poner esto
}

