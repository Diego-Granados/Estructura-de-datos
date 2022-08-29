#include "TipoDispositivo.cpp"

#ifndef HORNO 

#define HORNO 1

class Horno : public TipoDispositivo{
    public:
        Horno(){}
        Horno(string pNombre, List<TipoDispositivo> * dispositivos){
            this->name = pNombre;
            dispositivos->add(this);
            this->crearParametros("estado", "on");
            this->crearParametros("tostadas", "si");

            this->crearAcciones("prender", "estado", "horno on");
            this->crearAcciones("apagar", "estado", "horno off");
            this->crearAcciones("hacertostadas", "tostadas", "horno si tostadas");
            this->crearAcciones("nohacertostadas", "tostadas", "horno no tostadas");
        }
};
#endif