#include "TipoDispositivo.cpp"

#ifndef  SENSORHUMO

#define SENSORHUMO 1

class SensorHumo : public TipoDispositivo{
    public:
        SensorHumo(){}
        SensorHumo(string pNombre, List<TipoDispositivo> * dispositivos){
            this->name = pNombre;
            dispositivos->add(this);
            this->crearParametros("estado", "sensor de humo on");
            this->crearParametros("alarma", "sensor de humo sonó la alarma");

            this->crearAcciones("prender", "estado", "sensor de humo on");
            this->crearAcciones("apagar", "estado", "sensor de humo off");
            this->crearAcciones("prenderalarma", "alarma", "sensor de humo sonó la alarma");
            this->crearAcciones("apagaralarma", "alarma", "sensor de humo se apagó la alarma");
        }
};
#endif