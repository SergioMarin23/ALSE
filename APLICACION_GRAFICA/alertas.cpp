#include "alertas.h"
#include "ui_alertas.h"

Alertas::Alertas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alertas)
{
    ui->setupUi(this);
}

Alertas::~Alertas()
{
    delete ui;
}
