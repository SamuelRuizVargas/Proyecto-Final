#ifndef IMAGENES_H
#define IMAGENES_H

#include <QGraphicsItem>
#include <QPainter>

class Imagenes : public QGraphicsItem
{
    int h;
    int an;
    int posx;
    int posy;
public:
    Imagenes(int,int,int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    ~Imagenes();
};

#endif // IMAGENES_H
