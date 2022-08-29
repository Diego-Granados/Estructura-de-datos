## Estructura de datos: Caso 2
# Diego Granados Retana
# 29 de agosto

Para solucionar el problema, utilicé varias clases y estructuras.

# Nodo
Esta clase se utiliza para almacenar los datos que pertenecen a la lista. Utiliza punteros para acceder a los datos en sí correctamente.  
`
template <class T>

class Node {
        
    
    public:
        T *data;
        Node *next;
        Node() {
            data = nullptr;
            next = nullptr;
        }

        Node(T *pData) {
            this->data = pData;
            next = nullptr;
        }

        T* getData() {
            return data;
        }

        Node* getNext() {
            return next;
        }

        void setNext(Node *pValue) {
            this->next = pValue;
        }
};
`

# List
Esta es la clase que se usa para crear las listas enlazadas. Sus elementos son los nodos del tipo necesario.
`
template <class T>
class List {
        

    public:
        Node<T> *first;
        Node<T> *last;
        int quantity;
        bool empty;

        List() {
            first = nullptr;
            last = nullptr;
            quantity = 0;
            empty = true;
        }

        void add(T *pData) {
            Node<T> *newNode = new Node<T>(pData);

            if (quantity>0) {
                this->last->setNext(newNode);
                this->last = newNode;
            } else {
                this->first = newNode;
                this->last = newNode;
            }

            empty = false;
            quantity++;
        }

        Node<T>* getFirst() {
            return this->first;
        }

        int getQuantity() {
            return quantity;
        }

        T* find(string pData){
            Node<T> * searchPtr = this->first;
            while (searchPtr != nullptr && searchPtr->getData()->name != pData){
                searchPtr = searchPtr->next;
            }
            if (searchPtr == nullptr){
                cout << "Se terminó la lista" << endl;
            }
            return (searchPtr->data);
        }

        void PrintList(){
            Node<T> * printPtr = this->first;
            while(printPtr != nullptr){
                cout << printPtr->data->name << endl;
                printPtr = printPtr-> next;
            }
        }
};
`

# Parameter
En esta estructura almaceno los parámetros de cada dispositivo. Las acciones van a poder cambiar estos parámetros.
`
struct tParameter {
    string name; // nombre del parametro
    string value; // valor del parametro
};
`

# Action
Esta es la estructura que uso para crear las acciones. Tiene un nombre, el parámetro que modifica y el nuevo valor.
`
struct tAction{
    string name;  // nombre de la acción
    string parameterName; // nombre del parámetro que cambia
    string newValue; // nuevo valor del parámetro que cambia.
};
`

# Tipo Dispositivo
Esta clase es la que se usa como base para crear los tipos de dispositivo. Tiene el nombre, una lista con las acciones que el dispositivo puede reailzar, y la lista de parámetros que se pueden modificar. La función crearParámetros se usa para añadir parámetros a la lista. La función crearAcciones se usa para añadir acciones a la lista. Finalmente, la función realizarAccion lleva a cabo una de las acciones que tiene asignadas, la que se pase como parámetro.
`
class TipoDispositivo{
    public:
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
`

# Tarea
Esta clase es la que se usa para crear tareas. Tiene un nombre, una lista con los dispositivos que afecta y la lista de las acciones que realizan los dispositivos. La función asignarDispositivos se usa para añadir dispositivos a la lista y las acciones que tienen que realizar. Para que un dispositivo haga dos cosas, se tiene que añadir dos veces. La función realizarTarea lleva a cabo todas las acciones que tiene en la lista a los dispositivos respectivos. Las acciones no se realizan en el momento de asignación, sino hasta que se llame a esta función.
`
class Tarea{ // esta es la clase de tareas.
    public:
        string name; // el nombre de la tarea
        List<TipoDispositivo> listaDispositivosTarea; // esta lista contiene todos los dipositivos que se cambian en la tarea.
        
        Tarea(string pNombre){ // constructor que cambia el nombre de la tarea.
            this -> name = pNombre;
        }

        List<tAction> accionesTarea; // esta lista contiene todas las acciones que se realizan en la tarea.
        void asignarDispositivos(string nombreDisp, string accionName){ // esta función añade los dispositivos y acciones a la tarea
            TipoDispositivo * dispositivo = dispositivos.find(nombreDisp); // se crea un puntero al dispositivo que se ingresó
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
`

# Habitación
Esta es la clase que se usa para crear una habitación. Tiene el nombre y una lista para añadirle dispositivos. La función añadir dispositivosHab añade dispositivos a la lista.
`
class Habitacion{ // esta es la clase de habitaciones
    public:
        string name; // el nombre de la habitación
        Habitacion(string nombre){ // constructor de la habitación
            this -> name = nombre;
        }
        List<TipoDispositivo> dispositivosHab; // esta lista contiene todos los dispositivos de la habitación

        void añadirDispositivos(string nombreDisp){ // esta función añade los dispositivos que pertenecen a la habitación.
            TipoDispositivo * dispositivo = dispositivos.find(nombreDisp); // crea un puntero al dispositivo

            dispositivosHab.add(dispositivo); // lo añade a la habitación
        }
};
`

# Ejecución
Este es el programa que donde se demuestra cómo el usuario añadaría los dispositivos, las habitaciones, y las tareas.
`
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
    
    Casa.add(&cuarto); // se añaden los habitaciones a la casa.
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
`

Para este ejemplo, se crearon varios tipos de dispositivos, como Bombillo, Camara, CoffeeMaker, Horno, Parlante, Sensor de Humo y Sensor de Puerta. Cada uno tiene sus respectivas acciones y parámetros. También, se crearon dos habitaciones, cuarto y cocina y se les añadieron dispositivos. Se hicieron dos tareas, Buenos días y Buenas noches. 

Buenos días apaga las luces del cuarto, prende el coffee maker para hacer café, prende el horno para hacer tostadas, enciende el Alexa para poner música, prende los sensores de humo y de puerta y apaga las cámaras del cuarto.

Buenas noches apaga todas luces, prende la luz de dormir, apaga los dispositivos de comida y entretenimiento y prende los dispositivos de seguridad.

Este es el resultado que da el programa.
`
App 4Home

Buenos días

luz fria
bombillo apagado

luz calida
bombillo prendido

night light
bombillo apagado

luz cocina
bombillo prendido

coffee maker cocina
Coffee Maker on

coffee maker cocina
Coffee Maker temperatura alta

coffee maker cocina
Coffee Maker si leche

hornito cocina
horno on

hornito cocina
horno si tostadas

Alexa
parlante on

Alexa
parlante si musica

sensor de humo cocina
sensor de humo on

sensor de puerta
sensor de puerta on

camara cuarto
camara off
`


