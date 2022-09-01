#include "List.h"
#include <string>
#include <iostream>
#include "eventos/event.h"

using namespace std;

int main() {
    // 3. Despues del cambio esto debería comportarse exactamente igual que el caso de lista simple
    // 4. Crear esta implementación de lista doblemente enlazada corresponde al quiz #4 y #5
    // 5. Entregar a mas tardar el viernes a las 7am, enviandolo al asistente kevinqj.2002@gmail.com 
    // 6. subject: estructuras - quiz #4#5
    // 7. el quiz se hará en parejas asignado por el profesor

    List<Event>* listA = new List<Event>();
    List<string>* listB = new List<string>();

    Event *unEvento = new Event("Concierto Coldplay", "ITCR", "ASODEC");
    Event *otroEvento = new Event("Charla de Bill Gates", "ITCR", "ASODEC");
    Event *otroEvento2 = new Event("Evento del final", "ITCR", "ASODEC");

    listA->insert(0, otroEvento2);
    listA->insert(0, otroEvento);
    listA->add(unEvento);

    string prueba1 = "Un mensaje de prueba";
    string prueba2 = "segundo mensaje de prueba";
    string prueba3 = "tercer mensaje de prueba";
    string prueba4 = "cuarto mensaje de prueba";
    string prueba5 = "quinto mensaje de prueba";

    listB->insert(0, &prueba1);
    listB->insert(1, &prueba2);
    listB->add(&prueba4);
    listB->insert(2,&prueba3);
    listB->add(&prueba5);

  //  listB->remove(0);
  //  listB->remove(3);
  //  listB->remove(1);

    for(int i=0; i<listA->getSize(); i++) {
        Event *currentEvent = listA->find(i);
        cout << currentEvent->getTitle() << endl;
    }

    cout << "==================================" << endl;
    for(int i=0; i<listB->getSize(); i++) {
        string *currentmsg = listB->find(i);
        cout << *currentmsg << endl;
    }
    listB->printList();

}