#include "sensor.h"
#include "db_local.h"
#include "iostream"
#include "sstream"
#include <vector>
#include <unistd.h>
#include <algorithm>

using namespace std;

int main(){

//CREACIÓN DE LOS O JETOS RELACIONADOS A LAS CLASES DE LOS SENSORES
    Temperatura temp;
    Humedad hum;
    Velocidad_viento vel_vien;
    Direccion_viento dir_vien;
    Precipitacion prec;
    Intensidad_luz inten;

//CREACIÓN DE VECTORES DONDE SE VAN A GUARDAR LOS DATOS DE LOS SENSORES
    std::vector<float> vec_temp;
    std::vector<float> vec_hum;
    std::vector<float> vec_vel;
    std::vector<int> vec_dir;
    std::vector<float> vec_preci;
    std::vector<float> vec_inten;

//PASANDO DATOS DE LOS SENSORES A LOS VECTORES CADA 5 SEGUNDOS
    int contador = 1;

    do{
        float _temp = temp.ActualizarDato();
        vec_temp.push_back(_temp);

        float _hum = hum.ActualizarDato();
        vec_hum.push_back( _hum );

        float _velo = vel_vien.ActualizarDato();
        vec_vel.push_back( _velo );

        int _direcc = dir_vien.ActualizarDato();
        vec_dir.push_back( _direcc );

        float _preci = prec.ActualizarDato();
        vec_preci.push_back( _preci );

        float _inten = inten.ActualizarDato();
        vec_inten.push_back( _inten );

        contador++;

        if( contador == 13 ){
        //hacer cálculo de promedio, maximo y minimo y borrar el contenido de los vectores

            //CALCULOS PARA EL VECTOR DE TEMPERATURA
            float tmp = 0.0;

            for(int i = 0 ; i < vec_temp.size(); i++)
                tmp += vec_temp[i];
            float prom_temp = tmp / 12;




        //INICIANDO PROCESO CON LA BASE DE DATOS
            DB_local b("SKYNET.db");
            b.Abrir_BaseDato();

            std::cout << b.Guarda_Tempe( 25.3, 31.1, 55.9) << std::endl;

            b.Cerrar_BaseDato();

            contador = 1;


        //vec_temp.clear();
        //vec_hum.clear();
        //vec_vel.clear();
        //vec_dir.clear();
        //vec_preci.clear();
        //vec_inten.clear();



        }

        sleep( 5 );

        //for(int i = 0; i < vec_temp.size(); i++)
        //    std::cout << &vec_temp[i] << std::endl;


        }while (true);

   return 0;


}





