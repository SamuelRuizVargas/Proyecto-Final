#include "plataforma.h"

plataforma::plataforma()
{
    h=0;
    an=0;
    posx=0;
    posy=0;
    setPos(posx,posy);
}

plataforma::plataforma(int x, int y, int _an, int _h, int _tipo)
{
    h=_h;
    an=_an;
    posx=x;
    posy=y;
    tipo=_tipo;
    setPos(posx,posy);
}

QRectF plataforma::boundingRect() const
{
    return QRectF(0, 0, an, h);
}

void plataforma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch (tipo)
    {
    case 1:
    {
        QImage bloq_esta(PATH_TEXTURA);
        QBrush brush_im(bloq_esta);
        painter->setPen(Qt::NoPen);
        painter->setBrush(brush_im);
        painter->drawRect(boundingRect());
    }break;
    case 2:
    {
        QImage bloq_esta(PATH_HITBOX);
        QBrush brush_im(bloq_esta);
        painter->setPen(Qt::NoPen);
        painter->setBrush(brush_im);
        painter->drawRect(boundingRect());
    }break;
    }
}

plataforma::~plataforma()
{

}
