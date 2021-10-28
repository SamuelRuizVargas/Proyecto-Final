#include "interfaz.h"
#include "ui_interfaz.h"

int vidas=3;
int listabase;
Interfaz::Interfaz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interfaz)
{
    ui->setupUi(this);

    //----------Escenas----------
            //Principal
    menu_princi = new QGraphicsScene;
    menu_princi->setSceneRect(0,0,1260,650);
            //Nivel 1
    level_one = new QGraphicsScene;
            //Nivel 2
    level_two = new QGraphicsScene;
            //Nivel 3
    level_three = new QGraphicsScene;
    //----------------------------

    //----Crear objetos en escenas-----
    crearMenu();
    crearLevelOne();
    crearLevelTwo();
    crearLevelThree();
    //---------------------------------

    //----------Timers------------------
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

    timer_standard=new QTimer(this);
    connect(timer_standard,SIGNAL(timeout()),this,SLOT(standard()));
    //---------------------------------

    //--------Interfaz niveles---------
//    ui->lcdTiempo->display(100);
//    ui->lcdVidas->display(vidas);
    ui->lcdEnemigos->hide();
    ui->lcdVidas->hide();
    ui->lcdTiempo->hide();
    ui->lcdPuntaje->hide();
    ui->labelEnemigos->hide();
    ui->labelVidas->hide();
    ui->labelPuntaje->hide();
    ui->labelTiempo->hide();
    ui->VidaBoss->hide();
    //---------------------------------

}

Interfaz::~Interfaz()
{
    delete ui;
}

void Interfaz::actualizar()//se encarga de los movimientos del personaje
{
    if(jugador1->getcaida()){
        int copy_y=jugador1->getY(),copy_x=jugador1->getX();
        jugador1->free(0.1f);
        jugador1->setPos(jugador1->getX(),jugador1->getY());
        if(evaluarColisionSalto(jugador1, listabase)==1)
        {
            jugador1->resetVX();
            jugador1->setposis(copy_x,copy_y);
            jugador1->setPos(jugador1->getX(),jugador1->getY());
        }
        else if(evaluarColisionJugador(jugador1, listabase))
        {
            timer->stop();
            jugador1->setposis(copy_x,copy_y);
            jugador1->setPos(jugador1->getX(),jugador1->getY());
            jugador1->resetVX();
            jugador1->resetVY();
            jugador1->resetVY2();
        }
    }
    else{
        int copy_y=jugador1->getY(),copy_x=jugador1->getX();
        jugador1->jump(0.1f);
        jugador1->setPos(jugador1->getX(),jugador1->getY());
        if(evaluarColisionSalto(jugador1, listabase)==1)
        {
            jugador1->resetVX();
            jugador1->setposis(copy_x,copy_y);
            jugador1->setPos(jugador1->getX(),jugador1->getY());
        }
        else if(evaluarColisionSalto(jugador1, listabase)==2)
        {
            jugador1->zeroVY();
            jugador1->setposis(copy_x,copy_y);
            jugador1->setPos(jugador1->getX(),jugador1->getY());
        }
        else if(evaluarColisionJugador(jugador1, listabase))
        {
            timer->stop();
            jugador1->setposis(copy_x,copy_y);
            jugador1->setPos(jugador1->getX(),jugador1->getY());
            jugador1->resetVX();
            jugador1->resetVY();
            jugador1->changedown();
        }
    }

}

int conta_1sec=0;
int conta_3sec=0;
void Interfaz::standard()//se encarga de todo lo que necesite un timer
{
    //---------------Mover enemigos---------------
    {
        QList<enemigo*>::iterator ite;
        switch (listabase)
        {
            case 1:
            {
                int contador=0;
                for(ite=enemigos_lvl1.begin();ite!=enemigos_lvl1.end();ite++)
                {
                    int taip=enemigos_lvl1[contador]->getTipo();
                    if(taip==1 or taip==3)
                    {
                        enemigo_act=enemigos_lvl1[contador];
                        bool moverse=enemigo_act->getMov();
                        if(moverse==true)
                        {
                            enemigo_act->moveLeft();
                            if(evaluarColisionEnemies(listabase))
                            {
                                enemigos_lvl1[contador]->movOriginal();
                                enemigos_lvl1[contador]->moveRight();
                                enemigos_lvl1[contador]->moveRight();
                            }
                            enemigos_lvl1[contador]->moveLeft();
                        }
                        else
                        {
                            enemigo_act->moveRight();
                            if(evaluarColisionEnemies(listabase))
                            {
                                enemigos_lvl1[contador]->movOriginal();
                                enemigos_lvl1[contador]->moveLeft();
                                enemigos_lvl1[contador]->moveLeft();
                            }
                            enemigos_lvl1[contador]->moveRight();
                        }
                    }
                    contador++;
                }
            }break;
            case 2:
            {
                int contador=0;
                for(ite=enemigos_lvl2.begin();ite!=enemigos_lvl2.end();ite++)
                {
                    int taip=enemigos_lvl2[contador]->getTipo();
                    if(taip==1 or taip==3)
                    {
                        enemigo_act=enemigos_lvl2[contador];
                        bool moverse=enemigo_act->getMov();
                        if(moverse==true)
                        {
                            enemigo_act->moveLeft();
                            if(evaluarColisionEnemies(listabase))
                            {
                                enemigos_lvl2[contador]->movOriginal();
                                enemigos_lvl2[contador]->moveRight();
                                enemigos_lvl2[contador]->moveRight();
                            }
                            enemigos_lvl2[contador]->moveLeft();
                        }
                        else
                        {
                            enemigo_act->moveRight();
                            if(evaluarColisionEnemies(listabase))
                            {
                                enemigos_lvl2[contador]->movOriginal();
                                enemigos_lvl2[contador]->moveLeft();
                                enemigos_lvl2[contador]->moveLeft();
                            }
                            enemigos_lvl2[contador]->moveRight();
                        }
                    }
                    contador++;
                }
            }break;
            case 3:
            {
                int contador=0;
                for(ite=enemigos_lvl3.begin();ite!=enemigos_lvl3.end();ite++)
                {
                    int taip=enemigos_lvl3[contador]->getTipo();
                    if(taip==1 or taip==3)
                    {
                        enemigo_act=enemigos_lvl3[contador];
                        bool moverse=enemigo_act->getMov();
                        if(moverse==true)
                        {
                            enemigo_act->moveLeft();
                            if(evaluarColisionEnemies(listabase))
                            {
                                enemigos_lvl3[contador]->movOriginal();
                                enemigos_lvl3[contador]->moveRight();
                                enemigos_lvl3[contador]->moveRight();
                            }
                            enemigos_lvl3[contador]->moveLeft();
                        }
                        else
                        {
                            enemigo_act->moveRight();
                            if(evaluarColisionEnemies(listabase))
                            {
                                enemigos_lvl3[contador]->movOriginal();
                                enemigos_lvl3[contador]->moveLeft();
                                enemigos_lvl3[contador]->moveLeft();
                            }
                            enemigos_lvl3[contador]->moveRight();
                        }
                    }
                    contador++;
                }
            }break;
        }
    }
    //--------------------------------------------

    //------------Mover balas jugador-------------
    {
        QList<proyectil*>::iterator ite;

        if(!balas_jugador1.empty())
        {
            int contador=0;
            for(ite=balas_jugador1.begin();ite!=balas_jugador1.end();ite++)
            {
                balas_jugador1[contador]->disparo();
                balas_jugador1[contador]->setPos(balas_jugador1[contador]->getX(),balas_jugador1[contador]->getY());
                double tiempo=balas_jugador1[contador]->getTempo();
                bool colide=evaluarColisionBullet(balas_jugador1[contador],listabase);
                if(tiempo>=2.5f or colide==true)
                {
                    if(listabase==1)
                    {
                        level_one->removeItem(balas_jugador1.at(contador));
                        balas_jugador1.removeAt(contador);
                        break;
                    }
                    else if(listabase==2)
                    {
                        level_two->removeItem(balas_jugador1.at(contador));
                        balas_jugador1.removeAt(contador);
                        break;
                    }
                    else if(listabase==3)
                    {
                        level_three->removeItem(balas_jugador1.at(contador));
                        balas_jugador1.removeAt(contador);
                        break;
                    }
                }
                contador++;
            }
        }
    }
    //--------------------------------------------

    //------------Disparos enemigos---------------
    {
        conta_1sec+=20;
        if(conta_1sec==1000)
        {
            QList<enemigo*>::iterator ite;

            switch (listabase)
            {
                case 1:
                {
                    int contador=0;
                    for(ite=enemigos_lvl1.begin();ite!=enemigos_lvl1.end();ite++)
                    {
                        if(enemigos_lvl1[contador]->getTipo()==3)
                        {
                            int postionx=enemigos_lvl1[contador]->getX(), postiony=enemigos_lvl1[contador]->getY();
                            bool side=enemigos_lvl1[contador]->getMov();
                            if(side==true)
                            {
                                balas_enemigos.append(new proyectil(postionx,postiony+20,-10,0,20,20,1));
                            }
                            else
                            {
                                balas_enemigos.append(new proyectil(postionx,postiony+20,10,0,20,20,1));
                            }
                            level_one->addItem(balas_enemigos.back());
                        }
                        contador++;
                    }
                }break;
                case 2:
                {
                    int contador=0;
                    for(ite=enemigos_lvl2.begin();ite!=enemigos_lvl2.end();ite++)
                    {
                        if(enemigos_lvl2[contador]->getTipo()==3)
                        {
                            int postionx=enemigos_lvl2[contador]->getX(), postiony=enemigos_lvl2[contador]->getY();
                            bool side=enemigos_lvl2[contador]->getMov();
                            if(side==true)
                            {
                                balas_enemigos.append(new proyectil(postionx,postiony+20,-10,0,20,20,1));
                            }
                            else
                            {
                                balas_enemigos.append(new proyectil(postionx,postiony+20,10,0,20,20,1));
                            }
                            level_two->addItem(balas_enemigos.back());
                        }
                        contador++;
                    }
                }break;
                case 3:
                {
                    int contador=0;
                    for(ite=enemigos_lvl3.begin();ite!=enemigos_lvl3.end();ite++)
                    {
                        if(enemigos_lvl3[contador]->getTipo()==3)
                        {
                            int postionx=enemigos_lvl3[contador]->getX(), postiony=enemigos_lvl3[contador]->getY();
                            bool side=enemigos_lvl3[contador]->getMov();
                            if(side==true)
                            {
                                balas_enemigos.append(new proyectil(postionx,postiony+20,-10,0,20,20,1));
                            }
                            else
                            {
                                balas_enemigos.append(new proyectil(postionx,postiony+20,10,0,20,20,1));
                            }
                            level_three->addItem(balas_enemigos.back());
                        }
                        contador++;
                    }
                }break;
            }
            conta_1sec=0;
        }

        conta_3sec+=20;
        if(conta_3sec==3000)
        {
            QList<enemigo*>::iterator ite;

            switch (listabase)
            {
                case 1:
                {
                    int contador=0;
                    for(ite=enemigos_lvl1.begin();ite!=enemigos_lvl1.end();ite++)
                    {
                        if(enemigos_lvl1[contador]->getTipo()==2)
                        {
                            int postionx=enemigos_lvl1[contador]->getX(), postiony=enemigos_lvl1[contador]->getY();
                            int pox=jugador1->getX();
                            if(pox>=enemigos_lvl1[contador]->getX())
                            {
                                balas_enemigos.append(new proyectil(postionx,postiony-20,80,80,40,40,1));
                            }
                            else
                            {
                                balas_enemigos.append(new proyectil(postionx,postiony-20,-80,80,40,40,1));
                            }
                            level_one->addItem(balas_enemigos.back());
                        }
                        contador++;
                    }
                }break;
                case 2:
                {
                    int contador=0;
                    for(ite=enemigos_lvl2.begin();ite!=enemigos_lvl2.end();ite++)
                    {
                        if(enemigos_lvl2[contador]->getTipo()==2)
                        {
                            int postionx=enemigos_lvl2[contador]->getX(), postiony=enemigos_lvl2[contador]->getY();
                            int pox=jugador1->getX();
                            if(pox>=enemigos_lvl2[contador]->getX())
                            {
                                balas_enemigos.append(new proyectil(postionx,postiony-20,80,80,40,40,1));
                            }
                            else
                            {
                                balas_enemigos.append(new proyectil(postionx,postiony-20,-80,80,40,40,1));
                            }
                            level_two->addItem(balas_enemigos.back());
                        }
                        contador++;
                    }
                }break;
                case 3:
                {
                    int contador=0;
                    for(ite=enemigos_lvl3.begin();ite!=enemigos_lvl3.end();ite++)
                    {
                        if(enemigos_lvl3[contador]->getTipo()==2)
                        {
                            int postionx=enemigos_lvl3[contador]->getX(), postiony=enemigos_lvl3[contador]->getY();
                            int pox=jugador1->getX();
                            if(pox>=enemigos_lvl3[contador]->getX())
                            {
                                balas_enemigos.append(new proyectil(postionx,postiony-20,80,80,40,40,1));
                            }
                            else
                            {
                                balas_enemigos.append(new proyectil(postionx,postiony-20,-80,80,40,40,1));
                            }
                            level_three->addItem(balas_enemigos.back());
                        }
                        contador++;
                    }
                    contador=0;
                    for(ite=enemigos_lvl3.begin();ite!=enemigos_lvl3.end();ite++)
                    {
                        if(enemigos_lvl3[contador]->getTipo()==4)
                        {
                            int postionx=enemigos_lvl3[contador]->getX(), postiony=enemigos_lvl3[contador]->getY();
                            balas_enemigos.append(new proyectil(postionx-40,postiony+310,-5,0,35,35,3));
                            level_three->addItem(balas_enemigos.back());
                        }
                        contador++;
                    }
                }break;
            }
            conta_3sec=0;
        }

        QList<proyectil*>::iterator ite;

        if(!balas_enemigos.empty())
        {
            int contador=0;
            for(ite=balas_enemigos.begin();ite!=balas_enemigos.end();ite++)
            {
                balas_enemigos[contador]->disparo();
                balas_enemigos[contador]->setPos(balas_enemigos[contador]->getX(),balas_enemigos[contador]->getY());
                double tiempo=balas_enemigos[contador]->getTempo();
                bool colide=evaluarColisionBullet(balas_enemigos[contador],listabase);
                if(tiempo>=5 or colide==true)
                {
                    if(listabase==1)
                    {
                        level_one->removeItem(balas_enemigos.at(contador));
                        balas_enemigos.removeAt(contador);
                        break;
                    }
                    else if(listabase==2)
                    {
                        level_two->removeItem(balas_enemigos.at(contador));
                        balas_enemigos.removeAt(contador);
                        break;
                    }
                    else if(listabase==3)
                    {
                        level_three->removeItem(balas_enemigos.at(contador));
                        balas_enemigos.removeAt(contador);
                        break;
                    }
                }
                contador++;
            }
        }
    }
    //--------------------------------------------
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
        menu_princi->addItem(menu.at(cont));
        cont++;
    }
    //------------------------------------------

    //------------------Botones-----------------
    buttons.append(new botones(525,275,225,75,1));
    buttons.append(new botones(525,350,225,75,2));
    buttons.append(new botones(525,275,225,75,3));
    buttons.append(new botones(525,350,225,75,3));
    buttons.append(new botones(525,425,225,75,3));

    menu_princi->addItem(buttons.at(0));
    menu_princi->addItem(buttons.at(1));
    //------------------------------------------
    //Set Scene para el menu inicial
    ui->graphicsView->setScene(menu_princi);
}

void Interfaz::crearLevelOne()//Crea y agrega los elementos del nivel 1
{
    //-----------------------Limites enemigos---------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,digi;
        int ente1,ente2,ente3,ente4,len,conta;
        archivo.open(PATH_LIMITS_LVL1, ios::in);
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
            limites_lvl1.append(new plataforma(ente1,ente2,ente3,ente4,2));
            level_one->addItem(limites_lvl1.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //---------------------------Imagenes-------------------------
    {
        imagenes_lvl1.append(new Imagenes(0,0,2500,1200,3)); // Background

        QList<Imagenes*>::iterator it;
        int cont = 0;
        for(it = imagenes_lvl1.begin(); it!= imagenes_lvl1.end(); it++)
        {
            level_one->addItem(imagenes_lvl1.at(cont));
            cont++;
        }
    }
    //------------------------------------------------------------

    //-----------------------Paredes del mapa---------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,digi;
        int ente1,ente2,ente3,ente4,len,conta;
        archivo.open(PATH_PARED_LVL1, ios::in);
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
            pared_lvl1.append(new plataforma(ente1,ente2,ente3,ente4,2));
            level_one->addItem(pared_lvl1.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //-----------------------Bajos del mapa-----------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,digi;
        int ente1,ente2,ente3,ente4,len,conta;
        archivo.open(PATH_BAJOS_LVL1, ios::in);
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
            bajos_lvl1.append(new plataforma(ente1,ente2,ente3,ente4,2));
            level_one->addItem(bajos_lvl1.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //-----------------Se saca la base del mapa-------------------
    {
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
            base_lvl1.append(new plataforma(ente1,ente2,ente3,ente4,1));
            level_one->addItem(base_lvl1.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //--------------------------Enemigos--------------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,int5,digi;
        int ente1,ente2,ente3,ente4,ente5,len,conta;
        archivo.open(PATH_ENE_LVL1, ios::in);
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
                    else if(conta==5)
                        int5+=numero;
                    numero.erase();
                }
            }
            ente1=atoi(int1.c_str());
            ente2=atoi(int2.c_str());
            ente3=atoi(int3.c_str());
            ente4=atoi(int4.c_str());
            ente5=atoi(int5.c_str());
            int1.erase();
            int2.erase();
            int3.erase();
            int4.erase();
            int5.erase();
            enemigos_lvl1.append(new enemigo(ente1,ente2,ente3,ente4,ente5));
            level_one->addItem(enemigos_lvl1.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------
}

void Interfaz::crearLevelTwo()//Crea y agrega los elementos del nivel 2
{

    //-----------------------Limites enemigos---------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,digi;
        int ente1,ente2,ente3,ente4,len,conta;
        archivo.open(PATH_LIMITS_LVL2, ios::in);
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
            limites_lvl2.append(new plataforma(ente1,ente2,ente3,ente4,2));
            level_two->addItem(limites_lvl2.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //---------------------------Imagenes-------------------------
    {
        imagenes_lvl2.append(new Imagenes(0,0,2500,1200,4)); // Background

        QList<Imagenes*>::iterator it;
        int cont = 0;
        for(it = imagenes_lvl2.begin(); it!= imagenes_lvl2.end(); it++)
        {
            level_two->addItem(imagenes_lvl2.at(cont));
            cont++;
        }
    }
    //------------------------------------------------------------

    //-----------------------Paredes del mapa---------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,digi;
        int ente1,ente2,ente3,ente4,len,conta;
        archivo.open(PATH_PARED_LVL2, ios::in);
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
            pared_lvl2.append(new plataforma(ente1,ente2,ente3,ente4,2));
            level_two->addItem(pared_lvl2.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //-----------------------Bajos del mapa-----------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,digi;
        int ente1,ente2,ente3,ente4,len,conta;
        archivo.open(PATH_BAJOS_LVL2, ios::in);
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
            bajos_lvl2.append(new plataforma(ente1,ente2,ente3,ente4,2));
            level_two->addItem(bajos_lvl2.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //-----------------Se saca la base del mapa-------------------
    {
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
            base_lvl2.append(new plataforma(ente1,ente2,ente3,ente4,1));
            level_two->addItem(base_lvl2.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //--------------------------Enemigos--------------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,int5,digi;
        int ente1,ente2,ente3,ente4,ente5,len,conta;
        archivo.open(PATH_ENE_LVL2, ios::in);
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
                    else if(conta==5)
                        int5+=numero;
                    numero.erase();
                }
            }
            ente1=atoi(int1.c_str());
            ente2=atoi(int2.c_str());
            ente3=atoi(int3.c_str());
            ente4=atoi(int4.c_str());
            ente5=atoi(int5.c_str());
            int1.erase();
            int2.erase();
            int3.erase();
            int4.erase();
            int5.erase();
            enemigos_lvl2.append(new enemigo(ente1,ente2,ente3,ente4,ente5));
            level_two->addItem(enemigos_lvl2.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------
}

void Interfaz::crearLevelThree()//Crea y agrega los elementos del nivel 3
{
    //-----------------------Limites enemigos---------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,digi;
        int ente1,ente2,ente3,ente4,len,conta;
        archivo.open(PATH_LIMITS_LVL3, ios::in);
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
            limites_lvl3.append(new plataforma(ente1,ente2,ente3,ente4,2));
            level_three->addItem(limites_lvl3.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //---------------------------Imagenes-------------------------
    {
        imagenes_lvl3.append(new Imagenes(0,0,2500,681,5)); // Background

        QList<Imagenes*>::iterator it;
        int cont = 0;
        for(it = imagenes_lvl3.begin(); it!= imagenes_lvl3.end(); it++)
        {
            level_three->addItem(imagenes_lvl3.at(cont));
            cont++;
        }
    }
    //------------------------------------------------------------

    //-----------------------Paredes del mapa---------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,digi;
        int ente1,ente2,ente3,ente4,len,conta;
        archivo.open(PATH_PARED_LVL3, ios::in);
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
            pared_lvl3.append(new plataforma(ente1,ente2,ente3,ente4,2));
            level_three->addItem(pared_lvl3.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //-----------------------Bajos del mapa-----------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,digi;
        int ente1,ente2,ente3,ente4,len,conta;
        archivo.open(PATH_BAJOS_LVL3, ios::in);
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
            bajos_lvl3.append(new plataforma(ente1,ente2,ente3,ente4,2));
            level_three->addItem(bajos_lvl3.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //------------------------Base del mapa-----------------------
    {
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
            base_lvl3.append(new plataforma(ente1,ente2,ente3,ente4,1));
            level_three->addItem(base_lvl3.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //--------------------------Enemigos--------------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,int5,digi;
        int ente1,ente2,ente3,ente4,ente5,len,conta;
        archivo.open(PATH_ENE_LVL3, ios::in);
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
                    else if(conta==5)
                        int5+=numero;
                    numero.erase();
                }
            }
            ente1=atoi(int1.c_str());
            ente2=atoi(int2.c_str());
            ente3=atoi(int3.c_str());
            ente4=atoi(int4.c_str());
            ente5=atoi(int5.c_str());
            int1.erase();
            int2.erase();
            int3.erase();
            int4.erase();
            int5.erase();
            enemigos_lvl3.append(new enemigo(ente1,ente2,ente3,ente4,ente5));
            level_three->addItem(enemigos_lvl3.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------
}

bool Interfaz::evaluarColisionJugador(personaje *personaje, int lista)//Evalua si el jugador choca caminando
{
    QList<plataforma*>::iterator it;

    switch (lista)
    {
        case 1:
        {
            for(it=base_lvl1.begin();it!=base_lvl1.end();it++)
            {
                if(personaje->collidesWithItem(*it))
                {
                    return true;
                }
            }
        }break;
        case 2:
        {
            for(it=base_lvl2.begin();it!=base_lvl2.end();it++)
            {
                if(personaje->collidesWithItem(*it))
                {
                    return true;
                }
            }
        }break;
        case 3:
        {
            for(it=base_lvl3.begin();it!=base_lvl3.end();it++)
            {
                if(personaje->collidesWithItem(*it))
                {
                    return true;
                }
            }
        }break;
    }
    return false;
}

bool Interfaz::evaluarColisionEnemies(int lista)//Evalua las colisiones de los enemigos con sus limites de movimiento
{
    QList<plataforma*>::iterator it;

    switch (lista)
    {
        case 1:
        {
            for(it=limites_lvl1.begin();it!=limites_lvl1.end();it++)
            {
                if(enemigo_act->collidesWithItem(*it))
                {
                    return true;
                }
            }
        }break;
        case 2:
        {
            for(it=limites_lvl2.begin();it!=limites_lvl2.end();it++)
            {
                if(enemigo_act->collidesWithItem(*it))
                {
                    return true;
                }
            }
        }break;
        case 3:
        {
            for(it=limites_lvl3.begin();it!=limites_lvl3.end();it++)
            {
                if(enemigo_act->collidesWithItem(*it))
                {
                    return true;
                }
            }
        }break;
    }
    return false;
}

int Interfaz::evaluarColisionSalto(personaje *personaje , int lista)//revisa las colisiones al saltar
{
    QList<plataforma*>::iterator it;
    //cambiar esta parte para que sirva de manera general
    switch (lista)
    {
        case 1:
        {
            for(it=pared_lvl1.begin();it!=pared_lvl1.end();it++)
            {
                if(personaje->collidesWithItem(*it))
                {
                    return 1;
                }
            }
            for(it=bajos_lvl1.begin();it!=bajos_lvl1.end();it++)
            {
                if(personaje->collidesWithItem(*it))
                {
                    return 2;
                }
            }
        }break;
        case 2:
        {
            for(it=pared_lvl2.begin();it!=pared_lvl2.end();it++)
            {
                if(personaje->collidesWithItem(*it))
                {
                    return 1;
                }
            }
            for(it=bajos_lvl2.begin();it!=bajos_lvl2.end();it++)
            {
                if(personaje->collidesWithItem(*it))
                {
                    return 2;
                }
            }
        }break;
        case 3:
        {
            for(it=pared_lvl3.begin();it!=pared_lvl3.end();it++)
            {
                if(personaje->collidesWithItem(*it))
                {
                    return 1;
                }
            }
            for(it=bajos_lvl3.begin();it!=bajos_lvl3.end();it++)
            {
                if(personaje->collidesWithItem(*it))
                {
                    return 2;
                }
            }
        }break;
    }
    return 0;
}

bool Interfaz::evaluarColisionBullet(proyectil *bala, int lista)//revisa las colisiones de los proyectiles
{
    QList<plataforma*>::iterator it;

    switch (lista)
    {
        case 1:
        {
            for(it=base_lvl1.begin();it!=base_lvl1.end();it++)
            {
                if(bala->collidesWithItem(*it))
                {
                    return true;
                }
            }
        }break;
        case 2:
        {
            for(it=base_lvl2.begin();it!=base_lvl2.end();it++)
            {
                if(bala->collidesWithItem(*it))
                {
                    return true;
                }
            }
        }break;
        case 3:
        {
            for(it=base_lvl3.begin();it!=base_lvl3.end();it++)
            {
                if(bala->collidesWithItem(*it))
                {
                    return true;
                }
            }
        }break;
    }
    return false;
}

void Interfaz::changeTeclas()//cambia el estado de la posibilidad de capturar teclas
{
    if(teclas==false)teclas=true;
    else teclas=false;
}

void Interfaz::changeMapLocation()//cambia el focus del mapa
{
    if(izquierda_map==true)
    {
        switch (listabase)
        {
            case 1:
            {
                level_one->setSceneRect(1220,0,1281,651);
            }break;
            case 2:
            {
                level_two->setSceneRect(1220,0,1281,651);
            }break;
            case 3:
            {
                level_three->setSceneRect(1220,0,1281,651);
            }break;
        }
        izquierda_map=false;
    }
    else if(izquierda_map==false)
    {
        switch (listabase)
        {
            case 1:
            {
                level_one->setSceneRect(0,0,1281,651);
            }break;
            case 2:
            {
                level_two->setSceneRect(0,0,1281,651);
            }break;
            case 3:
            {
                level_three->setSceneRect(0,0,1281,651);
            }break;
        }
        izquierda_map=true;
    }
}
/*
void Interfaz::validacion()
{

}
*/
void Interfaz::mousePressEvent(QMouseEvent *event)//Evento de clic con mouse
{
    //---------------Menu Principal--------------
    cont++;
    if(buttons.at(0)->get_Pressed())
    {
//        if(cont==1)validacion();

        menu_princi->removeItem(buttons.at(0));
        menu_princi->removeItem(buttons.at(1));

        menu_princi->addItem(buttons.at(2));
        menu_princi->addItem(buttons.at(3));
        menu_princi->addItem(buttons.at(4));
    }
    else if(buttons.at(1)->get_Pressed())
    {
        //hacer botones para partidas (pensar luego)
    }
    //-------------------------------------------

    //----------Partidas un jugador--------------USANDO PARA PROBAR NIVELES
    if(buttons.at(2)->get_Pressed())
    {
        jugador1 = new personaje(35,585);
        level_one->setSceneRect(0,0,1281,651);
        level_one->addItem(jugador1);
        ui->graphicsView->setScene(level_one); //cambio de escena para probar el lvl 1
        timer_standard->start(20);
        listabase = 1;
        changeTeclas();
    }
    if(buttons.at(3)->get_Pressed())
    {
        jugador1 = new personaje(35,585);
        level_two->setSceneRect(0,0,1281,651);
        level_two->addItem(jugador1);
        ui->graphicsView->setScene(level_two);//cambio de escena para probar el lvl 2
        timer_standard->start(20);
        listabase = 2;
        changeTeclas();
    }
    if(buttons.at(4)->get_Pressed())
    {
        jugador1 = new personaje(35,585);
        level_three->setSceneRect(0,0,1281,651);
        level_three->addItem(jugador1);
        ui->graphicsView->setScene(level_three);//cambio de escena para probar el lvl 3
        timer_standard->start(20);
        listabase = 3;
        changeTeclas();
    }
    //-------------------------------------------
}

QString Interfaz::letra(QString x)
{
    int id;
    id = QFontDatabase::addApplicationFont(x);

    QStringList letra = QFontDatabase::applicationFontFamilies(id);
    letra = letra.takeLast().split('.');

    return letra[0];
}

void Interfaz::keyPressEvent(QKeyEvent *i)//Evento de tecla presionada
{
    //----------------Movimiento--------------------------
    if(teclas==true)
    {
        if(i->key() == Qt::Key_D)
        {
            float poxixion=jugador1->getX();
            if(poxixion>=1260 and izquierda_map==true)
                changeMapLocation();
            else if(poxixion<1260 and izquierda_map==false)
                changeMapLocation();
            jugador1->setVX(7);
            timer->start(16);
            jugador1->moveRight();
            if(evaluarColisionJugador(jugador1, listabase))
            {
                jugador1->setVX(-7);
                jugador1->moveLeft();
            }
            else
                jugador1->setside(true);
        }
        else if(i->key() == Qt::Key_A)
        {
            float poxixion=jugador1->getX();
            if(poxixion>=1260 and izquierda_map==true)
                changeMapLocation();
            else if(poxixion<1260 and izquierda_map==false)
                changeMapLocation();
            jugador1->setVX(-7);
            timer->start(16);
            jugador1->moveLeft();
            if(evaluarColisionJugador(jugador1, listabase))
            {
                jugador1->setVX(7);
                jugador1->moveRight();
            }
            else
                jugador1->setside(false);
        }
        else if(i->key() == Qt::Key_W)
        {
            if(jugador1->getcaida())
                jugador1->changedown();
            jugador1->resetVX();
            timer->start(16);
        }
        else if(i->key() == Qt::Key_S)
        {
            if(balas_jugador1.count()<5)
            {
                switch (listabase)
                {
                    case 1:
                    {
                        float postionx=jugador1->getX(),postiony=jugador1->getY();
                        bool side=jugador1->getSide();
                        if(side==true)
                        {
                            balas_jugador1.append(new proyectil(postionx+5,postiony+18,5,0,15,15,2));
                        }
                        else
                        {
                            balas_jugador1.append(new proyectil(postionx+5,postiony+18,-5,0,15,15,2));
                        }
                        level_one->addItem(balas_jugador1.back());
                    }break;
                    case 2:
                    {
                        float postionx=jugador1->getX(),postiony=jugador1->getY();
                        bool side=jugador1->getSide();
                        if(side==true)
                        {
                            balas_jugador1.append(new proyectil(postionx+5,postiony+18,5,0,15,15,2));
                        }
                        else
                        {
                            balas_jugador1.append(new proyectil(postionx+5,postiony+18,-5,0,15,15,2));
                        }
                        level_two->addItem(balas_jugador1.back());
                    }break;
                    case 3:
                    {
                        float postionx=jugador1->getX(),postiony=jugador1->getY();
                        bool side=jugador1->getSide();
                        if(side==true)
                        {
                            balas_jugador1.append(new proyectil(postionx+5,postiony+18,5,0,15,15,2));
                        }
                        else
                        {
                            balas_jugador1.append(new proyectil(postionx+5,postiony+18,-5,0,15,15,2));
                        }
                        level_three->addItem(balas_jugador1.back());
                    }break;
                }
            }
        }
    }
    //----------------------------------------------------
}

