#include "registrar.h"
#include "ui_registrar.h"
#include <string>
#include <iostream>
#include <sqlite3.h>
#include <sstream>


using namespace std;

Registrar::Registrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registrar)
{
    ui->setupUi(this);

}

Registrar::~Registrar()
{
    delete ui;
}

//void Registrar::GuardarDatos(){
//
//}


bool Registrar::Abrir_BaseDato(string path){
    _URL=path;
    char* zErrMsg;

    int rc = sqlite3_open( _URL.c_str(), &_BD );

    if ( rc != 0 ){
        fprintf( stderr, "NO SE PUDO ABRIR LA BASE DE DATOS: %s\n", sqlite3_errmsg(_BD) );
        return (false);
    } else{
        fprintf( stderr, "BASE DE DATOS ABIERTA" );
    }

    string sqlstr = "CREATE TABLE  IF NOT EXISTS DATOS_USUARIOS(id_usuario INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"\
             "nombre TEXT, apellido TEXT, documento INTEGER, fecha_nacimiento TEXT, usuario TEXT,"\
             "contraseña TEXT );";

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


bool Registrar::Cerrar_BaseDato(){
    int rc = sqlite3_close( _BD );

    if( rc != SQLITE_OK )
        return (false);

    return true;
}



void Registrar::on_buttonBox_accepted(){

    //GuardarDatos();

    //GUARDADO DE LOS DATOS PROPORCIONADOS EN LAS VARIBALES ESPECÍFICAS DE LA CLASE
        _nom = ui->lineEdit_NOMBRE->text();
        _apell = ui->lineEdit_APELLIDO->text();
        _docu = ui->lineEdit_DOCUMENT->text().toInt();
        _fech = ui->lineEdit_FECHA->text();
        _usu = ui->lineEdit_USUAR->text();
        _contra = ui->lineEdit_CONTRA->text();

     int rc;
     char* zErrMsg;


    Abrir_BaseDato("/home/maquinirris/Documents/ALSE_2120/PROYECTO_FINAL_ALSE-2021-2/SKYNET.db");

    //ENVÍO DE DATOS
    std::string sqlsentence;

    sqlsentence = "INSERT INTO DATOS_USUARIOS (nombre, apellido, documento, fecha_nacimiento, usuario, contraseña) "
                  "VALUES ('"+_nom.toStdString()+"', '"+_apell.toStdString()+"', "+std::to_string(_docu)+", '"+_fech.toStdString()+"', '"+_usu.toStdString()+"', '"+_contra.toStdString()+"' );";


    rc = sqlite3_exec( _BD, sqlsentence.c_str(), 0, 0, &zErrMsg );

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);

    } else {
        fprintf(stdout, "Records created successfully\n");
    }

     Cerrar_BaseDato();



}
