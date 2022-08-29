#include <string>
#include "Parameter.cpp"
#include "Action.cpp"
#include "../lista/lista.cpp"

#ifndef TIPODISPOSITIVO 

#define TIPODISPOSITIVO 1

using namespace std;

class TipoDispositivo{
    public:
        List<TipoDispositivo> dispositivos;
        string name; // nombre del tipo de dispositivo.
        List<tAction> acciones; // lista de acciones que pertenece al tipo de dispositivo
        TipoDispositivo(){ // constructor vacío.

        }
        List<tParameter> parametros; // lista de parámetros del tipo de dispositivo

        void crearParametros(string nombre, string valor){ // esta función crea los parámetros del tipo de dispositivo
            tParameter * parametro = new tParameter(); // obtiene un puntero a un estructura de parámetros

            this -> parametros.add(parametro); // añade la estructura a la lista
            parametro->name = nombre; // le cambia el nombre por el argumento
            parametro->value = valor; // le cambia el valor por el argumento
        }

        void crearAcciones(string actionName, string paramName, string paramValue){  // esta función crea las acciones del tipo de dispositivo  
            tAction * action = new tAction(); // crea un puntero a una estructura de acción
            
            this -> acciones.add(action); // la añade a la lista
            action->name = actionName; // le cambia el nombre
            action->parameterName = paramName; // le cambia el parámetro
            action->newValue = paramValue; // le cambia el valor de parámetro
        }
        
        void realizarAccion(string pNombreAccion){ // esta función realiza una acción

            tAction * action = this->acciones.find(pNombreAccion); // busca cuál acción es la que tiene que hacer
            
            tParameter * newParam = this -> parametros.find(action->parameterName); // busca cuál parámetro tiene que cambiar
            newParam->value =  action->newValue; // le cambia el valor
            cout << newParam->value << endl; // imprime el nuevo valor.
        }
};
#endif