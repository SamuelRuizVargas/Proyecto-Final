#include "proyectil.h"

proyectil::proyectil(float x, float y, float _vx, float _vy, int _an, int _h, int tip)
{
    h=_h;
    an=_an;
    posx=x;
    posy=y;
    vx=_vx;
    vy=_vy;
    tipo=tip;
    setPos(posx,posy);
}

QRectF proyectil::boundingRect() const
{
    return QRectF(0, 0, an, h);
}

void proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    switch(tipo)
    {
        case 1://Enemigos
        {
            pixmap.load(PATH_PROY2);
        }break;
        case 2://Jugador
        {
            pixmap.load(PATH_PROY);
        }break;
        case 3:
        {
            //
        }break;
    }
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void proyectil::disparo(float dt)
{
    switch(tipo)
    {
        case 1://parabola
        {
            posx=posx+vx*dt;
            posy-=vy*dt+(g*dt*dt)/2.0f;
            vy=vy+g*dt;
        }break;
        case 2://linea recta
        {
            posx+=vx;
        }break;
    }
    t1 = clock();
    tempo=(double(t1-t0)/CLOCKS_PER_SEC);
}

int proyectil::getTipo()
{
    return tipo;
}

float proyectil::getX()
{
    return posx;
}

float proyectil::getY()
{
    return posy;
}

double proyectil::getTempo()
{
    return tempo;
}

proyectil::~proyectil()
{

}
