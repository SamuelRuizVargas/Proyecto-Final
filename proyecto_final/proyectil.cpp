#include "proyectil.h"

proyectil::proyectil(int x, int y, int _an, int _h, int tip)
{
    h=_h;
    an=_an;
    posx=x;
    posy=y;
    tipo=tip;
    setPos(posx,posy);
}

QRectF proyectil::boundingRect() const
{
    return QRectF(0, 0, an, h);
}

void proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage bloq_esta(PATH_PROY);
    QBrush brush_im(bloq_esta);
    painter->setPen(Qt::NoPen);
    painter->setBrush(brush_im);
    painter->drawRect(boundingRect());
}

void proyectil::parabola(float dt)
{
    posx=posx+vx*dt;
    posy-=vy*dt+(g*dt*dt)/2.0f;
    vy=vy+g*dt;
}

proyectil::~proyectil()
{

}
