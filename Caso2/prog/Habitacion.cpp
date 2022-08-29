#include <string>
#include "../lista/lista.cpp"
#include "TipoDispositivo.cpp"
#include "Tarea.cpp"

using namespace std;

#ifndef HABITACION

#define HABITACION 1

class Habitacion{ // esta es la clase de habitaciones
    public:
        string name; // el nombre de la habitación
        Habitacion(string nombre){ // constructor de la habitación
            this -> name = nombre;
        }
        List<TipoDispositivo> dispositivosHab; // esta lista contiene todos los dispositivos de la habitación

        void añadirDispositivos(string nombreDisp, List<TipoDispositivo> * dispositivos){ // esta función añade los dispositivos que pertenecen a la habitación.
            TipoDispositivo * dispositivo = dispositivos->find(nombreDisp); // crea un puntero al dispositivo

            dispositivosHab.add(dispositivo); // lo añade a la habitación
        }
};
#endif