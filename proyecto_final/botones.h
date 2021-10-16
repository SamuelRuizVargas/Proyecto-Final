#ifndef BOTONES_H
#define BOTONES_H
#include <QPainter>
#include <QGraphicsItem>

class botones: public QGraphicsItem
{
public:
    botones();
    bool Pressed;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
protected:
void mousePressEvent(QGraphicsSceneMouseEvent *event);
void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // BOTONES_H
