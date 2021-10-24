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

using namespace std;

//-----------Rutas nivel 1--------------
#define PATH_BASE_LVL1 "../proyecto_final/posiciones/lvl1/posi_base_lvl1.txt"
//--------------------------------------
//-----------Rutas nivel 2--------------
#define PATH_BASE_LVL2 "../proyecto_final/posiciones/lvl2/posi_base_lvl2.txt"
//--------------------------------------
//-----------Rutas nivel 3--------------
#define PATH_BASE_LVL3 "../proyecto_final/posiciones/lvl3/posi_base_lvl3.txt"
#define PATH_PARED_LVL3 "../proyecto_final/posiciones/lvl3/posi_pared_lvl3.txt"
#define PATH_ENE_LVL3 "../proyecto_final/posiciones/lvl3/posi_ene_lvl3.txt"
#define PATH_LIMITS_LVL3 "../proyecto_final/posiciones/lvl3/posi_limit_ene_lvl3.txt"
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
    QGraphicsScene *bossfight;
    QGraphicsScene *scene2;
    //---------------------------

    //--------TIMERS--------------
    QTimer *timer;
    QTimer *timer_standard;
    //---------------------------

    //--------OBJETOS------------
            //MENU
    QMainWindow *ven2;

    QMediaPlayer *fondo;
    QVideoWidget *vw;
            //LVL 1
            //LVL 2
            //LVL 3
            //BOSSFIGHT
            //OTROS
    personaje *jugador1;
    enemigo *enemigo_act;
    //---------------------------

    //-----------Listas---------
                //MENU
    QList<Imagenes*> menu;
    QList<botones*> buttons;
                //LVL 1
    QList<plataforma*> base_lvl1;
    QList<Imagenes*> imagenes_lvl1;
                //LVL 2
    QList<plataforma*> base_lvl2;
    QList<Imagenes*> imagenes_lvl2;
                //LVL 3
    QList<plataforma*> base_lvl3;
    QList<plataforma*> pared_lvl3;
    QList<plataforma*> limites_lvl3;
    QList<Imagenes*> imagenes_lvl3;
    QList<enemigo*> enemigos_lvl3;
                //BOSSFIGHT
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
                //BOSSFIGHT
                //OTROS
    QString letra(QString x);
    bool evaluarColisionJugador(personaje *personaje, int lista);
    bool evaluarColisionEnemies(int lista);
    int evaluarColisionSalto(personaje *personaje, int lista);
    void validacion();
    int cont=0; // borrar
    //--------------------------

protected:
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *i);
};
#endif // INTERFAZ_H
