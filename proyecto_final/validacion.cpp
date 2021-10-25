#include "validacion.h"
#include "ui_validacion.h"

validacion::validacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::validacion)
{
    ui->setupUi(this);

}

validacion::~validacion()
{
    delete ui;
}



void validacion::on_ingreso_clicked()
{
    QString usuario = ui->user->text();
    ui->label->setText(usuario);

}
