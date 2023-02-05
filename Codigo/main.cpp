#include <iostream>
#include "LinkedList.h"
#include "algoritmosEstructurasDatos/manejoEstructuraDatos.h"

using namespace std;

int main()
{
    LinkedList myList;
    cout << endl;

    myList.push_front(45);
    myList.push_back(4);
    myList.push_back(2);
    myList.push_back(1);
    myList.push_front(65);
    myList.push_back(10);
    myList.insertarElemento(4, 98);
    cout << endl;

    manejoEstructuraDatos::imprimirLinkedList(myList);
    cout << endl;

    myList.vaciar();
    manejoEstructuraDatos::imprimirLinkedList(myList);
    cout <<  myList.Longitud() << endl;
    cout << endl;

    myList.push_front(65);
    manejoEstructuraDatos::imprimirLinkedList(myList);



    return 0;
}
