#include "sensor.h"
#include "db_local.h"
#include "iostream"
#include "sstream"
#include <vector>
#include <unistd.h>
#include <algorithm>

using namespace std;

int main(){

//CREACIÓN DE LOS OBJETOS RELACIONADOS A LAS CLASES DE LOS SENSORES
    Temperatura temp;
    Humedad hum;
    Velocidad_viento vel_vien;
    Direccion_viento dir_vien;
    Precipitacion prec;
    Intensidad_luz inten;


//CREACIÓN DE VECTORES DONDE SE VAN A GUARDAR LOS DATOS DE LOS SENSORES
    vector<float> vec_temp;
    vector<float> vec_hum;
    vector<float> vec_vel;
    vector<int> vec_dir;
    vector<float> vec_preci;
    vector<float> vec_inten;

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
                tmp += vec_temp[i];                      //HALLANDO EL PROMEDIO DE LA TEMPERATURA
            float prom_temp = tmp / 12;

            float max_temp = vec_temp[0];
            for( int i = 1; i < vec_temp.size(); i++ )
                if( max_temp < vec_temp[i] )               //HALLANDO EL MAXIMO DE LA TEMPERATURA
                    max_temp = vec_temp[i];

            float min_temp = vec_temp[0];
            for( int i = 1; i < vec_temp.size(); i++)
                if( min_temp > vec_temp[i] )               //HALLANDO EL MÍNIMO DE LA TEMPERATURA
                    min_temp = vec_temp[i];


            //CALCULOS PARA EL VECTOR DE HUMEDAD
            float tmp1 = 0.0;
            for(int i = 0 ; i < vec_hum.size(); i++)
                tmp1 += vec_temp[i];                    //HALLANDO EL PROMEDIO DE LA HUMEDAD
            float prom_hum = tmp1 / 12;

            float max_hum = vec_temp[0];
            for( int i = 1; i < vec_hum.size(); i++ )
                if( max_hum < vec_hum[i] )               //HALLANDO EL MAXIMO DE LA HUMEDAD
                    max_hum = vec_hum[i];

            float min_hum = vec_hum[0];
            for( int i = 1; i < vec_hum.size(); i++)
                if( min_hum > vec_hum[i] )               //HALLANDO EL MÍNIMO DE LA HUMEDAD
                    min_hum = vec_hum[i];


            //CALCULOS PARA EL VECTOR DE VELOCIDAD DEL VIENTO
            float tmp2 = 0.0;
            for(int i = 0 ; i < vec_vel.size(); i++)
                tmp2 += vec_vel[i];                    //HALLANDO EL PROMEDIO DE LA VELOCIDAD DEL VIENTO
            float prom_velo = tmp2 / 12;

            float max_velo = vec_temp[0];
            for( int i = 1; i < vec_vel.size(); i++ )
                if( max_velo < vec_vel[i] )               //HALLANDO EL MAXIMO DE LA VELOCIDAD DEL VIENTO
                    max_velo = vec_vel[i];

            float min_velo = vec_vel[0];
            for( int i = 1; i < vec_vel.size(); i++)
                if( min_velo > vec_vel[i] )               //HALLANDO EL MÍNIMO DE LA VELOCIDAD DEL VIENTO
                    min_velo = vec_vel[i];


            //CALCULOS PARA EL VECTOR DE DIRECCION DEL VIENTO
            float tmp3 = 0.0;
            for(int i = 0 ; i < vec_dir.size(); i++)
                tmp3 += vec_dir[i];                    //HALLANDO EL PROMEDIO DE LA DIRECCION DEL VIENTO
            float prom_direc = tmp3 / 12;

            int max_direc = vec_dir[0];
            for( int i = 1; i < vec_dir.size(); i++ )
                if( max_direc < vec_dir[i] )               //HALLANDO EL MAXIMO DE LA DIRECCION DEL VIENTO
                    max_direc = vec_dir[i];

            int min_direc = vec_dir[0];
            for( int i = 1; i < vec_dir.size(); i++)
                if( min_direc > vec_dir[i] )               //HALLANDO EL MÍNIMO DE LA DIRECCION DEL VIENTO
                    min_direc = vec_dir[i];


            //CALCULOS PARA EL VECTOR DE PRECIPITACIONES
            float tmp4 = 0.0;
            for(int i = 0 ; i < vec_preci.size(); i++)
                tmp4 += vec_preci[i];                    //HALLANDO EL PROMEDIO DE PRECIPITACIONES
            float prom_preci = tmp4 / 12;

            float max_preci = vec_preci[0];
            for( int i = 1; i < vec_preci.size(); i++ )
                if( max_preci < vec_preci[i] )               //HALLANDO EL MAXIMO DE PRECIPITACIONES
                    max_preci = vec_preci[i];

            float min_preci = vec_preci[0];
            for( int i = 1; i < vec_preci.size(); i++)
                if( min_preci > vec_preci[i] )               //HALLANDO EL MÍNIMO DE PRECIPITACIONES
                    min_preci = vec_preci[i];


            //CALCULOS PARA EL VECTOR DE INTENSIDAD LUMÍNICA
            float tmp5 = 0.0;
            for(int i = 0 ; i < vec_inten.size(); i++)
                tmp5 += vec_inten[i];                    //HALLANDO EL PROMEDIO DE LA INTENSIDAD LUMÍNICA
            float prom_inten = tmp5 / 12;

            float max_inten = vec_inten[0];
            for( int i = 1; i < vec_inten.size(); i++ )
                if( max_inten < vec_inten[i] )               //HALLANDO EL MAXIMO DE LA INTENSIDAD LUMÍNICA
                    max_inten = vec_inten[i];

            float min_inten = vec_inten[0];
            for( int i = 1; i < vec_inten.size(); i++)
                if( min_inten > vec_inten[i] )               //HALLANDO EL MÍNIMO DE LA INTENSIDAD LUMÍNICA
                    min_inten = vec_inten[i];

        //GUARDANDO DATOS EN LA TABLA
        DB_local b("/home/maquinirris/Documents/ALSE_2120/PROYECTO_FINAL_ALSE-2021-2/SKYNET.db");

        b.Abrir_BaseDato();

        b.GuardarDatos(min_temp, prom_temp, max_temp,
                       min_hum, prom_hum, max_hum,
                       min_velo, prom_velo, max_velo,
                       min_direc, prom_direc, max_direc,
                       min_preci, prom_preci, max_preci,
                       min_inten, prom_inten, max_inten);

       b.Cerrar_BaseDato();

       //HACIENDO ALERTA DE LAS PAPAS Y LAS ROSAS
          vector<float> alert;
          int dia_calor = 0;

          float temp_recup = b.RecuperarTemperatura();
          alert.push_back(temp_recup);

          for(int i = 0; i < alert.size(); i++ ){
              if( alert[i] == alert[i+1])
                  cout << "HAY UNA AMENAZA CONSIDERABLE DE HONGO" << endl;
              if (alert[i] > 10){
                 dia_calor = dia_calor + 1;
                 cout << "LLEVA " << dia_calor << "DÍAS DE CALOR ACUMULADOS." << endl;
              }
          }

       //BORRANDO LOS DATOS DE LOS VECTORES Y VOLVIENDO A INICIAR
       contador = 1;

        vec_temp.clear();
        vec_hum.clear();
        vec_vel.clear();
        vec_dir.clear();
        vec_preci.clear();
        vec_inten.clear();

        }



        sleep( 1 );





        }while (true);



return 0;
}





