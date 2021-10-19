#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <QGraphicsItem>
#include <QPainter>

#define PATH_TEXTURA_PRUEBA ":/imagenes/LVLS/lvl1/bloque.png"

class plataforma : public QGraphicsItem
{
    int h;
    int an;
    int posx;
    int posy;

public:
    plataforma();
    plataforma(int,int,int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    ~plataforma();
};

#endif // PLATAFORMA_H
