#ifndef ALERTAS_H
#define ALERTAS_H

#include <QDialog>
#include <sqlite3.h>
#include <string>

namespace Ui {
class Alertas;
}

class Alertas : public QDialog
{
    Q_OBJECT

public:
    explicit Alertas(QWidget *parent = nullptr);
    ~Alertas();
    bool Abrir_BaseDato(std::string path);               //FUNCIÓN PARA ABRIR LA BASE DE DATOS LOCAL.
    bool Cerrar_BaseDato();                              //FUNCIÓN PARA CERRAR LA BASE DE DATOS LOCAL.
    void AlertaHongo();

private slots:
    void on_line_TEMP_textEdited(const QString &arg1);
    void on_line_HUMED_textEdited(const QString &arg1);
    void on_line_VELO_textEdited(const QString &arg1);
    void on_line_DIREC_textEdited(const QString &arg1);
    void on_line_PRECI_textEdited(const QString &arg1);
    void on_line_INTENSI_textEdited(const QString &arg1);

    void on_line_DIAS_CALOR_textEdited(const QString &arg1);



private:
    Ui::Alertas *ui;
    static int callback(void* data, int argc, char** argv, char** campos );
    sqlite3 *_BD;
    std::string _URL;


};

#endif // ALERTAS_H
