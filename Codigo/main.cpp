#include <iostream>
#include <memory>
#include <exception>
#include "LinkedList.h"
#include "Stack.h"
#include "algoritmosEstructurasDatos/manejoEstructuraDatos.h"

using namespace std;

int main()
{
    Stack pila = Stack();
    pila.push(9);
    pila.push(3);
    pila.push(1);
    cout << pila.pop() << endl;
    pila.push(-1);
    cout << "L:" << pila.Longitud() << endl;
    while(!pila.estaVacia())
        cout << pila.pop() << endl;
    cout << "L:" << pila.Longitud() << endl;
    /*
    try
    {
        pila.top();
    } catch(out_of_range const& ex) { cout << ex.what() << endl; }*/

    return 0;
}
