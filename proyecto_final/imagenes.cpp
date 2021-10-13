#include "imagenes.h"

Imagenes::Imagenes(int x, int y, int _an, int _h)
{
    h=_h;
    an=_an;
    posx=x;
    posy=y;
    setPos(posx,posy);
}

QRectF Imagenes::boundingRect() const
{
    return QRectF(0, 0, an, h);
}

void Imagenes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage imagen(":/imagenes/logo.png");
    QBrush brush_im(imagen);
    painter->setPen(Qt::NoPen);
    painter->setBrush(brush_im);
    painter->drawRect(boundingRect());
}

Imagenes::~Imagenes()
{

}
