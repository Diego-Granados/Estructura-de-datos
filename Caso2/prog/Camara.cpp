#include "TipoDispositivo.cpp"

#ifndef CAMARA 

#define CAMARA 1


class Camara : public TipoDispositivo{
    public:
        Camara(){}
        Camara(string pNombre, List<TipoDispositivo> * dispositivos){
            this->name = pNombre;
            dispositivos->add(this);
            this->crearParametros("estado", "camara on");
            this->crearParametros("grabar", "camara si");
            this->crearParametros("alarma", "camara sonó la alarma");
            this->crearParametros("notificacion", "camara enviar");
            

            this->crearAcciones("prender", "estado", "camara on");
            this->crearAcciones("apagar", "estado", "camara off");
            this->crearAcciones("grabar", "grabar", "camara si");
            this->crearAcciones("borrar", "grabar", "camara no");
            this->crearAcciones("prenderalarma", "alarma", "camara sonó la alarma");
            this->crearAcciones("apagaralarma", "alarma", "camara se apagó la alarma");
            this->crearAcciones("sendNoti", "notificacion", "camara enviar");
            this->crearAcciones("nosendNoti", "notificacion", "camara no enviar");
        }
};
#endif