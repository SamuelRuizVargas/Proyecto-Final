#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>

#define PATH ":/imagenes/icono.png"

class personaje  : public QGraphicsItem
{
public:

    personaje(int,int,int,int);
    ~personaje();
    int h;
    int an;
    int posx;
    int posy;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // PERSONAJE_H
