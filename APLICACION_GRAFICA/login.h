#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <sqlite3.h>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool Abrir_BaseDato(std::string path);               //FUNCIÓN PARA ABRIR LA BASE DE DATOS LOCAL.
    bool Cerrar_BaseDato();                              //FUNCIÓN PARA CERRAR LA BASE DE DATOS.

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Login *ui;
    QString _usu_log;
    QString _contra_log;
    sqlite3 *_BD;
    std::string _URL;
};

#endif // LOGIN_H
