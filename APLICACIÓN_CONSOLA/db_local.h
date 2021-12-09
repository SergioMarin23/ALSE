#ifndef DB_LOCAL_H
#define DB_LOCAL_H

#include <sqlite3.h>
#include "string"


using namespace std;

class DB_local{
public:
    DB_local( string path );
    bool Abrir_BaseDato();                                                                      //FUNCIÓN PARA ABRIR LA BASE DE DATOS LOCAL.
    bool Cerrar_BaseDato();                                                                     //FUNCIÓN QUE CIERRA LA BASE DE DATOS.
    bool Guarda_Tempe(float min_temp, float prom_temp, float max_temp);                         //FUNCIÓN PARA INSERTAR LOS DATOS DE LA TEMPERATURA.
    bool Guarda_Hume(float min_hume, float prom_hume, float max_hume);                          //FUNCIÓN PARA INSERTAR LOS DATOS DE LA HUMEDAD.
    bool Guarda_Vel_vient(float min_vel_vient, float prom_vel_vient, float max_vel_vient);      //FUNCIÓN PARA INSERTAR LOS DATOS DE LA VELOCIDAD DEL VIENTO.
    bool Guarda_Dire_vient(float min_dir_vient, float prom_dir_vient, float max_dir_vient);     //FUNCIÓN PARA INSERTAR LOS DATOS DE LA DIRECCIÓN DEL VIENTO.
    bool Guarda_Preci(float min_preci, float prom_preci, float max_preci);                      //FUNCIÓN PARA INSERTAR LOS DATOS DE LAS PRECIPITACIONES.
    bool Guarda_Inten(float min_inten, float prom_inten, float max_inten);                      //FUNCIÓN PARA INSERTAR LOS DATOS DE LA INTENSIDAD LUMÍNICA.

private:
    DB_local();
    sqlite3 *_BD;
    string _URL;
};

#endif // DB_LOCAL_H
