#include "interfaz.h"
#include "ui_interfaz.h"

Interfaz::Interfaz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interfaz)
{
    ui->setupUi(this);

    //----------Escenas----------
            //Principal
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,1260,650);
            //Nivel 1
    level_one = new QGraphicsScene;
            //Nivel 2
    level_two = new QGraphicsScene;
            //Nivel 3
    level_three = new QGraphicsScene;
            //BossFight
    bossfight = new QGraphicsScene;
    //----------------------------

    //----Crear objetos en escenas-----
    crearMenu();
    crearLevelOne();
    //---------------------------------
}

Interfaz::~Interfaz()
{
    delete ui;
}

void Interfaz::crearMenu()//Crea y agrega los elementos del menu inicial
{
    //-------------------Imagenes---------------
    menu.append(new Imagenes(-11,0,1281,651,2)); // Background
    menu.append(new Imagenes(275,-100,700,400,1)); // Logo

    QList<Imagenes*>::iterator it;
    int cont = 0;
    for(it = menu.begin(); it!= menu.end(); it++)
    {
        scene->addItem(menu.at(cont));
        cont++;
    }
    //------------------------------------------

    //------------------Botones-----------------
    buttons.append(new botones(525,275,225,75,1));
    buttons.append(new botones(525,350,225,75,2));

    QList<botones*>::iterator ite;
    cont = 0;
    for(ite = buttons.begin(); ite!= buttons.end(); ite++)
    {
        scene->addItem(buttons.at(cont));
        cont++;
    }
    //------------------------------------------
    //Set Scene para el menu inicial
    ui->graphicsView->setScene(scene);
}

void Interfaz::crearLevelOne()//Crea y agrega los elementos del nivel 1
{
    //-----------------Se saca la base del mapa------------------
    ifstream archivo;
    string coorde,numero,int1,int2,int3,int4,digi;
    int ente1,ente2,ente3,ente4,len,conta;
    archivo.open(PATH_BASE_LVL1, ios::in);
    while(!archivo.eof())
    {
        if (archivo.eof())
            break;
        getline(archivo,coorde);
        len=coorde.length();
        conta=0;
        for (int i=0; i<=len;i++)
        {
            digi=coorde[i];
            if (digi!="," and digi[0]!='\000' )
            {
                numero+=digi;
            }
            else
            {
                conta+=1;
                if(conta==1)
                    int1+=numero;
                else if(conta==2)
                    int2+=numero;
                else if(conta==3)
                    int3+=numero;
                else if(conta==4)
                    int4+=numero;
                numero.erase();
            }
        }
        ente1=atoi(int1.c_str());
        ente2=atoi(int2.c_str());
        ente3=atoi(int3.c_str());
        ente4=atoi(int4.c_str());
        int1.erase();
        int2.erase();
        int3.erase();
        int4.erase();
        base_lvl1.append(new plataforma(ente1,ente2,ente3,ente4));
        level_one->addItem(base_lvl1.back());
    }
    archivo.close();
    //------------------------------------------------------------
}

void Interfaz::mousePressEvent(QMouseEvent *event)//Evento de clic con mouse
{
    //Si se da click verificar si fue en algun boton (Esto para hacer las pruebas de los mapas)
    QList<botones*>::iterator ite;
    int cont =0;
    for(ite = buttons.begin(); ite!= buttons.end(); ite++)
    {
        bool Press = buttons.at(cont)->get_Pressed();
        if(Press)
        {
           ui->graphicsView->setScene(level_one);//cambio de escena para probar el lvl 1
        }
        cont++;
    }
}
