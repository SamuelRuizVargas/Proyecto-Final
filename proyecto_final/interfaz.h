#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <fstream>
#include <QMovie>//REVISAR (para poner videitos supongo)
#include <QList>

#include "imagenes.h"
#include "botones.h"
#include "plataforma.h"

using namespace std;

//-----------Rutas nivel 1--------------
#define PATH_BASE_LVL1 "../proyecto_final/posiciones/lvl1/posi_base_lvl1.txt"
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

private:
    Ui::Interfaz *ui;

    //---------Escenas----------
    QGraphicsScene *scene;
    QGraphicsScene *level_one;
    QGraphicsScene *level_two;
    QGraphicsScene *level_three;
    QGraphicsScene *bossfight;
    //--------------------------

    //-----------Listas---------
                //MENU
    QList<Imagenes*> menu;
    QList<botones*> buttons;
                //LVL 1
    QList<plataforma*> base_lvl1;
                //LVL 2
                //LVL 3
                //BOSSFIGHT
    //--------------------------

    //----------Metodos---------
                //MENU
    void crearMenu();
                //LVL 1
    void crearLevelOne();
                //LVL 2
                //LVL 3
                //BOSSFIGHT
    //--------------------------

protected:
    void mousePressEvent(QMouseEvent *event);
};
#endif // INTERFAZ_H
