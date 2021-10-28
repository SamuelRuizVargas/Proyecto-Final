#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <QGraphicsItem>
#include <QPainter>

#define PATH_TEXTURA ":/imagenes/bloque.png"
#define PATH_HITBOX ":/imagenes/bloque_hitbox.png"

class plataforma : public QGraphicsItem
{
    int h;
    int an;
    int posx;
    int posy;
    int tipo;

public:
    plataforma();
    plataforma(int, int, int, int, int _tipo);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    ~plataforma();
};

#endif // PLATAFORMA_H
