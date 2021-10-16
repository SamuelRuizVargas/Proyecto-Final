#include "botones.h"

botones::botones()
{
    Pressed = false;

}

QRectF botones::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}
void botones::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    if(Pressed){
        pixmap.load(":/imagenes/logo.png");
    }
    else{
        pixmap.load(":/imagenes/logo.jpg");
    }
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void botones::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     Pressed = true;
     update();
     QGraphicsItem::mousePressEvent(event);
}

void botones::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
