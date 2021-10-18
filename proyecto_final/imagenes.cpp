#include "imagenes.h"

Imagenes::Imagenes(int x, int y, int _an, int _h, int name_img)
{
    h=_h;
    an=_an;
    posx=x;
    posy=y;
    image = name_img;
    setPos(posx,posy);
}

int Imagenes::get_image()
{
    return image;
}

QRectF Imagenes::boundingRect() const
{
    return QRectF(0, 0, an, h);
}

void Imagenes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    switch(image)
    {
    case 1://el logo
    {
        pixmap.load(PATH_LOGO);
    }break;
    case 2://el fondo
    {
        pixmap.load(PATH_BACKGROUND);
    }break;
    }

    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

Imagenes::~Imagenes()
{

}
