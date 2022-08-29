// Diego Granados
// Estructuras de datos IC-2001
// Caso 2: Aplicaciones 4home
// 29 de agosto, 2022

#include "../lista/lista.cpp"
#include "Action.cpp"
#include "Habitacion.cpp"
#include "Parameter.cpp"
#include "TipoDispositivo.cpp"
#include "Tarea.cpp"
#include "Bombillo.cpp"
#include "Camara.cpp"
#include "SensorHumo.cpp"
#include "SensorPuerta.cpp"
#include "Horno.cpp"
#include "Parlante.cpp"
#include "CoffeeMaker.cpp"


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Listas

List<TipoDispositivo> * dispositivos = new List<TipoDispositivo>;

List<Habitacion> Casa;

// creación de dispositivos específicos.
Bombillo luzcalida("luz calida", dispositivos);
Bombillo luzfria("luz fria", dispositivos);
Bombillo nightlight("night light", dispositivos);
Bombillo luzcocina("luz cocina", dispositivos);

SensorHumo smokedetectorkitchen("sensor de humo cocina", dispositivos);

SensorPuerta doordetector("sensor de puerta", dispositivos);

CoffeeMaker coffeemakerkitchen("coffee maker cocina", dispositivos);

Horno hornito("hornito cocina", dispositivos);

Parlante Alexa("Alexa", dispositivos);

Camara camaracuarto("camara cuarto", dispositivos);

Habitacion cuarto("Cuarto");

Habitacion cocina("Cocina");

Tarea BuenosDias("Buenos días");

Tarea BuenasNoches("Buenas noches");




// función principal
int main(){
    cout << "App 4Home\n" << endl;
    
    Casa.add(&cuarto); // se añaden los cuartos a la casa.
    Casa.add(&cocina);


    cuarto.añadirDispositivos("luz fria", dispositivos);
    cuarto.añadirDispositivos("night light", dispositivos);
    cuarto.añadirDispositivos("camara cuarto", dispositivos);
    cuarto.añadirDispositivos("Alexa", dispositivos);

    cocina.añadirDispositivos("luz calida", dispositivos);
    cocina.añadirDispositivos("luz cocina", dispositivos);
    cocina.añadirDispositivos("sensor de humo cocina", dispositivos);
    cocina.añadirDispositivos("sensor de puerta", dispositivos);
    cocina.añadirDispositivos("coffee maker cocina", dispositivos);
    cocina.añadirDispositivos("hornito cocina", dispositivos);

    BuenosDias.asignarDispositivos("luz fria", "apagar", dispositivos);
    BuenosDias.asignarDispositivos("luz calida", "prender", dispositivos);
    BuenosDias.asignarDispositivos("night light", "apagar", dispositivos);
    BuenosDias.asignarDispositivos("luz cocina", "prender", dispositivos);
    BuenosDias.asignarDispositivos("coffee maker cocina", "prender", dispositivos);
    BuenosDias.asignarDispositivos("coffee maker cocina", "subirtemperatura", dispositivos);
    BuenosDias.asignarDispositivos("coffee maker cocina", "ponerleche", dispositivos);
    BuenosDias.asignarDispositivos("hornito cocina", "prender", dispositivos);
    BuenosDias.asignarDispositivos("hornito cocina", "hacertostadas", dispositivos), dispositivos;
    BuenosDias.asignarDispositivos("Alexa", "prender", dispositivos);
    BuenosDias.asignarDispositivos("Alexa", "tocarmusica", dispositivos);
    BuenosDias.asignarDispositivos("sensor de humo cocina", "prender", dispositivos);
    BuenosDias.asignarDispositivos("sensor de puerta", "prender", dispositivos);
    BuenosDias.asignarDispositivos("camara cuarto", "apagar", dispositivos);
    
    cout << BuenosDias.name << endl << endl;
    BuenosDias.realizarTarea();

    cout << endl;

    BuenasNoches.asignarDispositivos("luz fria", "apagar", dispositivos);
    BuenosDias.asignarDispositivos("luz calida", "apagar", dispositivos);
    BuenosDias.asignarDispositivos("night light", "prender", dispositivos);
    BuenosDias.asignarDispositivos("luz cocina", "apagar", dispositivos);
    BuenosDias.asignarDispositivos("coffee maker cocina", "apagar", dispositivos);
    BuenosDias.asignarDispositivos("hornito cocina", "apagar", dispositivos);
    BuenosDias.asignarDispositivos("Alexa", "apagar", dispositivos);
    BuenosDias.asignarDispositivos("sensor de humo cocina", "prender", dispositivos);
    BuenosDias.asignarDispositivos("sensor de puerta", "prender", dispositivos);
    BuenosDias.asignarDispositivos("camara cuarto", "prender", dispositivos);
}