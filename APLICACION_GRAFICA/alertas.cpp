#include "alertas.h"
#include "ui_alertas.h"
#include <string>
#include <sstream>
#include <vector>

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


bool Alertas::Abrir_BaseDato(std::string path){
    _URL=path;
    char* zErrMsg;

    int rc = sqlite3_open( _URL.c_str(), &_BD );

    if ( rc != 0 ){
        fprintf( stderr, "NO SE PUDO ABRIR LA BASE DE DATOS: %s\n", sqlite3_errmsg(_BD) );
        return (false);
    } else{
        fprintf( stderr, "BASE DE DATOS ABIERTA" );
    }

    std::string sqlstr = "CREATE TABLE IF NOT EXISTS USUARIOS_REGISTRADOS(id_usuario INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"\
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


bool Alertas::Cerrar_BaseDato(){
    int rc = sqlite3_close( _BD );

    if( rc != SQLITE_OK )
        return (false);

    return true;
}

void Alertas::AlertaHongo(){
    Abrir_BaseDato("/home/maquinirris/Documents/ALSE_2120/PROYECTO_FINAL_ALSE-2021-2/SKYNET.db");
    int rc;
    char* zErrMsg;
    std::vector<float> tmp;

    std::string sql;

    sql = "SELECT prom_temp FROM PROM_MAX_MIN;";

    rc = sqlite3_exec( _BD, sql.c_str(), callback, (void*)&tmp, &zErrMsg );

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);

    } else {
       fprintf(stdout, "Records created successfully\n");
    }

    for(int i = 0; i < tmp.size(); i++)
        if(tmp[i] == tmp[i+1])
            ui->radioButton_HAY_HONGO->setChecked(true);
        else
            ui->radioButton_NO_HONGO->setChecked(true);
}


void Alertas::on_line_TEMP_textEdited(const QString &arg1){
    Abrir_BaseDato("/home/maquinirris/Documents/ALSE_2120/PROYECTO_FINAL_ALSE-2021-2/SKYNET.db");
    int rc;
    char* zErrMsg;
    double tmp[1] = {0.};

    std::string sql;

    sql = "SELECT prom_temp FROM PROM_MAX_MIN;";

    rc = sqlite3_exec( _BD, sql.c_str(), callback, (void*)&tmp, &zErrMsg );

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);

    } else {
       fprintf(stdout, "Records created successfully\n");
    }

    Cerrar_BaseDato();

    ui->line_DIREC->setText( QString::number(tmp[0], 'f', 2) );

}


void Alertas::on_line_HUMED_textEdited(const QString &arg1){
    Abrir_BaseDato("/home/maquinirris/Documents/ALSE_2120/PROYECTO_FINAL_ALSE-2021-2/SKYNET.db");
    int rc;
    char* zErrMsg;
    double tmp[1] = {0.};

    std::string sql;

    sql = "SELECT prom_humed FROM PROM_MAX_MIN;";

    rc = sqlite3_exec( _BD, sql.c_str(), callback, (void*)&tmp, &zErrMsg );

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);

    } else {
       fprintf(stdout, "Records created successfully\n");
    }

    Cerrar_BaseDato();

    ui->line_DIREC->setText( QString::number(tmp[0], 'f', 2) );

}


void Alertas::on_line_VELO_textEdited(const QString &arg1){
    Abrir_BaseDato("/home/maquinirris/Documents/ALSE_2120/PROYECTO_FINAL_ALSE-2021-2/SKYNET.db");
    int rc;
    char* zErrMsg;
    double tmp[1] = {0.};

    std::string sql;

    sql = "SELECT prom_veloc FROM PROM_MAX_MIN;";

    rc = sqlite3_exec( _BD, sql.c_str(), callback, (void*)&tmp, &zErrMsg );

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);

    } else {
       fprintf(stdout, "Records created successfully\n");
    }

    Cerrar_BaseDato();

    ui->line_DIREC->setText( QString::number(tmp[0], 'f', 2) );

}


void Alertas::on_line_DIREC_textEdited(const QString &arg1){
    Abrir_BaseDato("/home/maquinirris/Documents/ALSE_2120/PROYECTO_FINAL_ALSE-2021-2/SKYNET.db");
    int rc;
    char* zErrMsg;
    double tmp[1] = {0.};

    std::string sql;

    sql = "SELECT prom_direc FROM PROM_MAX_MIN;";

    rc = sqlite3_exec( _BD, sql.c_str(), callback, (void*)&tmp, &zErrMsg );

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);

    } else {
       fprintf(stdout, "Records created successfully\n");
    }

    Cerrar_BaseDato();

    ui->line_DIREC->setText( QString::number(tmp[0], 'f', 2) );
}


void Alertas::on_line_PRECI_textEdited(const QString &arg1){
    Abrir_BaseDato("/home/maquinirris/Documents/ALSE_2120/PROYECTO_FINAL_ALSE-2021-2/SKYNET.db");
    int rc;
    char* zErrMsg;
    double tmp[1] = {0.};

    std::string sql;

    sql = "SELECT prom_precip FROM PROM_MAX_MIN;";

    rc = sqlite3_exec( _BD, sql.c_str(), callback, (void*)&tmp, &zErrMsg );

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);

    } else {
       fprintf(stdout, "Records created successfully\n");
    }

    Cerrar_BaseDato();

    ui->line_DIREC->setText( QString::number(tmp[0], 'f', 2) );
}


void Alertas::on_line_INTENSI_textEdited(const QString &arg1){
    Abrir_BaseDato("/home/maquinirris/Documents/ALSE_2120/PROYECTO_FINAL_ALSE-2021-2/SKYNET.db");
    int rc;
    char* zErrMsg;
    double tmp[1] = {0.};

    std::string sql;

    sql = "SELECT prom_intensi FROM PROM_MAX_MIN;";

    rc = sqlite3_exec( _BD, sql.c_str(), callback, (void*)&tmp, &zErrMsg );

    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);

    } else {
       fprintf(stdout, "Records created successfully\n");
    }

    Cerrar_BaseDato();

    ui->line_DIREC->setText( QString::number(tmp[0], 'f', 2) );
}


int Alertas::callback(void *data, int argc, char **argv, char **campos){
    double *ttemp = (double *)data;

    for(int i = 0; i < argc; i++)
        ttemp[0] = atof(argv[i]);
    return 0;

}

void Alertas::on_line_DIAS_CALOR_textEdited(const QString &arg1){
    char *mesg = 0;
    int rc = 0;
    int dia_calor = 0;

    float tmp;

    Abrir_BaseDato("/home/maquinirris/Documents/ALSE_2120/PROYECTO_FINAL_ALSE-2021-2/SKYNET.db");

    std::stringstream sql;
    sql << "SELECT prom_temp FROM PROM_MIN_MAX;";

    rc = sqlite3_exec( _BD, sql.str().c_str(), callback, (void*)&tmp, &mesg );
    if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", mesg);

    } else {
       fprintf(stdout, "Records created successfully\n");
    }

    if(tmp > 10)
        dia_calor = dia_calor + 1;
        ui->line_DIAS_CALOR->setText(QString::number(dia_calor));
}














