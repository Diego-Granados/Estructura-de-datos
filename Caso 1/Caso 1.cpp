// Diego Granados
// Estructuras de datos IC-2001
// Caso 1: Teorema Four Color
// 13 de agosto, 2022

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct region {
    short color = 0; // Se va a utilizar para almacenar el color de cada region.
    vector<short> adyacentes = {}; // Se va a utilizar para almacenar 
    short ubicacion; // Se va a utilizar para almacenar cuál región es correctamente, es para identificar cuál región es
    vector<short> coloresUsados = {}; // Se va a usar para almacenar cuáles colores ya se han usado, por lo que podrán ser el color de la región
};

vector<short> colores = {1,2,3,4}; // Se utiliza para almacenar los colores

// Esta función se va a utilizar si un color pertenece a un conjunto de colores
bool containColor(short color, vector<short> conjunto){
    for (short elem : conjunto){ // Se recorre el conjunto de colores.
        if (color == elem){ // Si el color a buscar es igual al color actual
            return true; // se retorna true
        }
    }
    return false; // Si no se encuentra, se retorna false
}

int main()
{  
// Se declaran las regiones
    region a;
    a.ubicacion = 1;
//    a.adyacentes = {2,3,4,5,6,7};
    a.color = 0;
    
    region b;
    b.ubicacion = 2;
//    b.adyacentes = {1,3,7,8};
    b.color = 0;
    
    
    region c;
    c.ubicacion = 3;
//    c.adyacentes = {1,2,4,8,10};
    c.color = 0;
    
    region d;
    d.ubicacion = 4;
//    d.adyacentes = {1,3,5,10};
    d.color = 0;
    
    region e;
    e.ubicacion = 5;
  //  e.adyacentes = {1,4,6,9,10};
    e.color = 0;
    
    region f;
    f.ubicacion = 6;
 //   f.adyacentes = {1,5,7,9};
    f.color = 0;
    
    region g;
    g.ubicacion = 7;
 //   g.adyacentes = {1,2,6,8,9};
    g.color = 0;
    
    region h;
    h.ubicacion = 8;
//    h.adyacentes = {2,3,7,9,10};
    h.color = 0;
    
    region i;
    i.ubicacion = 9;
//    i.adyacentes = {5,6,7,8,10};
    i.color = 0;

    region j;
    j.ubicacion = 10;
//    j.adyacentes = {3,4,5,8,9};
    j.color = 0;  


    region k;
    k.ubicacion = 11;
    k.color = 0;  

    region l;
    l.ubicacion = 12;
    l.color = 0;  

    region m;
    m.ubicacion = 13;
    m.color = 0;  

    region n;
    n.ubicacion = 14;
    n.color = 0;  

    region o;
    o.ubicacion = 15;
    o.color = 0;  

    region p;
    p.ubicacion = 16;
    p.color = 0;  

    region r;
    r.ubicacion = 18;
    r.color = 0;  

    region q;
    q.ubicacion = 17;
    q.color = 0;  

    region s;
    s.ubicacion = 19;
    s.color = 0;

    region t;
    t.ubicacion = 20;
    t.color = 0;  

    region u;
    u.ubicacion = 21;
    u.color = 0;   
    
    region v;
    v.ubicacion = 22;
    v.color = 0;  

    region w;
    w.ubicacion = 23;
    w.color = 0;  

    region x;
    x.ubicacion = 24;
    x.color = 0;  

    region y1;
    y1.ubicacion = 25;
    y1.color = 0;  

    region z;
    z.ubicacion = 26;
    z.color = 0;  

    region a1;
    a1.ubicacion = 27;
    a1.color = 0;

    region b1;
    b1.ubicacion = 28;
    b1.color = 0;

    region c1;
    c1.ubicacion = 29;
    c1.color = 0;

    region d1;
    d1.ubicacion = 30;
    d1.color = 0;

    region e1;
    e1.ubicacion = 31;
    e1.color = 0;

    region f1;
    f1.ubicacion = 32;
    f1.color = 0;

    region g1;
    g1.ubicacion = 33;
    g1.color = 0;

    region h1;
    h1.ubicacion = 34;
    h1.color = 0;
    
// Se dan las regiones de los adyacentes.
    a.adyacentes = {2,3,6};
    b.adyacentes = {1,3,5};
    c.adyacentes = {1,2,4,5,6,7,8};
    d.adyacentes = {3,6,7};
    e.adyacentes = {2,3,8};
    f.adyacentes = {1,3,4,7,9,13,12,18};
    g.adyacentes = {3,4,6,8,10};
    h.adyacentes = {5,3,7,11,17,23};
    i.adyacentes = {6,14,10};
    j.adyacentes = {7,9,11,15};
    k.adyacentes = {8,10,16};
    l.adyacentes = {6,13,19,18};
    m.adyacentes = {6,12,14,19,20,21};
    n.adyacentes = {9,15,13,21};
    o.adyacentes = {10,14,21,16};
    p.adyacentes = {15,11,17,23,21,22};
    q.adyacentes = {8,16};
    r.adyacentes = {6,12,19,25,27};
    s.adyacentes = {12,13,18,26,30};
    t.adyacentes = {13,30,21};
    u.adyacentes = {15,14,13,20,30,31,34,22,16};
    v.adyacentes = {16,21,34,32,24};
    w.adyacentes = {16,24,8};
    x.adyacentes = {2,23};
    y1.adyacentes = {18,26,28};
    z.adyacentes = {19,25,29};
    a1.adyacentes = {18,28,30};
    b1.adyacentes = {27,25,29};
    c1.adyacentes = {26,28,30};
    d1.adyacentes = {29,27,19,20,21,31,34,33};
    e1.adyacentes = {21,30,34};
    f1.adyacentes = {22,34};
    g1.adyacentes = {30,34};
    h1.adyacentes = {30,31,21,22,33,32};

// Se construye el mapa
    vector<region> mapa = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y1,z,a1,b1,c1,d1,e1,f1,g1,h1};
    vector<short> adyacentesOrdenados; // Se va a usar para ordenar la lista de adyacentes
    short cantAdyacentes; // Se usa para ordenar la lista de adyacentes
    short y = 0; // Se va usar para recorrer el mapa.
    for (; y < size(mapa); y++){
        cout << "Region: " << mapa[y].ubicacion << endl;
        sort(mapa[y].coloresUsados.begin(),mapa[y].coloresUsados.end());

        // para ordenar las adyacencias con base en cuál tiene menor adyacencias.
        adyacentesOrdenados = {};

        for (cantAdyacentes = 1; size(adyacentesOrdenados) < size(mapa[y].adyacentes); cantAdyacentes++){ // mientras la lista de adyacentes ordenados sea más pequeña que la de adyacentes
            for (short adyacente : mapa[y].adyacentes){ // se itera por cada adyacente para encontrar los que tengan la menor cantidad de adyacencias.
                if (size(mapa[adyacente-1].adyacentes) == cantAdyacentes) { // Si la cantidad de adyacencias es igual a la que se está buscando
                    adyacentesOrdenados.push_back(adyacente); // se añade a la lista en el orden correcto
                }
            }
        }
        
        mapa[y].adyacentes = adyacentesOrdenados; // Se cambia la lista de adyacentes a la lista ordenada
         
        if (size(mapa[y].coloresUsados) >= size(colores)){ // Si la lista de colores usados de la región actual es mayor o igual que la cantidad de colores,
            short cambio = 0;                                        // eso significa que no se pueden escoger un color para la región, por lo que se tiene que cambiar algunos de los adyacentes. 
            for (short adyacente : mapa[y].adyacentes) { 
                if (size(mapa[adyacente-1].coloresUsados) < 4) { // Si la lista de colores usados del adyacente actual es menor que la cantidad de colores, eso significa que tiene otros colores disponibles.
                    for (short opcion : colores){ // Se recorre la lista de colores
                        if (containColor(opcion, mapa[adyacente-1].coloresUsados) == false && opcion != mapa[adyacente-1].color){ // Si la opción actual no está en la lista de colores usados y no es igual al color actual,
                            if (cambio == 0){ // la variable de cambio se usa para representar el color que se va a liberar,
                                cambio = mapa[adyacente-1].color; // luego de establecerse, solo se van a cambiar las regiones que tengan ese color.
                            }
                            if (mapa[adyacente-1].color != cambio){ // Si la región no es del color a cambiar, continúa el recorrido.
                                continue;
                            }
                            short elem = 1; // se intenta borrar el color actual para desactivarlo
                            for (auto iterator = mapa[y].coloresUsados.begin(); iterator != mapa[y].coloresUsados.end();++iterator){
                                if (elem == mapa[adyacente-1].color){ // si el color que se borró es igual al elemento actual, 
                                    mapa[y].coloresUsados.erase(iterator); // se borra.
                                    break; // se rompe el ciclo.
                                }
                                ++elem; // si no, se incrementa el elemento.
                            }
                            mapa[adyacente-1].color = opcion; // Se cambia el color actual al nuevo
                            for (short seccion : mapa[adyacente-1].adyacentes){ // recorre la lista de adyacentes de esa región para eliminarles el color nuevo como opción.
                                if (containColor(mapa[adyacente-1].color,mapa[seccion-1].coloresUsados) == false){
                                    mapa[seccion-1].coloresUsados.push_back(mapa[adyacente-1].color); 
                                }
                            }                            
                            cout << "Color nuevo del adyacente " << mapa[adyacente-1].ubicacion << ": " << mapa[adyacente-1].color << endl;
                            break; // se rompe el ciclo.
                        }
                    }
                }   
            }

            for (short adyacente : mapa[y].adyacentes) { // Se recorre la lista de adyacentes para actualizar los colores usados
                if (containColor(mapa[adyacente-1].color,mapa[y].coloresUsados) == false){ // Si el color actual no está en la lista
                    mapa[y].coloresUsados.push_back(mapa[adyacente-1].color); //  lo añade.
                }
            }   
            
            // Si después de todo este proceso la lista de colores usados sigue siendo mayor o igual a la cantidad de colores, 
            if (size(mapa[y].coloresUsados) >= size(colores)){ // el mapa no se puede colorear con la cantidad de colores disponible
                for (short adyacente : mapa[y].adyacentes) {
                    cout <<  "Adyacente: " << mapa[adyacente-1].ubicacion << ",Color: " << mapa[adyacente-1].color << endl; 
                }
                for (short color: mapa[y].coloresUsados){
                    cout << "Color: " << color << endl;
                }
                cout << "ERROR: ESTA MAPA NO SE PUEDE COLOREAR!" << endl;  // se imprime un mensaje de error.
                break; // se rompe el ciclo.
            }
        }
        
        for (short opcion : colores){ // se recorre la lista de colores
            if (containColor(opcion, mapa[y].coloresUsados) == false){ // Si el color actual no está en la lista colores actuales, está disponible
                mapa[y].color = opcion; // Se asigna el color de la región
                cout << "Color escogido: " << mapa[y].color << endl; 
                for (short adyacente : mapa[y].adyacentes){ // Se recorre la lista de adyacentes para añadir el color escogido a la lista de colores usados
                    if (containColor(mapa[y].color,mapa[adyacente-1].coloresUsados) == false){ // Si el color escogido no está en la lsita de colores usados,
                        mapa[adyacente-1].coloresUsados.push_back(mapa[y].color);  // lo añade
                    }
                }
                break; // se termina el ciclo
            }
        }
    cout << endl;
    }
    // Si al final de recorrer todo el mapa no se detuvo el ciclo y se terminó de iterar todo, eso significa que "y" debe ser igual o mayor al tamaño del mapa
    if (y >= size(mapa)) // Si es el caso, se imprime un mensaje de éxito.
        cout << "Este mapa se puede colorear!" << endl;
    return true;
}