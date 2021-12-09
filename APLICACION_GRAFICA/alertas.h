#ifndef ALERTAS_H
#define ALERTAS_H

#include <QDialog>

namespace Ui {
class Alertas;
}

class Alertas : public QDialog
{
    Q_OBJECT

public:
    explicit Alertas(QWidget *parent = nullptr);
    ~Alertas();

private:
    Ui::Alertas *ui;
};

#endif // ALERTAS_H
