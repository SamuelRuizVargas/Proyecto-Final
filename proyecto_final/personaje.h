#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>

#define PATH ":/imagenes/icono.png"
#define g -9.8f
class personaje  : public QGraphicsItem
{
    int h;
    int an;
    float posx;
    float posy;
    float vx=0;
    float vy=40;

public:
    personaje(int,int,int,int);
    ~personaje();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void setVX(float velocidadx);
    void resetVX();
    void resetVY();
    void setposis(float x, float y);
    float getX();
    float getY();
    float getVY();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void jump(float dt);
};

#endif // PERSONAJE_H
