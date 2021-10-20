#include "personaje.h"

personaje::personaje(int x, int y, int _an, int _h)
{
    h=_h;
    an=_an;
    posx=x;
    posy=y;
    setPos(posx,posy);
}

personaje::~personaje()
{

}


QRectF personaje::boundingRect() const
{
    return QRectF(0, 0, an, h);
}

float personaje::getX()
{
    return posx;
}

float personaje::getY()
{
    return posy;
}

void personaje::moveUp()
{
    posy-=vy;
    setPos(posx, posy);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(PATH);
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void personaje::setVX(float velocidadx)
{
    vx=velocidadx;
}

void personaje::resetVX()
{
    vx=0;
}

void personaje::resetVY()
{
    vy=40;
}

void personaje::setposis(float x, float y)
{
    posx=x;
    posy=y;
}

void personaje::moveDown()
{
    posy+=vy;
    setPos(posx, posy);
}

void personaje::moveLeft()
{
    posx+=vx;
    setPos(posx, posy);
}

void personaje::moveRight()
{
    posx+=vx;
    setPos(posx, posy);
}

void personaje::jump(float dt)
{
    posx=posx+vx*dt;
    posy-=vy*dt+(g*dt*dt)/2.0f;
    vy=vy+g*dt;
}
