#include "personaje.h"

personaje::personaje(int x, int y, int _tipo)
{
    posx=x;
    posy=y;
    tipo=_tipo;
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

float personaje::getVY()
{
    return vy;
}

void personaje::moveUp()
{
    posy-=vy;
    setPos(posx, posy);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    switch (tipo)
    {
    case 1:
    {
        pixmap.load(PATH_P1);
    }break;
    case 2:
    {
        pixmap.load(PATH_P2);
    }break;
    }
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void personaje::setVX(float velocidadx)
{
    vx=velocidadx;
}

void personaje::setVY(float velocidady)
{
    vy=velocidady;
}

void personaje::free(float dt)
{
    posx=posx+vx*dt;
    posy-=vy2*dt+(g*dt*dt)/2.0f;
    vy2=vy2+g*dt;
}

void personaje::resetVX()
{
    vx=0;
}

void personaje::resetVY()
{
    vy=60;
}

void personaje::zeroVY()
{
    vy=0;
}

void personaje::resetVY2()
{
    vy2=0;
}

void personaje::changedown()
{
    if(caida)caida = false;
    else caida = true;
}

void personaje::setside(bool lado)
{
    derecha=lado;
}

bool personaje::getSide()
{
    return derecha;
}

bool personaje::getcaida()
{
    return caida;
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

void personaje::cambiar()
{
    if(inmortal==false)
        inmortal=true;
    else
        inmortal=false;
}

bool personaje::getInmo()
{
    return inmortal;
}
