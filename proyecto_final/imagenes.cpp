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
    if(image==1){
        pixmap.load(":/imagenes/logo.png");
    }
    else if(image==2){
        pixmap.load(":/imagenes/menu_back.jpg");
    }

   painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

Imagenes::~Imagenes()
{

}
