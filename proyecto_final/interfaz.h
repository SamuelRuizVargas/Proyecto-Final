#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <QList>

#include "imagenes.h"
#include "botones.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Interfaz; }
QT_END_NAMESPACE

class Interfaz : public QMainWindow
{
    Q_OBJECT

public:
    Interfaz(QWidget *parent = nullptr);
    ~Interfaz();

private:
    Ui::Interfaz *ui;
    QGraphicsScene *scene;
    botones *boton_p;
    QList<Imagenes*> menu;


    void dibujarMenu();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};
#endif // INTERFAZ_H
