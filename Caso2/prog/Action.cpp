#include <string>
using namespace std;

#ifndef TACTION 

#define TACTION 1

struct tAction{
    string name;  // nombre de la acción
    string parameterName; // nombre del parámetro que cambia
    string newValue; // nuevo valor del parámetro que cambia.
};
#endif