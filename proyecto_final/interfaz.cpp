#include "interfaz.h"
#include "ui_interfaz.h"

int vidas=3;
int vidas2=5;
int puntaje=0;
int listabase=0;
bool tiempo_paso=false;
bool cambiazo=false;
bool cambiazo2=false;
bool multijugador=false;

//variables de guardado
int vidas_save;
int puntaje_save;
int nivel_save;

Interfaz::Interfaz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interfaz)
{
    ui->setupUi(this);

    //----------Musica-----------
    playlist = new QMediaPlaylist();
    player = new QMediaPlayer(this);

    playlist->addMedia(QUrl("qrc:/audio/musica.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player->setPlaylist(playlist);
    player->setVolume(3);
    player->play();
    //---------------------------

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
            //Multijugador
    level_multi = new QGraphicsScene;
    //----------------------------

    //----Crear objetos en escenas-----
    crearMenu();
    crearLevelOne();
    crearLevelTwo();
    crearLevelThree();
    crearMulti();
    //---------------------------------

    //----------Timers------------------
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

    timer_standard=new QTimer(this);
    connect(timer_standard,SIGNAL(timeout()),this,SLOT(standard()));
    //---------------------------------

    //--------Interfaz niveles---------
    ui->lcdEnemigos->hide();
    ui->lcdVidas->hide();
    ui->lcdTiempo->hide();
    ui->lcdPuntaje->hide();
    ui->labelEnemigos->hide();
    ui->labelVidas->hide();
    ui->labelPuntaje->hide();
    ui->labelTiempo->hide();
    ui->VidaBoss->hide();

    ui->labelVidas_j1->hide();
    ui->labelVidas_j2->hide();
    ui->lcdVidas_J2->hide();

    ui->textUsuario->hide();
    ui->textContra->hide();
    ui->labelUsuarios->hide();
    ui->labelContra->hide();
    //---------------------------------
}

Interfaz::~Interfaz()
{
    delete ui;
}

void Interfaz::actualizar()//se encarga de los movimientos del personaje
{
    //-------------------------Multijugador-------------------------
    if(multijugador==true)
    {
                                //Jugador 1
        if(jugador1->getcaida())
        {
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
                //timer->stop();
                jugador1->setposis(copy_x,copy_y);
                jugador1->setPos(jugador1->getX(),jugador1->getY());
                jugador1->resetVX();
                jugador1->resetVY();
                jugador1->resetVY2();
            }
        }
        else
        {
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
                //timer->stop();
                jugador1->setposis(copy_x,copy_y);
                jugador1->setPos(jugador1->getX(),jugador1->getY());
                jugador1->resetVX();
                jugador1->resetVY();
                jugador1->changedown();
            }
        }
                                //Jugador 2
        if(jugador2->getcaida())
        {
            int copy_y=jugador2->getY(),copy_x=jugador2->getX();
            jugador2->free(0.1f);
            jugador2->setPos(jugador2->getX(),jugador2->getY());
            if(evaluarColisionSalto(jugador2, listabase)==1)
            {
                jugador2->resetVX();
                jugador2->setposis(copy_x,copy_y);
                jugador2->setPos(jugador2->getX(),jugador2->getY());
            }
            else if(evaluarColisionJugador(jugador2, listabase))
            {
                //timer->stop();
                jugador2->setposis(copy_x,copy_y);
                jugador2->setPos(jugador2->getX(),jugador2->getY());
                jugador2->resetVX();
                jugador2->resetVY();
                jugador2->resetVY2();
            }
        }
        else
        {
            int copy_y=jugador2->getY(),copy_x=jugador2->getX();
            jugador2->jump(0.1f);
            jugador2->setPos(jugador2->getX(),jugador2->getY());
            if(evaluarColisionSalto(jugador2, listabase)==1)
            {
                jugador2->resetVX();
                jugador2->setposis(copy_x,copy_y);
                jugador2->setPos(jugador2->getX(),jugador2->getY());
            }
            else if(evaluarColisionSalto(jugador2, listabase)==2)
            {
                jugador2->zeroVY();
                jugador2->setposis(copy_x,copy_y);
                jugador2->setPos(jugador2->getX(),jugador2->getY());
            }
            else if(evaluarColisionJugador(jugador2, listabase))
            {
                //timer->stop();
                jugador2->setposis(copy_x,copy_y);
                jugador2->setPos(jugador2->getX(),jugador2->getY());
                jugador2->resetVX();
                jugador2->resetVY();
                jugador2->changedown();
            }
        }
    }
    //--------------------------------------------------------------

    //---------------------------Un jugador-------------------------
    else
    {
        if(jugador1->getcaida())
        {
            int copy_y=jugador1->getY(),copy_x=jugador1->getX();
            jugador1->free(0.1f);
            jugador1->setPos(jugador1->getX(),jugador1->getY());
            if(copy_y>=650)
            {
                vidas-=1;
                ui->lcdVidas->display(vidas);
                if(vidas==0)
                {
                    timer_standard->stop();
                    QMessageBox::information(
                        this,
                        tr("GAME OVER"),
                        tr("Ultima vida perdida por una caida."));
                    volverMenu();
                    timer->stop();
                }
                switch (listabase)
                {
                    case 1:
                    {
                        jugador1 = new personaje(35,585,1);
                        level_one->addItem(jugador1);
                    }break;
                    case 2:
                    {
                        jugador1 = new personaje(35,585,1);
                        level_two->addItem(jugador1);
                    }break;
                    case 3:
                    {
                        jugador1 = new personaje(35,585,1);
                        level_three->addItem(jugador1);
                    }break;
                }
            }
            else if(evaluarColisionSalto(jugador1, listabase)==1)
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
        else
        {
            int copy_y=jugador1->getY(),copy_x=jugador1->getX();
            jugador1->jump(0.1f);
            jugador1->setPos(jugador1->getX(),jugador1->getY());
            if(copy_y>=650)
            {
                vidas-=1;
                ui->lcdVidas->display(vidas);
                if(vidas==0)
                {
                    timer_standard->stop();
                    QMessageBox::information(
                        this,
                        tr("GAME OVER"),
                        tr("Ultima vida perdida por una caida."));
                    volverMenu();
                    timer->stop();
                }
                switch (listabase)
                {
                    case 1:
                    {
                        jugador1 = new personaje(35,585,1);
                        level_one->addItem(jugador1);
                    }break;
                    case 2:
                    {
                        jugador1 = new personaje(35,585,1);
                        level_two->addItem(jugador1);
                    }break;
                    case 3:
                    {
                        jugador1 = new personaje(35,585,1);
                        level_three->addItem(jugador1);
                    }break;
                }
            }
            else if(evaluarColisionSalto(jugador1, listabase)==1)
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
    //--------------------------------------------------------------
}

int conta_1sec=0;
int conta_3sec=0;
int tiempo_pasa=0;
int conta_2sec=0;
bool reiniciar_conta=false;
bool seguirmoviendo=true;
void Interfaz::standard()//se encarga de todo lo que necesite un timer
{
    if(multijugador==true)
    {
        //------------Mover balas jugador-------------
        {
            QList<proyectil*>::iterator ite;
                        //Jugador 1
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
                        level_multi->removeItem(balas_jugador1.at(contador));
                        balas_jugador1.removeAt(contador);
                        break;
                    }
                    contador++;
                }
            }
                        //Jugador 2
            if(!balas_jugador2.empty())
            {
                int contador=0;
                for(ite=balas_jugador2.begin();ite!=balas_jugador2.end();ite++)
                {
                    balas_jugador2[contador]->disparo();
                    balas_jugador2[contador]->setPos(balas_jugador2[contador]->getX(),balas_jugador2[contador]->getY());
                    double tiempo=balas_jugador2[contador]->getTempo();
                    bool colide=evaluarColisionBullet2(balas_jugador2[contador]);
                    if(tiempo>=2.5f or colide==true)
                    {
                        level_multi->removeItem(balas_jugador2.at(contador));
                        balas_jugador2.removeAt(contador);
                        break;
                    }
                    contador++;
                }
            }
        }
        //--------------------------------------------

        //---------------inmortalidad-----------------
        {
            conta_2sec+=20;
            if(conta_2sec==2000)
            {
                if(cambiazo==true)
                {
                    jugador1->cambiar();
                    cambiazo=false;
                }
                if(cambiazo2==true)
                {
                    jugador2->cambiar();
                    cambiazo2=false;
                }
                conta_2sec=0;
            }
        }
        //--------------------------------------------
    }
    else
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
                        if(seguirmoviendo==true)
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
                        else
                            break;
                    }
                }break;
                case 2:
                {
                    int contador=0;
                    for(ite=enemigos_lvl2.begin();ite!=enemigos_lvl2.end();ite++)
                    {
                        if(seguirmoviendo==true)
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
                        else
                            break;
                    }
                }break;
                case 3:
                {
                    int contador=0;
                    for(ite=enemigos_lvl3.begin();ite!=enemigos_lvl3.end();ite++)
                    {
                        if(seguirmoviendo==true)
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
                        else
                            break;
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
                    bool colide=evaluarColisionBulletEne(balas_enemigos[contador],listabase);
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

        //------------------tiempo--------------------
        {
            tiempo_pasa+=20;
            if(tiempo_pasa==1000)
            {
                switch (listabase)
                {
                case 1:
                {
                    static int conta=1;
                    if(reiniciar_conta==true)
                    {
                        conta=1;
                        reiniciar_conta=false;
                    }
                    ui->lcdTiempo->display(30-conta);
                    if(30-conta<=0)
                    {
                        ui->lcdTiempo->display(0);
                        if(tiempo_paso==false)
                        {
                            vidas-=1;
                            ui->lcdVidas->display(vidas);
                            tiempo_paso=true;
                            if(vidas==0)
                            {
                                QMessageBox::information(
                                    this,
                                    tr("GAME OVER"),
                                    tr("Ultima vida perdida por el tiempo."));
                                    volverMenu();
                            }
                        }
                    }
                    conta++;
                    tiempo_pasa=0;
                }break;
                case 2:
                {
                    static int conta=1;
                    if(reiniciar_conta==true)
                    {
                        conta=1;
                        reiniciar_conta=false;
                    }
                    ui->lcdTiempo->display(50-conta);
                    if(50-conta<=0)
                    {
                        ui->lcdTiempo->display(0);
                        if(tiempo_paso==false)
                        {
                            vidas-=1;
                            ui->lcdVidas->display(vidas);
                            tiempo_paso=true;
                        }
                    }
                    conta++;
                    tiempo_pasa=0;
                }break;
                case 3:
                {
                    static int conta=1;
                    if(reiniciar_conta==true)
                    {
                        conta=1;
                        reiniciar_conta=false;
                    }
                    ui->lcdTiempo->display(60-conta);
                    if(60-conta<=0)
                    {
                        ui->lcdTiempo->display(0);
                        if(tiempo_paso==false)
                        {
                            vidas-=1;
                            ui->lcdVidas->display(vidas);
                            tiempo_paso=true;
                        }
                    }
                    conta++;
                    tiempo_pasa=0;
                }break;
                }
            }
        }
        //--------------------------------------------

        //---------------inmortalidad-----------------
        {
            conta_2sec+=20;
            if(conta_2sec==2000)
            {
                if(cambiazo==true)
                {
                    jugador1->cambiar();
                    cambiazo=false;
                }
                conta_2sec=0;
            }
        }
        //--------------------------------------------
    }
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
    buttons.append(new botones(525,275,225,75,4));
    buttons.append(new botones(525,350,225,75,3));
    buttons.append(new botones(575,330,120,40,4));

    menu_princi->addItem(buttons.at(0));
    menu_princi->addItem(buttons.at(1));
    //------------------------------------------
    //Set Scene para el menu inicial
    ui->graphicsView->setScene(menu_princi);
}

void Interfaz::clearMenu()
{
    menu.clear();
    buttons.clear();
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

void Interfaz::clearLevelOne()
{
    base_lvl1.clear();
    pared_lvl1.clear();
    bajos_lvl1.clear();
    limites_lvl1.clear();
    imagenes_lvl1.clear();
    enemigos_lvl1.clear();
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

void Interfaz::clearLevelTwo()
{
    base_lvl2.clear();
    pared_lvl2.clear();
    bajos_lvl2.clear();
    limites_lvl2.clear();
    imagenes_lvl2.clear();
    enemigos_lvl2.clear();
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

void Interfaz::clearLevelThree()
{
    base_lvl3.clear();
    pared_lvl3.clear();
    bajos_lvl3.clear();
    limites_lvl3.clear();
    imagenes_lvl3.clear();
    enemigos_lvl3.clear();
}

void Interfaz::crearMulti()//Crea y agrega los elementos del nivel multijugador
{
    //-----------------------Paredes del mapa---------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,digi;
        int ente1,ente2,ente3,ente4,len,conta;
        archivo.open(PATH_PARED_MULT, ios::in);
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
            pared_multi.append(new plataforma(ente1,ente2,ente3,ente4,2));
            level_multi->addItem(pared_multi.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //---------------------------Imagenes-------------------------
    {
        imagenes_multi.append(new Imagenes(0,0,1281,681,6)); // Background

        QList<Imagenes*>::iterator it;
        int cont = 0;
        for(it = imagenes_multi.begin(); it!= imagenes_multi.end(); it++)
        {
            level_multi->addItem(imagenes_multi.at(cont));
            cont++;
        }
    }
    //------------------------------------------------------------

    //-----------------------Bajos del mapa-----------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,digi;
        int ente1,ente2,ente3,ente4,len,conta;
        archivo.open(PATH_BAJOS_MULT, ios::in);
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
            bajos_multi.append(new plataforma(ente1,ente2,ente3,ente4,2));
            level_multi->addItem(bajos_multi.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------

    //------------------------Base del mapa-----------------------
    {
        ifstream archivo;
        string coorde,numero,int1,int2,int3,int4,digi;
        int ente1,ente2,ente3,ente4,len,conta;
        archivo.open(PATH_BASE_MULT, ios::in);
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
            base_multi.append(new plataforma(ente1,ente2,ente3,ente4,1));
            level_multi->addItem(base_multi.back());
        }
        archivo.close();
    }
    //------------------------------------------------------------
}

void Interfaz::clearMulti()
{
    base_multi.clear();
    pared_multi.clear();
    bajos_multi.clear();
    imagenes_multi.clear();
}

bool Interfaz::evaluarColisionJugador(personaje *personaje, int lista)//Evalua si el jugador choca caminando
{
    QList<plataforma*>::iterator it;
    QList<enemigo*>::iterator ite;

    if(multijugador==true)
    {
        for(it=base_multi.begin();it!=base_multi.end();it++)
        {
            if(personaje->collidesWithItem(*it))
            {
                return true;
            }
        }
    }
    else
    {
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
                bool inmo=jugador1->getInmo();
                if(personaje->collidesWithItem(enemigos_lvl3.at(0)))
                {
                    if(inmo==false)
                    {
                        vidas-=1;
                        ui->lcdVidas->display(vidas);
                        jugador1->cambiar();
                        cambiazo=true;
                        if(vidas==0)
                        {
                            QMessageBox::information(
                                this,
                                tr("GAME OVER"),
                                tr("Ultima vida perdida por el Boss Final."));
                                volverMenu();
                        }
                    }
                    return true;
                }
            }break;
        }
        return false;
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
            bool inmo=jugador1->getInmo();
            if(enemigo_act->collidesWithItem(jugador1))
            {
                if(inmo==false)
                {
                    vidas-=1;
                    ui->lcdVidas->display(vidas);
                    jugador1->cambiar();
                    cambiazo=true;
                    if(vidas==0)
                    {
                        timer->stop();
                        timer_standard->stop();
                        QMessageBox::information(
                            this,
                            tr("GAME OVER"),
                            tr("Ultima vida perdida por un enemigo."));
                        volverMenu();
                        seguirmoviendo=false;
                    }
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
            bool inmo=jugador1->getInmo();
            if(enemigo_act->collidesWithItem(jugador1))
            {
                if(inmo==false)
                {
                    vidas-=1;
                    ui->lcdVidas->display(vidas);
                    jugador1->cambiar();
                    cambiazo=true;
                    if(vidas==0)
                    {
                        timer->stop();
                        timer_standard->stop();
                        QMessageBox::information(
                            this,
                            tr("GAME OVER"),
                            tr("Ultima vida perdida por un enemigo."));
                        volverMenu();
                        seguirmoviendo=false;
                    }
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
            bool inmo=jugador1->getInmo();
            if(enemigo_act->collidesWithItem(jugador1))
            {
                if(inmo==false)
                {
                    vidas-=1;
                    ui->lcdVidas->display(vidas);
                    jugador1->cambiar();
                    cambiazo=true;
                    if(vidas==0)
                    {
                        timer->stop();
                        timer_standard->stop();
                        QMessageBox::information(
                            this,
                            tr("GAME OVER"),
                            tr("Ultima vida perdida por un enemigo."));
                        volverMenu();
                        seguirmoviendo=false;
                    }
                }
            }
        }break;
    }
    return false;
}

int Interfaz::evaluarColisionSalto(personaje *personaje , int lista)//revisa las colisiones al saltar
{
    QList<plataforma*>::iterator it;

    if(multijugador==true)
    {
        for(it=pared_multi.begin();it!=pared_multi.end();it++)
        {
            if(personaje->collidesWithItem(*it))
            {
                return 1;
            }
        }
        for(it=bajos_multi.begin();it!=bajos_multi.end();it++)
        {
            if(personaje->collidesWithItem(*it))
            {
                return 2;
            }
        }
        return 0;
    }
    else
    {
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
    return 0;
}

bool Interfaz::evaluarColisionBullet(proyectil *bala, int lista)//revisa las colisiones de los proyectiles
{
    QList<plataforma*>::iterator it;
    QList<enemigo*>::iterator ite;

    if(multijugador==true)
    {
        for(it=base_multi.begin();it!=base_multi.end();it++)
        {
            if(bala->collidesWithItem(*it))
            {
                return true;
            }
        }
        bool inmo=jugador2->getInmo();
        if(bala->collidesWithItem(jugador2))
        {
            if(inmo==false)
            {
                vidas2-=1;
                ui->lcdVidas_J2->display(vidas2);
                jugador2->cambiar();
                cambiazo2=true;
                if(vidas2==0)
                {
                    timer->stop();
                    timer_standard->stop();
                    QMessageBox::information(
                        this,
                        tr("GAME OVER"),
                        tr("GANA EL JUGADOR 1."));
                    volverMenu();
                }
                return true;
            }
        }
        return false;
    }
    else
    {
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
                int con=0;
                for(ite=enemigos_lvl1.begin();ite!=enemigos_lvl1.end();ite++)
                {
                    if(bala->collidesWithItem(*ite))
                    {
                        enemigos_lvl1[con]->minusLives();
                        int vidillas=enemigos_lvl1[con]->getLives();
                        if(vidillas==0)
                        {
                            level_one->removeItem(*ite);
                            enemigos_lvl1.removeAt(con);
                            puntaje+=500;
                            ui->lcdEnemigos->display(enemigos_lvl1.count());
                            if(enemigos_lvl1.count()==0)
                            {
                                nextMap();
                            }
                            ui->lcdPuntaje->display(puntaje);
                        }
                        return true;
                    }
                    con++;
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
                int con=0;
                for(ite=enemigos_lvl2.begin();ite!=enemigos_lvl2.end();ite++)
                {
                    if(bala->collidesWithItem(*ite))
                    {
                        enemigos_lvl2[con]->minusLives();
                        int vidillas=enemigos_lvl2[con]->getLives();
                        if(vidillas==0)
                        {
                            level_two->removeItem(*ite);
                            enemigos_lvl2.removeAt(con);
                            puntaje+=500;
                            ui->lcdEnemigos->display(enemigos_lvl2.count());
                            if(enemigos_lvl2.count()==0)
                            {
                                nextMap();
                            }
                            ui->lcdPuntaje->display(puntaje);
                        }
                        return true;
                    }
                    con++;
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
                int con=0;
                for(ite=enemigos_lvl3.begin();ite!=enemigos_lvl3.end();ite++)
                {
                    if(bala->collidesWithItem(*ite))
                    {
                        enemigos_lvl3[con]->minusLives();
                        int vidillas=enemigos_lvl3[con]->getLives(), tipo=enemigos_lvl3[con]->getTipo();
                        if(tipo==4)
                        {
                            ui->VidaBoss->setValue(vidillas);
                        }
                        if(vidillas==0)
                        {
                            if(tipo==4)
                            {
                                puntaje+=5000;
                                ui->lcdEnemigos->display(0);
                                timer->stop();
                                timer_standard->stop();
                                QMessageBox::information(
                                    this,
                                    tr("FELICITACIONES!!!"),
                                    tr("Has logrado terminar el juego."));
                                QMessageBox::information(this,
                                    tr("Julian"),
                                    tr("*Babeando su mesa*"),
                                    tr("-Eh? que paso, yo estaba... oh, solo fue un sueño."));
                                QMessageBox::information(
                                    this,
                                    tr("Narrador"),
                                    tr("O quizás no lo fue?..."));
                                volverMenu();
                            }
                            level_three->removeItem(*ite);
                            enemigos_lvl3.removeAt(con);
                            ui->lcdPuntaje->display(puntaje);
                            ui->VidaBoss->hide();
                        }
                        return true;
                    }
                    con++;
                }
            }break;
        }
        return false;
    }
    return false;
}

bool Interfaz::evaluarColisionBullet2(proyectil *bala)
{
    QList<plataforma*>::iterator it;
    for(it=base_multi.begin();it!=base_multi.end();it++)
    {
        if(bala->collidesWithItem(*it))
        {
            return true;
        }
    }
    bool inmo=jugador1->getInmo();
    if(bala->collidesWithItem(jugador1))
    {
        if(inmo==false)
        {
            vidas-=1;
            ui->lcdVidas->display(vidas);
            jugador1->cambiar();
            cambiazo=true;
            if(vidas==0)
            {
                timer->stop();
                timer_standard->stop();
                QMessageBox::information(
                    this,
                    tr("GAME OVER"),
                    tr("GANA EL JUGADOR 2."));
                volverMenu();
            }
            return true;
        }
    }
}

bool Interfaz::evaluarColisionBulletEne(proyectil *bala, int lista)//revisa las colisiones de los proyectiles enemigos
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
            bool inmo=jugador1->getInmo();
            if(bala->collidesWithItem(jugador1))
            {
                if(inmo==false)
                {
                    vidas-=1;
                    ui->lcdVidas->display(vidas);
                    jugador1->cambiar();
                    cambiazo=true;
                    if(vidas==0)
                    {
                        timer->stop();
                        timer_standard->stop();
                        QMessageBox::information(
                            this,
                            tr("GAME OVER"),
                            tr("Ultima vida perdida por una bala enemiga."));
                        volverMenu();
                    }
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
            bool inmo=jugador1->getInmo();
            if(bala->collidesWithItem(jugador1))
            {
                if(inmo==false)
                {
                    vidas-=1;
                    ui->lcdVidas->display(vidas);
                    jugador1->cambiar();
                    cambiazo=true;
                    if(vidas==0)
                    {
                        timer->stop();
                        timer_standard->stop();
                        QMessageBox::information(
                            this,
                            tr("GAME OVER"),
                            tr("Ultima vida perdida por una bala enemiga."));
                        volverMenu();
                    }
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
            bool inmo=jugador1->getInmo();
            if(bala->collidesWithItem(jugador1))
            {
                if(inmo==false)
                {
                    vidas-=1;
                    ui->lcdVidas->display(vidas);
                    jugador1->cambiar();
                    cambiazo=true;
                    if(vidas==0)
                    {
                        timer->stop();
                        timer_standard->stop();
                        QMessageBox::information(
                            this,
                            tr("GAME OVER"),
                            tr("Ultima vida perdida por una bala enemiga."));
                        volverMenu();
                    }
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

void Interfaz::volverMenu()//esconde los elementos graficos y vuelve al menu inicial
{
    ui->lcdEnemigos->hide();
    ui->lcdVidas->hide();
    ui->lcdTiempo->hide();
    ui->lcdPuntaje->hide();
    ui->labelEnemigos->hide();
    ui->labelVidas->hide();
    ui->labelPuntaje->hide();
    ui->labelTiempo->hide();
    ui->VidaBoss->hide();
    changeTeclas();
    puntaje=0;
    ui->lcdPuntaje->display(puntaje);
    vidas=3;
    if(multijugador==true)
    {
        ui->labelVidas_j1->hide();
        ui->labelVidas_j2->hide();
        ui->lcdVidas_J2->hide();
        multijugador=false;
        vidas2=5;
    }
    reiniciar_conta=true;
    clearLevelOne();
    clearLevelTwo();
    clearLevelThree();
    clearMulti();
    crearLevelOne();
    crearLevelTwo();
    crearLevelThree();
    crearMulti();
    listabase=0;
    clearMenu();
    crearMenu();
    timer_standard->stop();
}

void Interfaz::guardar()
{
    ofstream escritura;
    string name="jugador",contras="12345",niv=to_string(nivel_save),lif=to_string(vidas_save),sco=to_string(puntaje_save);
    string texto=name+","+contras+","+niv+","+lif+","+sco+",";
    escritura.open("../proyecto_final/guardado/partida_guardada.txt");// Crear o abrir un archivo para escritura
    escritura<<texto;
    escritura.close();
}

void Interfaz::validacion(string nombre, string contrasenha)//Valida que el usuario y contraseña sean correctos y llama al cargado de la partida
{
    ifstream archivo;
    string line,digi,texto,name,contras,nivel,lifes,score;
    int niv,lif,sco,len,conta;
    archivo.open(PATH_GUARDADO, ios::in);
    if(archivo.fail())
    {
        QMessageBox::information(
            this,
            tr("ERROR"),
            tr("No se encontro ningun archivo de guardado."));
    }
    getline(archivo,line);
    len=line.length();
    conta=0;
    for (int i=0; i<=len;i++)
    {
        digi=line[i];
        if(digi!=",")
            texto+=digi;
        else
        {
            conta++;
            switch (conta)
            {
                case 1:
                {
                    name=texto;
                }break;
                case 2:
                {
                    contras=texto;
                }break;
                case 3:
                {
                    nivel=texto;
                }break;
                case 4:
                {
                    lifes=texto;
                }break;
                case 5:
                {
                    score=texto;
                }break;
            }
            texto.erase();
        }
    }
    niv=atoi(nivel.c_str());
    lif=atoi(lifes.c_str());
    sco=atoi(score.c_str());
    archivo.close();
    if(nombre!=name)
    {
        QMessageBox::information(
            this,
            tr("ERROR"),
            tr("Nombre erroneo."));
    }
    else if(contrasenha!=contras)
    {
        QMessageBox::information(
            this,
            tr("ERROR"),
            tr("Contraseña erroneo."));
    }
    else
    {
        listabase=niv;
        vidas=lif;
        puntaje=sco;
        cargar();
        ui->textUsuario->hide();
        ui->textContra->hide();
        ui->labelUsuarios->hide();
        ui->labelContra->hide();
        menu_princi->removeItem(buttons.at(4));
    }
}

void Interfaz::cargar()
{
    switch (listabase)
    {
        case 1:
        {
            timer->stop();
            timer_standard->stop();
            QMessageBox::information(this,
                tr("El Comienzo..."),
                tr("La historia comienza con un programador común y corriente llamado Julian, trabaja como desarrollador independiente; Un día mientras intenta corregir algunos bugs en su programa se queda mirando a su ventana pensando como seria un mundo futurista, mientras tenia la mente en las nubes pensando en cosas extraordinarias, sin darse cuenta, derrama su bebida sobre su computadora, pero...."));
            jugador1 = new personaje(35,585,1);
            level_one->setSceneRect(0,0,1281,651);
            level_one->addItem(jugador1);
            ui->graphicsView->setScene(level_one);
            ui->labelEnemigos->show();
            ui->labelTiempo->show();
            ui->labelVidas->show();
            ui->labelPuntaje->show();
            ui->lcdEnemigos->show();
            ui->lcdPuntaje->show();
            ui->lcdPuntaje->display(puntaje);
            ui->lcdTiempo->show();
            ui->lcdVidas->show();
            ui->lcdTiempo->display(30);
            ui->lcdVidas->display(vidas);
            ui->lcdEnemigos->display(enemigos_lvl1.count());
            timer->stop();
            timer_standard->stop();
            QMessageBox::information(this,
                tr("Julian"),
                tr("-¡Que pasa! no, NOOOO..."));
            QMessageBox::information(this,
                tr("Narrador"),
                tr("Una fuerza extraña lo hace ingresar a su computadora y ahora tendrá que enfrentarse a los bugs y a su reina para poder regresar, lo se, una locura no?."));
            seguirmoviendo=true;
            tiempo_paso=false;
            jugador1->cambiar();
            cambiazo=true;
            changeTeclas();
            timer_standard->start(20);
        }break;
        case 2:
        {
            timer->stop();
            timer_standard->stop();
            QMessageBox::information(this,
                tr("La Travesia"),
                tr("Nuestro protagonista se encuentra cerca de hayar al bug y destruirlo. Sigue asi!!!"));
            jugador1 = new personaje(35,585,1);
            level_two->setSceneRect(0,0,1281,651);
            level_two->addItem(jugador1);
            ui->graphicsView->setScene(level_two);
            ui->labelEnemigos->show();
            ui->labelTiempo->show();
            ui->labelVidas->show();
            ui->labelPuntaje->show();
            ui->lcdEnemigos->show();
            ui->lcdPuntaje->show();
            ui->lcdPuntaje->display(puntaje);
            ui->lcdTiempo->show();
            ui->lcdVidas->show();
            ui->lcdTiempo->display(50);
            ui->lcdVidas->display(vidas);
            ui->lcdEnemigos->display(enemigos_lvl2.count());
            jugador1->cambiar();
            cambiazo=true;
            changeTeclas();
            timer_standard->start(20);
            tiempo_paso=false;
            listabase = 2;
        }break;
        case 3:
        {
            jugador1 = new personaje(35,585,1);
            level_three->setSceneRect(0,0,1281,651);
            level_three->addItem(jugador1);
            ui->graphicsView->setScene(level_three);
            ui->labelEnemigos->show();
            ui->labelTiempo->show();
            ui->labelVidas->show();
            ui->labelPuntaje->show();
            ui->lcdPuntaje->display(puntaje);
            ui->lcdEnemigos->show();
            ui->lcdPuntaje->show();
            ui->lcdTiempo->show();
            ui->lcdVidas->show();
            ui->lcdTiempo->display(60);
            ui->lcdVidas->display(vidas);
            ui->lcdEnemigos->display(1);
            ui->VidaBoss->show();
            timer->stop();
            timer_standard->stop();
            QMessageBox::information(this,
                tr("La Batalla Final"),
                tr("FINALEMENTE! ahi esta tu archienemigo, ve y derrotalo!"));
            jugador1->cambiar();
            cambiazo=true;
            changeTeclas();
            timer_standard->start(20);
            tiempo_paso=false;
            listabase = 3;
        }break;
    }
}

void Interfaz::nextMap()//cambia el mapa cada que se cumple la condicion para pasar de nivel
{
    listabase++;
    switch (listabase)
    {
        case 1:
        {
            nivel_save=listabase;
            vidas_save=vidas;
            puntaje_save=puntaje;
            guardar();
            timer->stop();
            timer_standard->stop();
            QMessageBox::information(this,
                tr("El Comienzo..."),
                tr("La historia comienza con un programador común y corriente llamado Julian, trabaja como desarrollador independiente; Un día mientras intenta corregir algunos bugs en su programa se queda mirando a su ventana pensando como seria un mundo futurista, mientras tenia la mente en las nubes pensando en cosas extraordinarias, sin darse cuenta, derrama su bebida sobre su computadora, pero...."));
            jugador1 = new personaje(35,585,1);
            level_one->setSceneRect(0,0,1281,651);
            level_one->addItem(jugador1);
            ui->graphicsView->setScene(level_one);
            ui->labelEnemigos->show();
            ui->labelTiempo->show();
            ui->labelVidas->show();
            ui->labelPuntaje->show();
            ui->lcdEnemigos->show();
            ui->lcdPuntaje->show();
            ui->lcdTiempo->show();
            ui->lcdVidas->show();
            ui->lcdTiempo->display(30);
            ui->lcdVidas->display(vidas);
            ui->lcdEnemigos->display(enemigos_lvl1.count());
            timer->stop();
            timer_standard->stop();
            QMessageBox::information(this,
                tr("Julian"),
                tr("-¡Que pasa! no, NOOOO..."));
            QMessageBox::information(this,
                tr("Narrador"),
                tr("Una fuerza extraña lo hace ingresar a su computadora y ahora tendrá que enfrentarse a los bugs y a su reina para poder regresar, lo se, una locura no?."));
            seguirmoviendo=true;
            tiempo_paso=false;
            jugador1->cambiar();
            cambiazo=true;
            timer_standard->start(20);
        }break;
        case 2:
        {
            nivel_save=listabase;
            timer->stop();
            timer_standard->stop();
            QMessageBox::information(this,
                tr("La Travesia"),
                tr("Nuestro protagonista se encuentra cerca de hayar al bug y destruirlo. Sigue asi!!!"));
            jugador1 = new personaje(35,585,1);
            level_two->setSceneRect(0,0,1281,651);
            level_two->addItem(jugador1);
            ui->graphicsView->setScene(level_two);
            ui->labelEnemigos->show();
            ui->labelTiempo->show();
            ui->labelVidas->show();
            ui->labelPuntaje->show();
            ui->lcdEnemigos->show();
            ui->lcdPuntaje->show();
            ui->lcdTiempo->show();
            ui->lcdVidas->show();
            ui->lcdTiempo->display(50);
            puntaje+=vidas*100+1000;
            ui->lcdPuntaje->display(puntaje);
            vidas+=1;
            //guardar
            vidas_save=vidas;
            puntaje_save=puntaje;
            guardar();
            //------
            ui->lcdVidas->display(vidas);
            ui->lcdEnemigos->display(enemigos_lvl2.count());
            jugador1->cambiar();
            cambiazo=true;
            timer_standard->start(20);
            tiempo_paso=false;
            listabase = 2;
        }break;
        case 3:
        {
            nivel_save=listabase;
            jugador1 = new personaje(35,585,1);
            level_three->setSceneRect(0,0,1281,651);
            level_three->addItem(jugador1);
            ui->graphicsView->setScene(level_three);
            ui->labelEnemigos->show();
            ui->labelTiempo->show();
            ui->labelVidas->show();
            ui->labelPuntaje->show();
            ui->lcdEnemigos->show();
            ui->lcdPuntaje->show();
            ui->lcdTiempo->show();
            ui->lcdVidas->show();
            ui->lcdTiempo->display(60);
            puntaje+=vidas*100+1000;
            ui->lcdPuntaje->display(puntaje);
            vidas+=1;
            //guardar
            vidas_save=vidas;
            puntaje_save=puntaje;
            guardar();
            //------
            ui->lcdVidas->display(vidas);
            ui->lcdEnemigos->display(1);
            ui->VidaBoss->show();
            timer->stop();
            timer_standard->stop();
            QMessageBox::information(this,
                tr("La Batalla Final"),
                tr("FINALEMENTE! ahi esta tu archienemigo, ve y derrotalo!"));
            jugador1->cambiar();
            cambiazo=true;
            timer_standard->start(20);
            tiempo_paso=false;
            listabase = 3;
        }break;
    }
}

void Interfaz::cargarMulti()
{
    listabase=4;
    multijugador=true;
    timer->stop();
    timer_standard->stop();
    QMessageBox::information(this,
        tr("Multiplayer"),
        tr("Que comience la matanza..."));
    jugador1 = new personaje(60,585,1);
    jugador2 = new personaje(1195,585,2);
    level_multi->setSceneRect(0,0,1281,651);
    level_multi->addItem(jugador1);
    level_multi->addItem(jugador2);
    ui->graphicsView->setScene(level_multi);
    ui->labelVidas_j1->show();
    ui->labelVidas_j2->show();
    ui->lcdVidas->show();
    ui->lcdVidas_J2->show();
    vidas=5;
    ui->lcdVidas->display(vidas);
    ui->lcdVidas_J2->display(vidas2);
    jugador1->cambiar();
    jugador2->cambiar();
    cambiazo2=true;
    cambiazo=true;
    timer_standard->start(20);
}

void Interfaz::mousePressEvent(QMouseEvent *event)//Evento de clic con mouse
{
    //---------------Menu Principal--------------
                    //Un jugador
    if(buttons.at(0)->get_Pressed())
    {
        menu_princi->removeItem(buttons.at(0));
        menu_princi->removeItem(buttons.at(1));

        menu_princi->addItem(buttons.at(2));
        menu_princi->addItem(buttons.at(3));
        buttons.at(0)->changePressed();
    }
                    //Multijugador
    else if(buttons.at(1)->get_Pressed())
    {
        cargarMulti();
        changeTeclas();
        buttons.at(1)->changePressed();
    }
    //-------------------------------------------

    //----------Partidas un jugador--------------
                //Cargar partida
    if(buttons.at(2)->get_Pressed())
    {
        //Revisar cargar partidas
        menu_princi->removeItem(buttons.at(2));
        menu_princi->removeItem(buttons.at(3));
        ui->textContra->show();
        ui->textUsuario->show();
        ui->labelUsuarios->show();
        ui->labelContra->show();
        menu_princi->addItem(buttons.at(4));
        buttons.at(2)->changePressed();
    }
                //Nueva partida
    if(buttons.at(3)->get_Pressed())
    {
        menu_princi->removeItem(buttons.at(2));
        menu_princi->removeItem(buttons.at(3));
        nextMap();
        changeTeclas();
        buttons.at(3)->changePressed();
    }
                //Cargar partida
    if(buttons.at(4)->get_Pressed())
    {
        nombre = ui->textUsuario->toPlainText();
        contra = ui->textContra->toPlainText();
        string nombrex=nombre.toStdString(),contrax=contra.toStdString();
        validacion(nombrex,contrax);
        buttons.at(4)->changePressed();
    }
    //-------------------------------------------
}

void Interfaz::keyPressEvent(QKeyEvent *i)//Evento de tecla presionada
{
    //----------------Movimiento--------------------------
    if(teclas==true)
    {
        if(multijugador==true)
        {
                    //jugador 1
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
                    level_multi->addItem(balas_jugador1.back());
                }
            }
                    //jugador 2
            if(i->key() == Qt::Key_L)
            {
                float poxixion=jugador2->getX();
                if(poxixion>=1260 and izquierda_map==true)
                    changeMapLocation();
                else if(poxixion<1260 and izquierda_map==false)
                    changeMapLocation();
                jugador2->setVX(7);
                timer->start(16);
                jugador2->moveRight();
                if(evaluarColisionJugador(jugador2, listabase))
                {
                    jugador2->setVX(-7);
                    jugador2->moveLeft();
                }
                else
                    jugador2->setside(true);
            }
            else if(i->key() == Qt::Key_J)
            {
                float poxixion=jugador2->getX();
                if(poxixion>=1260 and izquierda_map==true)
                    changeMapLocation();
                else if(poxixion<1260 and izquierda_map==false)
                    changeMapLocation();
                jugador2->setVX(-7);
                timer->start(16);
                jugador2->moveLeft();
                if(evaluarColisionJugador(jugador2, listabase))
                {
                    jugador2->setVX(7);
                    jugador2->moveRight();
                }
                else
                    jugador2->setside(false);
            }
            else if(i->key() == Qt::Key_I)
            {
                if(jugador2->getcaida())
                    jugador2->changedown();
                jugador2->resetVX();
                timer->start(16);
            }
            else if(i->key() == Qt::Key_K)
            {
                if(balas_jugador2.count()<5)
                {
                    float postionx=jugador2->getX(),postiony=jugador2->getY();
                    bool side=jugador2->getSide();
                    if(side==true)
                    {
                        balas_jugador2.append(new proyectil(postionx+5,postiony+18,5,0,15,15,4));
                    }
                    else
                    {
                        balas_jugador2.append(new proyectil(postionx+5,postiony+18,-5,0,15,15,4));
                    }
                    level_multi->addItem(balas_jugador2.back());
                }
            }
        }
        else
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
    }
    //----------------------------------------------------
}
