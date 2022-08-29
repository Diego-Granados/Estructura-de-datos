#include "TipoDispositivo.cpp"

#ifndef COFFEEMAKER 

#define COFFEEMAKER 1

class CoffeeMaker : public TipoDispositivo{
    public:
        CoffeeMaker(){}
        CoffeeMaker(string pNombre, List<TipoDispositivo> * dispositivos){
            this->name = pNombre;
            dispositivos->add(this);
            this->crearParametros("estado", "Coffee Maker on");
            this->crearParametros("temperatura", "Coffee Maker temperatura alta");
            this->crearParametros("leche", "Coffee Maker no");

            this->crearAcciones("prender", "estado", "Coffee Maker on");
            this->crearAcciones("apagar", "estado", "Coffee Maker off");
            this->crearAcciones("subirtemperatura", "temperatura", "Coffee Maker temperatura alta");
            this->crearAcciones("bajartemperatura", "temperatura", "Coffee Maker temperatura baja");
            this->crearAcciones("ponerleche", "leche", "Coffee Maker si leche");
            this->crearAcciones("noponerleche", "temperatura", "Coffee Maker no leche");

        }
};
#endif