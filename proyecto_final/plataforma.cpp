#include "plataforma.h"

plataforma::plataforma()
{
    h=0;
    an=0;
    posx=0;
    posy=0;
    setPos(posx,posy);
}

plataforma::plataforma(int x, int y, int _an, int _h)
{
    h=_h;
    an=_an;
    posx=x;
    posy=y;
    setPos(posx,posy);
}

QRectF plataforma::boundingRect() const
{
    return QRectF(0, 0, an, h);
}

void plataforma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(PATH_TEXTURA_PRUEBA);
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

plataforma::~plataforma()
{

}
