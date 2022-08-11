// Diego Granados
// Estructuras de datos IC-2001
// Quiz 1 y 2
// 11 de agosto, 2022
 /* 
 Utilizando arreglos en C++ escriba una estructura de datos que le 
 permita modelar un tren de N vagones y escriba una función que reciba
 el tren por parámetro, luego liste los 10 primeros y los 10 últimos 
 asientos disponibles. Eso hace que el tren por definición tenga 
 alguna forma de marcar los asientos ya ocupados.  
 */

/* 
Solución:
El tren está diseñado como un array de dos dimensiones: la primera para los vagones y segunda para los asientos
de cada vagón. Los elementos son booleanos, en los cuales false indica que el asiento está ocupado y true que está
libre. La función asientosVacios recorre cada vagón, buscando los asientos que estén disponibles. Si encuentra
uno, lo imprime y sigue con el siguiente. Se detiene hasta que haya recorrido todo el tren o ya haya encontrado 
los primeros 10 disponibles. Luego, repite el mismo proceso, nada más que al revés, empezando desde el final 
del tren. Va disminuyendo los índices del asiento y vagón en lugar de incrementarlos.
*/

#include <iostream>

using namespace std;

 // se definen las constantes para luego declarar los arrays
#define VAGON 3 // Esta es la constante que tiene la cantidad de vagones
#define ASIENTOS 10 // Esta es la constante que tiene la cantidad de asientos en cada vagón

// Esta función despliega los primeros 10 espacios disponibles y los últimos 10 espacios disponibles.
void asientosVacios(bool tren[][ASIENTOS]){
    int x = 0; // se va a utilizar para contar los espacios que ya se han desplegado
    int wagon = 0; // se va a utilizar para contar los vagones que se van recorriendo
    int seat; // se va a utilizar para recorrer los asientos
    cout << "Asientos disponibles adelante: " << endl;
    while (x < 10 && wagon < VAGON){ // mientras el número de asientos ya desplegados no sea mayor a 10 y no se haya recorrido todo el tren
        seat = 0; // se ponen los asientos en 0 para empezar desde el principio en cada vagón
        while (x < 10 && seat < ASIENTOS){ // mientras el número de asientos ya desplegados no sea mayor a 10 y no se haya recorrido todo el vagón
            if (tren[wagon][seat]) { // si el asiento actual está con el valor de verdadero, signfica que está vacío
                ++x; // se incrementa el número de asientos desplegados
                cout << "Asiento " << x << ": Vagón " << (wagon + 1) << ", Asiento " << (seat + 1) << endl; // se despliega el asiento con los números correctamente         
            } 
            ++seat; // se incrementa el asiento para ir al siguiente
        }
        ++wagon; // se incrementa el vagón para ir al siguiente
    }    

    cout << endl; // se imprime un cambio de línea para ser más ordenado

    x = 0; // se restauran el número de asientos desplegados
    wagon = (VAGON-1); // Se establece el valor del vagón al último para empezar desde atrás
    cout << "Asientos disponibles atrás: " << endl; // se da un mensaje para indicar los asientos que se van a desplegar
    while (x < 10 && wagon >= 0){ // mientras el número de asientos desplegados no sea mayor a 10 y no se haya terminado de recorrer todo el tren
        seat = (ASIENTOS-1); // se establece el asiento al último para empezar desde atrás.
        while (x < 10 && seat >= 0){ // mientras el número de asientos desplegados no sea mayor a 10 y no se haya terminado de recorrer todo el vagón
            if (tren[wagon][seat]) { // si el asiento es true, significa que está desocupado
                ++x; // se incrementa el número de asientos desplegados
                cout << "Asiento " << x << ": Vagón " << (wagon + 1) << ", Asiento " << (seat + 1) << endl; // se despliega el asiento correctamente
            } 
            --seat; // se disminuye el asiento para ir al siguiente
        }
        --wagon; // se disminuye el vagón para ir al siguiente.
    }   
}

int main()
{  // se crea el tren. Este es un ejemplo que tiene 3 vagones, donde cada vagón tiene 10 asientos.
    bool tren[VAGON][ASIENTOS] = {{false, true, false, false, true, true, false, true, false, true},\
                      {false, false, false, true, false, false, true, false, true, true},\
                      {false, true, true, false, false, true, false, true, true, false}};
    asientosVacios(tren); // Se llama a la función
}