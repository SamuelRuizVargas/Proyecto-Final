#include "enemigo.h"

enemigo::enemigo(int x, int y, int _an, int _h, int _tipo)
{
    an=_an;
    h=_h;
    tipo=_tipo;
    posx=x;
    posy=y;
    setPos(posx,posy);
}

QRectF enemigo::boundingRect() const
{
    return QRectF(0,0,an,h);
}

void enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    switch(tipo)
    {
        case 1://Enemigos basicos
        {
            pixmap.load(PATH_BASE_ENE);
        }break;
        case 2://Enemigos a distancia
        {
            pixmap.load(PATH_TIRA_ENE);
        }break;
        case 3://Enemigos voladores
        {
            pixmap.load(PATH_VOLA_ENE);
        }break;
    }
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void enemigo::movOriginal()
{
    if(movi_original==true)
        movi_original=false;
    else if(movi_original==false)
        movi_original=true;
}

bool enemigo::getMov()
{
    return movi_original;
}

void enemigo::moveLeft()
{
    posx-=velocidad;
    setPos(posx, posy);
}

void enemigo::moveRight()
{
    posx+=velocidad;
    setPos(posx, posy);
}

int enemigo::getTipo()
{
    return tipo;
}

int enemigo::getX()
{
    return posx;
}

int enemigo::getY()
{
    return posy;
}

enemigo::~enemigo()
{

}
