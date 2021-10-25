#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsItem>
#include <QPainter>

#define PATH_PROY ":/imagenes/proyectil.png"
#define g -15.0f

class proyectil : public QGraphicsItem
{
    int h;
    int an;
    float posx;
    float posy;
    float vx;
    float vy;
    int tipo;
public:
    proyectil(int x, int y, int _an, int _h, int tip);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void parabola(float dt);
    ~proyectil();
};

#endif // PROYECTIL_H
