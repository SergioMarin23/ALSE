#include "db_local.h"
#include <sstream>
#include <vector>

DB_local::DB_local(string path){
    _URL = path;
}


bool DB_local::Abrir_BaseDato(){
    char* zErrMsg;

    int rc = sqlite3_open( _URL.c_str(), &_BD );

    if ( rc != 0 ){
        fprintf( stderr, "NO SE PUDO ABRIR LA BASE DE DATOS: %s\n", sqlite3_errmsg(_BD) );
        return (false);
    } else{
        fprintf( stderr, "BASE DE DATOS ABIERTA" );
    }

    string sqlstr = "CREATE TABLE IF NOT EXISTS PROM_MAX_MIN(id_medicion INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"\
                    "prom_temp REAL, max_temp REAL, min_temp REAL,"\
                    "prom_humed REAL, max_humed REAL, min_humed REAL,"\
                    "prom_veloc REAL, max_velo REAL, min_velo REAL,"\
                    "prom_direc REAL, max_direc REAL, min_direc REAL,"\
                    "prom_precip REAL, max_precipi REAL, min_precipi REAL,"\
                    "prom_intensi REAL, max_intensi REAL,min_intensi REAL);";

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


bool DB_local::Cerrar_BaseDato(){
    int rc = sqlite3_close( _BD );

    if( rc != SQLITE_OK )
        return (false);

    return true;
}

bool DB_local::GuardarDatos(float min_temp, float prom_temp, float max_temp, float min_hume, float prom_hume, float max_hume, float min_vel_vient, float prom_vel_vient, float max_vel_vient, int min_dir_vient, float prom_dir_vient, int max_dir_vient, float min_preci, float prom_preci, float max_preci, float min_inten, float prom_inten, float max_inten)
{
    char* zErrMsg = 0;
    int rc = 0;
    std::stringstream sqlsentence;

    sqlsentence << "INSERT INTO PROM_MAX_MIN ('prom_temp', 'max_temp', 'min_temp', 'prom_humed', "\
                   "'max_humed', 'min_humed', 'prom_veloc', 'max_velo', 'min_velo', 'prom_direc', "\
                   "'max_direc', 'min_direc', 'prom_precip', 'max_precipi', 'min_precipi', 'prom_intensi', "\
                   "'max_intensi', 'min_intensi' ) VALUES (";
    sqlsentence << prom_temp << ", " << max_temp << ", " << min_temp << ", " << prom_hume << ", " << max_hume << ", " << min_hume\
                << ", " << prom_vel_vient << ", " << max_vel_vient << ", " << min_vel_vient << ", " << prom_dir_vient << ", " \
                << max_dir_vient << ", " << min_dir_vient << ", " <<  prom_preci << ", " << max_preci << ", " << min_preci << ", " \
                << prom_inten << ", " << max_inten << ", " << min_inten << ");";

    rc = sqlite3_exec(_BD, sqlsentence.str().c_str(), 0, 0, &zErrMsg );

    if (rc != SQLITE_OK )
        return (false);

    return true;
}

float DB_local::RecuperarTemperatura(){
    char *mesg = 0;
    int rc = 0;

    float tmp;

    std::stringstream sql;
    sql << "SELECT prom_temp FROM PROM_MIN_MAX;";

    rc = sqlite3_exec( _BD, sql.str().c_str(), callback, (void*)&tmp, &mesg );

    if (rc != SQLITE_OK )
        return 0;

    return tmp;
}

int DB_local::callback(void *data, int argc, char *argv[], char *campos[]){
    float *ttemp = (float*)data;

    for(int i = 0; i < argc ; i++)
        ttemp[i] = atof(argv[i]);
    return 0;

}




