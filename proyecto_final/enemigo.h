#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsItem>
#include <QPainter>

#define PATH_BASE_ENE ":/imagenes/Enemigos/enemigo_base.png"
#define PATH_TIRA_ENE ":/imagenes/Enemigos/enemigo_distancia.png"
#define PATH_VOLA_ENE ":/imagenes/Enemigos/enemigo_volador.png"

class enemigo : public QGraphicsItem
{
    int h;
    int an;
    int posx;
    int posy;
    int velocidad=1;
    bool movi_original=true;
    int tipo;
public:
    enemigo(int x, int y, int an, int h, int tipo);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void movOriginal();
    bool getMov();
    void moveLeft();
    void moveRight();
    int getTipo();
    ~enemigo();
};

#endif // ENEMIGO_H
