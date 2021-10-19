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

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPixmap pixmap;
    pixmap.load(PATH);

    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());


}
