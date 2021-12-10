#include "inicio.h"
#include "./ui_inicio.h"
#include "registrar.h"
#include "login.h"
#include <string>
#include <sqlite3.h>

Inicio::Inicio(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inicio)
{
    ui->setupUi(this);

}

Inicio::~Inicio()
{
    delete ui;
}


void Inicio::on_LOGIN_BUTTON_clicked(){
    Login log;
    log.setModal( true );
    log.show();
    log.exec();
}

void Inicio::on_REGIS_BUTTON_clicked(){
    Registrar reg;
    reg.setModal( true );
    reg.show();
    reg.exec();
}
