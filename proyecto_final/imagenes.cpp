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
        case 1://el logo MENU
        {
            pixmap.load(PATH_LOGO);
        }break;
        case 2://el fondo MENU
        {
            pixmap.load(PATH_BACKGROUND);
        }break;
        case 3://el fondo LVL1
        {
            pixmap.load(PATH_BACK_1);
        }break;
        case 4://el fondo LVL2
        {
            pixmap.load(PATH_BACK_2);
        }break;
        case 5://el fondo LVL3
        {
            pixmap.load(PATH_BACK_3);
        }break;
        case 6:
        {
            pixmap.load(PATH_BACK_MULT);
        }break;
    }

    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

Imagenes::~Imagenes()
{

}
