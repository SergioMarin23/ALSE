#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <QDialog>
#include "string"
#include <sqlite3.h>

namespace Ui {
class Registrar;
}

class Registrar : public QDialog
{
    Q_OBJECT

public:
    explicit Registrar(QWidget *parent = nullptr);
    ~Registrar();
    bool Abrir_BaseDato(std::string path);               //FUNCIÓN PARA ABRIR LA BASE DE DATOS LOCAL.
    bool Cerrar_BaseDato();                              //FUNCIÓN PARA CERRAR LA BASE DE DATOS.

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Registrar *ui;
    QString _nom;
    QString _apell;
    int _docu;
    QString _fech;
    QString _usu;
    QString _contra;
    sqlite3 *_BD;
    std::string _URL;
};

#endif // REGISTRAR_H
