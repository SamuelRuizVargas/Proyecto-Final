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
    crearLevelTwo();
    crearLevelThree();
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
    //-------------------Imagenes---------------
    imagenes_lvl1.append(new Imagenes(0,0,1281,651,3)); // Background

    QList<Imagenes*>::iterator it;
    int cont = 0;
    for(it = imagenes_lvl1.begin(); it!= imagenes_lvl1.end(); it++)
    {
        level_one->addItem(imagenes_lvl1.at(cont));
        cont++;
    }
    //------------------------------------------

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

void Interfaz::crearLevelTwo()//Crea y agrega los elementos del nivel 2
{
    //-------------------Imagenes---------------
    imagenes_lvl2.append(new Imagenes(0,0,1281,651,4)); // Background

    QList<Imagenes*>::iterator it;
    int cont = 0;
    for(it = imagenes_lvl2.begin(); it!= imagenes_lvl2.end(); it++)
    {
        level_two->addItem(imagenes_lvl2.at(cont));
        cont++;
    }
    //------------------------------------------

    //-----------------Se saca la base del mapa------------------
    ifstream archivo;
    string coorde,numero,int1,int2,int3,int4,digi;
    int ente1,ente2,ente3,ente4,len,conta;
    archivo.open(PATH_BASE_LVL2, ios::in);
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
        base_lvl2.append(new plataforma(ente1,ente2,ente3,ente4));
        level_two->addItem(base_lvl2.back());
    }
    archivo.close();
    //------------------------------------------------------------
}

void Interfaz::crearLevelThree()
{
    //-------------------Imagenes---------------
    imagenes_lvl3.append(new Imagenes(0,0,1281,651,5)); // Background

    QList<Imagenes*>::iterator it;
    int cont = 0;
    for(it = imagenes_lvl3.begin(); it!= imagenes_lvl3.end(); it++)
    {
        level_three->addItem(imagenes_lvl3.at(cont));
        cont++;
    }
    //------------------------------------------

    //-----------------Se saca la base del mapa------------------
    ifstream archivo;
    string coorde,numero,int1,int2,int3,int4,digi;
    int ente1,ente2,ente3,ente4,len,conta;
    archivo.open(PATH_BASE_LVL3, ios::in);
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
        base_lvl3.append(new plataforma(ente1,ente2,ente3,ente4));
        level_three->addItem(base_lvl3.back());
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
//           level_one->setSceneRect(0,0,1281,651);
//           ui->graphicsView->setScene(level_one);//cambio de escena para probar el lvl 1

//           level_two->setSceneRect(0,0,1281,651);
//           ui->graphicsView->setScene(level_two);//cambio de escena para probar el lvl 2

           level_three->setSceneRect(0,0,1281,651);
           ui->graphicsView->setScene(level_three);//cambio de escena para probar el lvl 3
        }
        cont++;
    }
}
