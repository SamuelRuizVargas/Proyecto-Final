#ifndef VALIDACION_H
#define VALIDACION_H

#include <QMainWindow>
#include <QFontDatabase>
#include <string>
#include <fstream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class validacion; }
QT_END_NAMESPACE


namespace Ui {
class validacion;
}

class validacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit validacion(QWidget *parent = nullptr);
    ~validacion();

private slots:
    void on_ingreso_clicked();

private:
    Ui::validacion *ui;
    string usuario,contra;


};

#endif // VALIDACION_H
