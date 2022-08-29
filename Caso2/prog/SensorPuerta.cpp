#include "TipoDispositivo.cpp"


#ifndef SENSORPUERTA 

#define SENSORPUERTA 1

class SensorPuerta : public TipoDispositivo{
    public:
        SensorPuerta(){}
        SensorPuerta(string pNombre, List<TipoDispositivo> * dispositivos){
            this->name = pNombre;
            dispositivos->add(this);
            this->crearParametros("estado", "sensor de puerta on");
            this->crearParametros("abertura", "puerta cerrada");
            this->crearParametros("alarma", "sensor de puerta sonó la alarma");
            this->crearParametros("notificacion", "sensor de puerta no enviar");

            this->crearAcciones("prender", "estado", "sensor de puerta on");
            this->crearAcciones("apagar", "estado", "sensor de puerta off");
            this->crearAcciones("abrir", "abertura", "puerta abierta");
            this->crearAcciones("cerrar", "abertura", "puerta cerrada");
            this->crearAcciones("prenderalarma", "alarma", "sensor de puerta sonó la alarma");
            this->crearAcciones("apagaralarma", "alarma", "sensor de puerta se apagó la alarma");
            this->crearAcciones("sendNoti", "notificacion", "sensor de puerta enviar");
            this->crearAcciones("nosendNoti", "notificacion", "sensor de puerta no enviar");
        }
};
#endif