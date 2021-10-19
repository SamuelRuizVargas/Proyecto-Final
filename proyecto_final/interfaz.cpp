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

//Creación de niveles
void Interfaz::dibujarMenu()
{
    //Imagenes
    menu.append(new Imagenes(-11,0,1281,651,2)); // Background
    menu.append(new Imagenes(275,-100,700,400,1)); // Logo

    QList<Imagenes*>::iterator it;
    int cont = 0;
    for(it = menu.begin(); it!= menu.end(); it++)
    {
        scene->addItem(menu.at(cont));
        cont++;
    }
    //Botones
    buttons.append(new botones(525,275,225,75,1));
    buttons.append(new botones(525,350,225,75,2));

    QList<botones*>::iterator ite;
    cont = 0;
    for(ite = buttons.begin(); ite!= buttons.end(); ite++)
    {
        scene->addItem(buttons.at(cont));
        cont++;
    }
}

void Interfaz::mousePressEvent(QMouseEvent *event)
{

    QList<botones*>::iterator ite;
    int cont =0;
    for(ite = buttons.begin(); ite!= buttons.end(); ite++)
    {
    bool Press = buttons.at(cont)->get_Pressed();
    if(Press){
       Level_one();
    }

    cont++;
   }

}

void Interfaz::Level_one()
{
    ui->graphicsView->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();


    level_one = new QGraphicsScene;
    ui->graphicsView->setScene(level_one);
    ui->graphicsView->show();
}
