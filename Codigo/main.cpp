#include <iostream>
#include "LinkedList.h"
#include "algoritmosEstructurasDatos/manejoEstructuraDatos.h"

using namespace std;

int main()
{
    LinkedList myList;
    cout << endl;

    myList.push_back(4);
    myList.push_back(2);
    myList.push_back(1);
    myList.push_back(10);
    cout << endl;
    cout << "Eliminando elemento" << endl;
    myList.eliminarElemento(4);
    manejoEstructuraDatos::imprimirLinkedList(myList);



    return 0;
}
