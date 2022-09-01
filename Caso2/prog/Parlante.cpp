#include "TipoDispositivo.cpp"

#ifndef PARLANTE 

#define PARLANTE 1

class Parlante : public TipoDispositivo{
    public:
        Parlante(){}
        Parlante(string pNombre, List<TipoDispositivo> * dispositivos){
            this->name = pNombre;
            dispositivos->add(this);
            this->crearParametros("estado", "parlante on");
            this->crearParametros("musica", "parlante si");

            this->crearAcciones("prender", "estado", "parlante on");
            this->crearAcciones("apagar", "estado", "parlante off");
            this->crearAcciones("tocarmusica", "musica", "parlante si musica");
            this->crearAcciones("notocarmusica", "musica", "parlante no musica");
        }
};
#endif