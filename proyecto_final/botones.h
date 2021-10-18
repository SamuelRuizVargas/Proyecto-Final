#ifndef BOTONES_H
#define BOTONES_H
#include <QPainter>
#include <QGraphicsItem>

#define PATH_1P ":/imagenes/Botones/Boton_1p.png"
#define PATH_MULTI ":/imagenes/Botones/Boton_multi.png"

class botones: public QGraphicsItem
{
    int h;
    int an;
    int posx;
    int posy;
    int textura;

public:
    botones(int x,int y,int ancho,int alto, int textura);
    bool Pressed;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // BOTONES_H
