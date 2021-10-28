#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsItem>
#include <QPainter>
#include <ctime>
#include <math.h>

#define PATH_PROY ":/imagenes/proyectil.png"
#define PATH_PROY2 ":/imagenes/proyectil2.png"
#define g -15.0f

using namespace std;

class proyectil : public QGraphicsItem
{
    int h;
    int an;
    float posx;
    float posy;
    float vx;
    float vy;
    float radio=1;
    float desplazamiento=0;
    int tipo;
    double tempo;
    unsigned t0=clock(), t1;

public:
    proyectil(float x, float y, float _vx, float _vy, int _an, int _h, int tip);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void disparo(float dt=0.1f);
    int getTipo();
    float getX();
    float getY();
    double getTempo();
    ~proyectil();
};

#endif // PROYECTIL_H
