#include "botones.h"

botones::botones(int x, int y, int _an, int _h, int tex)
{
    h=_h;
    an=_an;
    posx=x;
    posy=y;
    textura=tex;
    Pressed = false;
    setPos(posx,posy);
}

bool botones::get_Pressed()
{
    return Pressed;
}

QRectF botones::boundingRect() const
{
    return QRectF(0, 0, an, h);
}
void botones::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    switch(textura)
    {
        case 1://UN JUGADOR
        {
            pixmap.load(PATH_1P);
        }break;
        case 2://MULTIJUGADOR
        {
            pixmap.load(PATH_MULTI);
        }break;
        case 3://NUEVA PARTIDA
        {
            pixmap.load(PATH_NUEV);
        }break;
        case 4://CARGAR PARTIDA
        {
            pixmap.load(PATH_CARG);
        }break;
    }
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void botones::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     Pressed = true;
     update();
     QGraphicsItem::mousePressEvent(event);
}

void botones::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
