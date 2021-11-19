
//GRUPO FORMADO POR SARA XIMENA PRADA OCAMPP, SERGIO ANDRÉS MARÍN PATIÑO y JULIÁN DAVID PINZÓN ARANGO.

#include <sqlite3.h>
#include <stdio.h>
#include <string>


using namespace std;

int main(){

    sqlite3 *db;
    char *zErrMsg=0;
    int rc;
    string sqlstr;


// SE ABRE LA BASE DATOS LLAMADA "SKYNET"

    rc = sqlite3_open( "SKYNET.db", &db );

    if ( rc != 0 ){
        fprintf( stderr, "NO SE PUDO ABRIR LA BASE DE DATOS: %s\n", sqlite3_errmsg(db) );
        return 1;
    } else{
        fprintf( stderr, "BASE DE DATOS ABIERTA" );
    }


// SE CREAN LAS TABLAS DE LA BASE DE DATOS

//CREANDO TABLA DE SENSORES

    sqlstr = "CREATE TABLE SENSORES(id_sensor INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"\
             "temperatura REAL NOT NULL,"\
             "humedad REAL NOT NULL, velocidad_viento REAL NOT NULL,"\
             "direccion_viento INTEGER NOT NULL, precipitación REAL NOT NULL,"\
             "intensidad_luz REAL NOT NULL);";

    rc = sqlite3_exec( db, sqlstr.c_str(), 0, 0, &zErrMsg );

    if ( rc != SQLITE_OK ){
        fprintf( stderr, "SQL ERROR: %s\n", zErrMsg );
        sqlite3_free( zErrMsg );
        return 2;
    } else {
        fprintf( stdout, "TABLA CREADA\n");
    }


//CREANDO TABLA DE PROMEDIOS, MAXIMOS Y MINIMOS

    sqlstr = "CREATE TABLE PROM_MAX_MIN(prom_temp REAL NOT NULL,"\
             "max_temp REAL NOT NULL, min_temp REAL NOT NULL,"\
             "prom_humed REAL NOT NULL, max_humed REAL NOT NULL,"\
             "min_humed REAL NOT NULL, prom_veloc REAL NOT NULL,"\
             "max_velo REAL NOT NULL, min_velo REAL NOT NULL,"\
             "prom_direc REAL NOT NULL, max_direc REAL NOT NULL,"\
             "min_direc REAL NOT NULL, prom_precip REAL NOT NULL,"\
             "max_precipi REAL NOT NULL, min_precipi REAL NOT NULL,"\
             "prom_intensi REAL NOT NULL, max_intensi REAL NOT NULL,"\
             "min_intensi REAL NOT NULL);";

    rc = sqlite3_exec( db, sqlstr.c_str(), 0, 0, &zErrMsg );

    if ( rc != SQLITE_OK ){
        fprintf( stderr, "SQL ERROR: %s\n", zErrMsg );
        sqlite3_free( zErrMsg );
        return 3;
    } else {
        fprintf( stdout, "TABLA CREADA\n");
    }


//CREANDO TABLA DE DATOS DE LOS USUARIOS QUE SE HAN REGISTRADO

    sqlstr = "CREATE TABLE DATOS_USUARIOS(id_usuario INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"\
             "nombre TEXT NOT NULL,"\
             "apellido TEXT NOT NULL, documento INTEGER NOT NULL,"\
             "fecha_nacimiento TEXT NOT NULL, usuario TEXT NOT NULL,"\
             "contraseña TEXT NOT NULL);";

    rc = sqlite3_exec( db, sqlstr.c_str(), 0, 0, &zErrMsg );

    if ( rc != SQLITE_OK ){
        fprintf( stderr, "SQL ERROR: %s\n", zErrMsg );
        sqlite3_free( zErrMsg );
        return 4;
    } else {
        fprintf( stdout, "TABLA CREADA\n");
    }


//CREANDO TABLA DE USUARIOS QUE HAN INICIADO LA APLICACÓN

    sqlstr = "CREATE TABLE USUARIOS_REGISTRADOS(id_usuario INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"\
             "usuario TEXT NOT NULL, fecha_ejecución TEXT NOT NULL, hora_ejecución TEXT NOT NULL);";

    rc = sqlite3_exec( db, sqlstr.c_str(), 0, 0, &zErrMsg );

    if ( rc != SQLITE_OK ){
        fprintf( stderr, "SQL ERROR: %s\n", zErrMsg );
        sqlite3_free( zErrMsg );
        return 5;
    } else {
        fprintf( stdout, "TABLA CREADA\n");
    }

sqlite3_close(db);
return 0;

}
