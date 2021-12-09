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

void Login::on_buttonBox_accepted(){
//SE GUARDAN LOS DATOS EN LAS VARIABLES ESPECÍFICA DE LA CLASE
    _usu_log = ui->line_USU_LOG->text();
    _contra_log = ui->line_CONTRA_LOG->text();


//LOS DATOS SE CONVIERTEN A STRING PARA PROCESARLOS MEJOR
    string usu_log_str = _usu_log.toStdString();
    string contra_log_str = _contra_log.toStdString();


//ABRIENDO BASE DE DATOS PARA HACER EL ENVÍO
    sqlite3 *db;
    int rc;
    char* zErrMsg = 0;
    string sqlstr;

    rc = sqlite3_open( "SKYNET.db", &db );

    if( rc != SQLITE_OK ){
        fprintf( stderr, "NO SE PUDO ABRIR LA BASE DE DATOS : %s\n", sqlite3_errmsg( db ) );

     }else{
        fprintf( stderr, "BASE DE DATOS ABIERTA" );
     }


//CREANDO TABLA DE USUARIOS REGISTRADOS
    sqlstr = "CREATE TABLE IF NOT EXISTS USUARIOS_REGISTRADOS (id_usuario INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"\
             "usuario TEXT NOT NULL, contraseña TEXT NOT NULL, fecha_ejecución TEXT NOT NULL, hora_ejecución TEXT NOT NULL);";

    rc = sqlite3_exec( db, sqlstr.c_str(), 0, 0, &zErrMsg );

    if ( rc != SQLITE_OK ){
        fprintf( stderr, "SQL ERROR: %s\n", zErrMsg );
        sqlite3_free( zErrMsg );
    } else {
        fprintf( stdout, "TABLA CREADA\n");
    }


//ENVÍO DE DATOS
    std::stringstream sqlsentence;

    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    sqlsentence << "INSERT INTO USUARIOS_REGISTRADOS (usuario, contraseña, fecha_ejecucion, hora_ejecucion) VALUES (";
    sqlsentence << usu_log_str << ", " << contra_log_str << ", " << &cd << ", " << &ct << ");" ;

    rc = sqlite3_exec( db, sqlsentence.str().c_str(), 0, 0, &zErrMsg );

    if( rc != SQLITE_OK )
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
    else
       fprintf(stdout, "Records created successfully\n");



//VALIDACIÓN DE DATOS

    string tmp[2] = {0, 0};

    std::stringstream sql;
    sql << "SELECT usuario,contraseña FROM USUARIOS_REGISTRADOS;";

    rc = sqlite3_exec( db, sql.str().c_str(), callback, (void*)&tmp, &zErrMsg );

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);

    } else {
       fprintf(stdout, "Records created successfully\n");
    }

    if( usu_log_str == tmp[0] ){
        Alertas alert;
        alert.setModal( true );
        alert.show();
        alert.exec();
    }

sqlite3_close(db);

    //cout << "Bienvenido, usuario: " << usu_log_str << endl;

}

int Login::callback(void *data, int argc, char *argv[], char *campos[]){
    string *ttemp = (string*)data;

    for(int i = 0; i < 2; i++)
        ttemp[i] = argv[i];

    return 0;
}
