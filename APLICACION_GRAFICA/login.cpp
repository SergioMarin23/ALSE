#include "login.h"
#include "ui_login.h"
#include <iostream>
#include <sstream>
#include <QTime>
#include <QDate>
#include "alertas.h"


using namespace std;

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


bool Login::Abrir_BaseDato(string path){
    _URL=path;
    char* zErrMsg;

    int rc = sqlite3_open( _URL.c_str(), &_BD );

    if ( rc != 0 ){
        fprintf( stderr, "NO SE PUDO ABRIR LA BASE DE DATOS: %s\n", sqlite3_errmsg(_BD) );
        return (false);
    } else{
        fprintf( stderr, "BASE DE DATOS ABIERTA" );
    }

    string sqlstr = "CREATE TABLE IF NOT EXISTS USUARIOS_REGISTRADOS(id_usuario INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"\
                    "usuario TEXT, fecha_ejecución TEXT, hora_ejecución TEXT);";

    rc = sqlite3_exec( _BD, sqlstr.c_str(), 0, 0, &zErrMsg );

    if ( rc != SQLITE_OK ){
        fprintf( stderr, "SQL ERROR: %s\n", zErrMsg );
        sqlite3_free( zErrMsg );
        return (false);
    } else {
        fprintf( stdout, "TABLA CREADA\n");
    }
    return true;
}


bool Login::Cerrar_BaseDato(){
    int rc = sqlite3_close( _BD );

    if( rc != SQLITE_OK )
        return (false);

    return true;

}

void Login::on_buttonBox_accepted(){
//SE GUARDAN LOS DATOS EN LAS VARIABLES ESPECÍFICA DE LA CLASE         //EN ESTA PARTE DEL BUTTONBOX_ACCEPTED SE ENVÍAN A LA BASE DE DATOS
    _usu_log = ui->line_USU_LOG->text();                               //LA INFORMACIÓN INGRESADA POR EL USUARIO.
    _contra_log = ui->line_CONTRA_LOG->text();

    int rc;
    char* zErrMsg;
//ENVÍO DE DATOS

    Abrir_BaseDato("/home/maquinirris/Documents/ALSE_2120/PROYECTO_FINAL_ALSE-2021-2/SKYNET.db");

    std::string sqlsentence;

    //QDate cd = QDate::currentDate();
    //QTime ct = QTime::currentTime();

    sqlsentence = "INSERT INTO USUARIOS_REGISTRADOS (usuario, fecha_ejecución, hora_ejecución) "
                  "VALUES ('"+_usu_log.toStdString()+"', date('now','localtime'), time('now','localtime'));";


    rc = sqlite3_exec( _BD, sqlsentence.c_str(), 0, 0, &zErrMsg );

    if( rc != SQLITE_OK )
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
    else
       fprintf(stdout, "Records created successfully\n");
    Alertas alert;
    alert.setModal( true );
    alert.show();
    alert.exec();

    Cerrar_BaseDato();


}
