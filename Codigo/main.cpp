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
    myList.eliminarElemento(2);
    manejoEstructuraDatos::imprimirLinkedList(myList);
    cout <<  myList.Longitud() << endl;



    return 0;
}
