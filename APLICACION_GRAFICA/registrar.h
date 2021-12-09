#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <QDialog>

namespace Ui {
class Registrar;
}

class Registrar : public QDialog
{
    Q_OBJECT

public:
    explicit Registrar(QWidget *parent = nullptr);
    ~Registrar();

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
};

#endif // REGISTRAR_H
