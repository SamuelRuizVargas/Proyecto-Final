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
    int image;
public:
    Imagenes(int,int,int,int,int);
    int get_image();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    ~Imagenes();
};

#endif // IMAGENES_H
