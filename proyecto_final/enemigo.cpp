#include "enemigo.h"

enemigo::enemigo(int x, int y, int _an, int _h, int _tipo)
{
    an=_an;
    h=_h;
    tipo=_tipo;
    posx=x;
    posy=y;
    switch(tipo)
    {
        case 1://Enemigos basicos
        {
            lives=1;
        }break;
        case 2://Enemigos a distancia
        {
            lives=3;
        }break;
        case 3://Enemigos voladores
        {
            lives=2;
        }break;
        case 4:
        {
            lives=160;
        }break;
    }
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
            if(movi_original==true)
                pixmap.load(PATH_BASE_ENE_IZQ);
            else
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
        case 4:
        {
            pixmap.load(PATH_BOSS_ENE);
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
    update();
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

int enemigo::getLives()
{
    return lives;
}

void enemigo::minusLives()
{
    lives-=1;
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
