#ifndef BOTONES_H
#define BOTONES_H
#include <QPainter>
#include <QGraphicsItem>

#define PATH_1P ":/imagenes/Botones/Boton_1p.png"
#define PATH_MULTI ":/imagenes/Botones/Boton_multi.png"
#define PATH_CARG ":/imagenes/Botones/Boton_cargar.png"
#define PATH_NUEV ":/imagenes/Botones/Boton_nueva.png"

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
    bool get_Pressed();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // BOTONES_H
