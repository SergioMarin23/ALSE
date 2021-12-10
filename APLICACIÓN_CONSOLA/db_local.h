#ifndef DB_LOCAL_H
#define DB_LOCAL_H

#include <sqlite3.h>
#include "string"


using namespace std;

class DB_local{
public:
    DB_local( string path );
    bool Abrir_BaseDato();               //FUNCIÓN PARA ABRIR LA BASE DE DATOS LOCAL.
    bool Cerrar_BaseDato();              //FUNCIÓN QUE CIERRA LA BASE DE DATOS.
    bool GuardarDatos(float min_temp, float prom_temp, float max_temp,         //FUNCIÓN PARA INSERTAR TODOS LOS DATOS.
                      float min_hume, float prom_hume, float max_hume,
                      float min_vel_vient, float prom_vel_vient, float max_vel_vient,
                      int min_dir_vient, float prom_dir_vient, int max_dir_vient,
                      float min_preci, float prom_preci, float max_preci,
                      float min_inten, float prom_inten, float max_inten);
    float RecuperarTemperatura();


private:
    DB_local();
    sqlite3 *_BD;
    string _URL;
    static int callback(void* data, int argc, char* argv[], char* campos[]);
};

#endif // DB_LOCAL_H
