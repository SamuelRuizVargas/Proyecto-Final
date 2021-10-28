#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QFontDatabase>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QKeyEvent>
#include <iostream>
#include <fstream>
#include <QList>
#include <QTimer>

#include "imagenes.h"
#include "botones.h"
#include "plataforma.h"
#include "personaje.h"
#include "enemigo.h"
#include "validacion.h"
#include "proyectil.h"

using namespace std;

//-----------Rutas nivel 1--------------
#define PATH_BASE_LVL1 "../proyecto_final/posiciones/lvl1/posi_base_lvl1.txt"
#define PATH_PARED_LVL1 "../proyecto_final/posiciones/lvl1/posi_pared_lvl1.txt"
#define PATH_ENE_LVL1 "../proyecto_final/posiciones/lvl1/posi_ene_lvl1.txt"
#define PATH_LIMITS_LVL1 "../proyecto_final/posiciones/lvl1/posi_limit_ene_lvl1.txt"
#define PATH_BAJOS_LVL1 "../proyecto_final/posiciones/lvl1/posi_bajos_lvl1.txt"
//--------------------------------------
//-----------Rutas nivel 2--------------
#define PATH_BASE_LVL2 "../proyecto_final/posiciones/lvl2/posi_base_lvl2.txt"
#define PATH_PARED_LVL2 "../proyecto_final/posiciones/lvl2/posi_pared_lvl2.txt"
#define PATH_ENE_LVL2 "../proyecto_final/posiciones/lvl2/posi_ene_lvl2.txt"
#define PATH_LIMITS_LVL2 "../proyecto_final/posiciones/lvl2/posi_limit_ene_lvl2.txt"
#define PATH_BAJOS_LVL2 "../proyecto_final/posiciones/lvl2/posi_bajos_lvl2.txt"
//--------------------------------------
//-----------Rutas nivel 3--------------
#define PATH_BASE_LVL3 "../proyecto_final/posiciones/lvl3/posi_base_lvl3.txt"
#define PATH_PARED_LVL3 "../proyecto_final/posiciones/lvl3/posi_pared_lvl3.txt"
#define PATH_ENE_LVL3 "../proyecto_final/posiciones/lvl3/posi_ene_lvl3.txt"
#define PATH_LIMITS_LVL3 "../proyecto_final/posiciones/lvl3/posi_limit_ene_lvl3.txt"
#define PATH_BAJOS_LVL3 "../proyecto_final/posiciones/lvl3/posi_bajos_lvl3.txt"
//--------------------------------------

QT_BEGIN_NAMESPACE
namespace Ui { class Interfaz; }
QT_END_NAMESPACE

class Interfaz : public QMainWindow
{
    Q_OBJECT

public:
    Interfaz(QWidget *parent = nullptr);
    ~Interfaz();

public slots:
    void actualizar();
    void standard();

private:
    Ui::Interfaz *ui;

    //---------Escenas----------
    QGraphicsScene *menu_princi;
    QGraphicsScene *level_one;
    QGraphicsScene *level_two;
    QGraphicsScene *level_three;
    QGraphicsScene *scene2;
    //---------------------------

    //--------TIMERS--------------
    QTimer *timer;
    QTimer *timer_standard;
    //---------------------------

    //--------OBJETOS------------
            //MENU
    validacion *pass;
            //LVL 1
            //LVL 2
            //LVL 3
            //OTROS
    personaje *jugador1;
    enemigo *enemigo_act;
    bool teclas=false;
    bool izquierda_map=true;
    //---------------------------

    //-----------Listas---------
                //MENU
    QList<Imagenes*> menu;
    QList<botones*> buttons;
                //LVL 1
    QList<plataforma*> base_lvl1;
    QList<plataforma*> pared_lvl1;
    QList<plataforma*> bajos_lvl1;
    QList<plataforma*> limites_lvl1;
    QList<Imagenes*> imagenes_lvl1;
    QList<enemigo*> enemigos_lvl1;
                //LVL 2
    QList<plataforma*> base_lvl2;
    QList<plataforma*> pared_lvl2;
    QList<plataforma*> bajos_lvl2;
    QList<plataforma*> limites_lvl2;
    QList<Imagenes*> imagenes_lvl2;
    QList<enemigo*> enemigos_lvl2;
                //LVL 3
    QList<plataforma*> base_lvl3;
    QList<plataforma*> pared_lvl3;
    QList<plataforma*> bajos_lvl3;
    QList<plataforma*> limites_lvl3;
    QList<Imagenes*> imagenes_lvl3;
    QList<enemigo*> enemigos_lvl3;
                //OTROS
    QList<proyectil*> balas_jugador1;
    QList<proyectil*> balas_enemigos;
    //--------------------------

    //----------Metodos---------
                //MENU
    void crearMenu();
                //LVL 1
    void crearLevelOne();
                //LVL 2
    void crearLevelTwo();
                //LVL 3
    void crearLevelThree();
                //OTROS
    QString letra(QString x);
    bool evaluarColisionJugador(personaje *personaje, int lista);
    bool evaluarColisionEnemies(int lista);
    int evaluarColisionSalto(personaje *personaje, int lista);
    bool evaluarColisionBullet(proyectil *bala, int lista);
    bool evaluarColisionBulletEne(proyectil *bala, int lista);
    void changeTeclas();
    void changeMapLocation();
    void validacion();
    void nextMap();
    //--------------------------

protected:
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *i);
};
#endif // INTERFAZ_H
