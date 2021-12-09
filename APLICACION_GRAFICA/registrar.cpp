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


void Registrar::on_buttonBox_accepted(){

//GUARDADO DE LOS DATOS PROPORCIONADOS EN LAS VARIBALES ESPECÍFICAS DE LA CLASE
    _nom = ui->lineEdit_NOMBRE->text();
    _apell = ui->lineEdit_APELLIDO->text();
    _docu = ui->lineEdit_DOCUMENT->text().toInt();
    _fech = ui->lineEdit_FECHA->text();
    _usu = ui->lineEdit_USUAR->text();
    _contra = ui->lineEdit_CONTRA->text();


//CONVERSION DE LOS DATOS A STRING PARA PROCESARLOS CORRECTAMENTE
    string nom_str = _nom.toStdString();
    string apell_str = _apell.toStdString();
    string fech_str = _fech.toStdString();
    string usu_str = _usu.toStdString();
    string contra_str = _contra.toStdString();

    int docu = _docu;


//ABRIENDO BASE DE DATOS PARA HACER EL ENVÍO
    sqlite3 *db;
    int rc;
    char* zErrMsg = 0;
    string sqlstr;

    rc = sqlite3_open( "SKYNET.db", &db );

    if( rc ){
        fprintf( stderr, "NO SE PUDO ABRIR LA BASE DE DATOS : %s\n", sqlite3_errmsg( db ) );

    }else{
        fprintf( stderr, "BASE DE DATOS ABIERTA" );
    }


//CREANDO TABLA
    sqlstr = "CREATE TABLE  IF NOT EXISTS DATOS_USUARIOS(id_usuario INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"\
             "nombre TEXT NOT NULL,"\
             "apellido TEXT NOT NULL, documento INTEGER NOT NULL,"\
             "fecha_nacimiento TEXT NOT NULL, usuario TEXT NOT NULL,"\
             "contraseña TEXT NOT NULL);";

    rc = sqlite3_exec( db, sqlstr.c_str(), 0, 0, &zErrMsg );

    if ( rc != SQLITE_OK ){
        fprintf( stderr, "SQL ERROR: %s\n", zErrMsg );
    } else {
        fprintf( stdout, "TABLA CREADA\n");
    }

//ENVÍO DE DATOS
    std::stringstream sqlsentence;

    sqlsentence << "INSERT INTO DATOS_USUARIOS (nombre, apellido, documento, fecha_nacimiento, usuario, contraseña) VALUES (";
    sqlsentence << nom_str << ", " << apell_str << ", " << docu << ", " << fech_str << ", " << usu_str << ", " << contra_str << ");" ;

    rc = sqlite3_exec( db, sqlsentence.str().c_str(), 0, 0, &zErrMsg );

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);

    } else {
       fprintf(stdout, "Records created successfully\n");
    }

sqlite3_close(db);

}
