#include "TipoDispositivo.cpp"

#ifndef BOMBILLO 

#define BOMBILLO 1

class Bombillo : public TipoDispositivo{
    public:
        Bombillo(){}
        Bombillo(string pNombre, List<TipoDispositivo> * dispositivos){
            this->name = pNombre;
            dispositivos->add(this);
            this->crearParametros("estado", "bombillo apagado");
            this->crearParametros("brillo", "el brillo está el 100%");
            this->crearAcciones("prender", "estado", "bombillo prendido");
            this->crearAcciones("apagar", "estado", "bombillo apagado");
            this->crearAcciones("bajar brillo", "brillo", "brillo del bombillo está al 50%");
            this->crearAcciones("subir brillo", "brillo", "brillo del bombillo está al 100%");
        }
};
#endif