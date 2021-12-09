#include "db_local.h"
#include <sstream>

DB_local::DB_local(string path){
    _URL = path;
}


bool DB_local::Abrir_BaseDato(){
    int rc = sqlite3_open( _URL.c_str(), &_BD );

    if(rc != SQLITE_OK)
        return (false);

    return true;
}


bool DB_local::Cerrar_BaseDato(){
    int rc = sqlite3_close( _BD );

    if( rc != SQLITE_OK )
        return (false);

    return true;
}


bool DB_local::Guarda_Tempe(float min_temp, float prom_temp, float max_temp){
    char* zErrMsg = 0;
    int rc = 0;
    std::stringstream sqlsentence;

    sqlsentence << "INSERT INTO PROM_MAX_MIN ('prom_temp', 'max_temp', 'min_temp') VALUES (";
    sqlsentence << prom_temp << ", " << max_temp << ", " << min_temp << ");" ;

    rc = sqlite3_exec(_BD, sqlsentence.str().c_str(), 0, 0, &zErrMsg );

    if (rc != SQLITE_OK )
        return (false);

    return true;
}


bool DB_local::Guarda_Hume(float min_hume, float prom_hume, float max_hume){
    char* zErrMsg = 0;
    int rc = 0;
    std::stringstream sqlsentence;

    sqlsentence << "INSERT INTO PROM_MAX_MIN ('prom_humed', 'max_humed', 'min_humed') VALUES (";
    sqlsentence << prom_hume << ", " << max_hume << ", " << min_hume << ");" ;

rc = sqlite3_exec(_BD, sqlsentence.str().c_str(), 0, 0, &zErrMsg );

if (rc != SQLITE_OK )
    return (false);

return true;
}


bool DB_local::Guarda_Vel_vient(float min_vel_vient, float prom_vel_vient, float max_vel_vient){
    char* zErrMsg = 0;
    int rc = 0;
    std::stringstream sqlsentence;

    sqlsentence << "INSERT INTO PROM_MAX_MIN ('prom_veloc', 'max_velo', 'min_velo') VALUES (";
    sqlsentence << prom_vel_vient << ", " << max_vel_vient << ", " << min_vel_vient << ");" ;

rc = sqlite3_exec(_BD, sqlsentence.str().c_str(), 0, 0, &zErrMsg );

if (rc != SQLITE_OK )
    return (false);

return true;
}


bool DB_local::Guarda_Dire_vient(float min_dir_vient, float prom_dir_vient, float max_dir_vient){
    char* zErrMsg = 0;
    int rc = 0;
    std::stringstream sqlsentence;

    sqlsentence << "INSERT INTO PROM_MAX_MIN ('prom_direc', 'max_direc', 'min_direc') VALUES (";
    sqlsentence << prom_dir_vient << ", " << max_dir_vient << ", " << min_dir_vient << ");" ;

rc = sqlite3_exec(_BD, sqlsentence.str().c_str(), 0, 0, &zErrMsg );

if (rc != SQLITE_OK )
    return (false);

return true;
}


bool DB_local::Guarda_Preci(float min_preci, float prom_preci, float max_preci){
    char* zErrMsg = 0;
    int rc = 0;
    std::stringstream sqlsentence;

    sqlsentence << "INSERT INTO PROM_MAX_MIN ('prom_precip', 'max_precip', 'min_precip') VALUES (";
    sqlsentence << prom_preci << ", " << max_preci << ", " << min_preci << ");" ;

rc = sqlite3_exec(_BD, sqlsentence.str().c_str(), 0, 0, &zErrMsg );

if (rc != SQLITE_OK )
    return (false);

return true;
}


bool DB_local::Guarda_Inten(float min_inten, float prom_inten, float max_inten){
    char* zErrMsg = 0;
    int rc = 0;
    std::stringstream sqlsentence;

    sqlsentence << "INSERT INTO PROM_MAX_MIN ('prom_intensi', 'max_intensi', 'min_intensi') VALUES (";
    sqlsentence << prom_inten << ", " << max_inten << ", " << min_inten << ");" ;

rc = sqlite3_exec(_BD, sqlsentence.str().c_str(), 0, 0, &zErrMsg );

if (rc != SQLITE_OK )
    return (false);

return true;
}


