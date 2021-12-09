#ifndef SENSOR_H
#define SENSOR_H

#include "cstdlib"
#include <time.h>

class Sensor{

public:

    Sensor();
    virtual float ActualizarDato();     //FUNCIÓN QUE EMULA EL ENVÍO DE LOS DATOS POR PARTE DE LOS SENSORES
    virtual ~Sensor() {};               //DESTRUCTOR PARA HACER USO DE MEMORIA DINÁMICA
};



class Temperatura: public Sensor{
public:
    float ActualizarDato(){                     //FUNCIÓN QUE EMULA EL ENVÍO DE LOS DATOS REFERENTES AL SENSOR DE TEMPERATURA
        srand(time(NULL));
        float t = ( -100 + rand() % (460 + 100) ) / 10. ;
        return t;
    }
};


class Humedad: public Sensor{
public:
    float ActualizarDato(){             //FUNCIÓN QUE EMULA EL ENVÍO DE LOS DATOS REFERENTES AL SENSOR DE HUMEDAD
        srand(time(NULL));
        float h = ( rand() % 101 ) / 10. ;
        return h;
    }
};


class Velocidad_viento: public Sensor{
public:
    float ActualizarDato(){         //FUNCIÓN QUE EMULA EL ENVÍO DE LOS DATOS REFERENTES AL SENSOR DE VELOCIDAD DEL VIENTO
        srand(time(NULL));
        float v = ( rand() % 41 ) / 10. ;
        return v;
    }
};


class Direccion_viento: public Sensor{
public:
    float ActualizarDato(){             //FUNCIÓN QUE EMULA EL ENVÍO DE LOS DATOS REFERENTES AL SENSOR DE DIRECCIÓN DEL VIENTO
        srand(time(NULL));
        float t = -180 + rand() % (181 + 180);
        return t;
    }
};


class Precipitacion: public Sensor{
public:
    float ActualizarDato(){         //FUNCIÓN QUE EMULA EL ENVÍO DE LOS DATOS REFERENTES AL SENSOR DE PRECIPITACIÓN
        srand(time(NULL));
        float t = rand() % 51 ;
        return t;
    }
};


class Intensidad_luz: public Sensor{
public:
    float ActualizarDato(){        //FUNCIÓN QUE EMULA EL ENVÍO DE LOS DATOS REFERENTES AL SENSOR DE INTENSIDAD LUMÍNICA
        srand(time(NULL));
        float t = rand() % 2001 ;
        return t;
    }
};
#endif // SENSOR_H
