#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>

#define PATH_P1 ":/imagenes/player1.png"
#define PATH_P1_IZQ ":/imagenes/player1_izq.png"
#define PATH_P2 ":/imagenes/player2.png"
#define PATH_P2_IZQ ":/imagenes/player2_izq.png"

#define g -15.0f

class personaje  : public QGraphicsItem
{
    int h=40;
    int an=28;
    float posx;
    float posy;
    float vx=0;
    float vy=60;
    float vy2=0;
    bool caida=true;
    bool derecha=true;
    bool inmortal=false;
    int tipo;

public:
    personaje(int, int, int _tipo);
    ~personaje();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void setVX(float velocidadx);
    void setVY(float velocidady);
    void free(float dt);
    void resetVX();
    void resetVY();
    void zeroVY();
    void resetVY2();
    void changedown();
    void setside(bool lado);
    bool getSide();
    bool getcaida();
    void setposis(float x, float y);
    float getX();
    float getY();
    float getVY();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void jump(float dt);
    void cambiar();
    bool getInmo();
};


#endif // PERSONAJE_H
