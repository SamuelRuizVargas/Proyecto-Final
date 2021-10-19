#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <QList>
#include <QMovie>

#include "imagenes.h"
#include "botones.h"
#include "niveluno.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Interfaz; }
QT_END_NAMESPACE

class Interfaz : public QMainWindow
{
    Q_OBJECT

public:
    Interfaz(QWidget *parent = nullptr);

    void Level_one();
    ~Interfaz();

private:
    Ui::Interfaz *ui;

    QGraphicsScene *scene;
    QGraphicsScene *level_one;

    QList<Imagenes*> menu;
    QList<botones*> buttons;

    void dibujarMenu();

protected:
    void mousePressEvent(QMouseEvent *event);
};
#endif // INTERFAZ_H
