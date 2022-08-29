#include <string>
#include "Action.cpp"
#include "TipoDispositivo.cpp"
#include "../lista/lista.cpp"

#ifndef TAREA 

#define TAREA 1

using namespace std;



class Tarea{ // esta es la clase de tareas.
    public:
        string name; // el nombre de la tarea
        List<TipoDispositivo> listaDispositivosTarea; // esta lista contiene todos los dipositivos que se cambian en la tarea.
        
        Tarea(string pNombre){ // constructor que cambia el nombre de la tarea.
            this -> name = pNombre;
        }

        List<tAction> accionesTarea; // esta lista contiene todas las acciones que se realizan en la tarea.
        void asignarDispositivos(string nombreDisp, string accionName, List<TipoDispositivo> * dispositivos){ // esta función añade los dispositivos y acciones a la tarea
            TipoDispositivo * dispositivo = dispositivos->find(nombreDisp); // se crea un puntero al dispositivo que se ingresó
            listaDispositivosTarea.add(dispositivo); // se añade a la lista
            tAction * tareaAction = dispositivo->acciones.find(accionName); // se crea un puntero a la acción que se ingresó
            accionesTarea.add(tareaAction); // se añade a la lista
        }

        void realizarTarea(){ // esta función realiza la tarea.
            Node <TipoDispositivo> * DispositivoPtr = listaDispositivosTarea.first; // Se crea un puntero al primer nodo de la lista
            Node <tAction> * AccionPtr = accionesTarea.first; // Se crea un puntero al primer nodo de la lista
            while (DispositivoPtr != nullptr && AccionPtr != nullptr){ // mientras los punteros no sean nulos.
                TipoDispositivo * device = DispositivoPtr -> data; // se accede a los datos del puntero
                string action = (AccionPtr -> data)->name; // se accede a los datos del puntero.
                cout << device->name << endl; // se imprime el nombre del dispositivo
                device->realizarAccion(action); // se realiza la acción al dispositivo
                cout << endl; // Se imprime una línea en blanco
                DispositivoPtr = DispositivoPtr->next; // se mueven los punteros hacia adelante.
                AccionPtr = AccionPtr->next;
            }
        }
};


#endif