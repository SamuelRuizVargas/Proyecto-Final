#ifndef IMAGENES_H
#define IMAGENES_H

#include <QGraphicsItem>
#include <QPainter>
//------------------Rutas----------------------------------
                    //menu
#define PATH_LOGO ":/imagenes/Menu/logo.png"
#define PATH_BACKGROUND ":/imagenes/Menu/menu_back.jpg"
                    //level 1
#define PATH_BACK_1 ":/imagenes/LVLS/lvl1/background.jpg"
                    //level 2
#define PATH_BACK_2 ":/imagenes/LVLS/lvl2/background.jpg"
                    //level 3
#define PATH_BACK_3 ":/imagenes/LVLS/lvl3/background.jpg"
                //Multijugador
#define PATH_BACK_MULT ":/imagenes/LVLS/multijugador/background.jpg"
//---------------------------------------------------------

class Imagenes : public QGraphicsItem
{
    int h;
    int an;
    int posx;
    int posy;
    int image;
public:
    Imagenes(int,int,int,int,int);
    int get_image();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    ~Imagenes();
};

#endif // IMAGENES_H
