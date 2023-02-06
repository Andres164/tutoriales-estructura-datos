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
    pila.push(-1);
    cout << "L:" << pila.Longitud() << endl;
    manejoEstructuraDatos::vaciarStack( make_shared<Stack>( pila ) );
    cout << "L:" << pila.Longitud() << endl;
    /*
    try
    {
        pila.top();
    } catch(out_of_range const& ex) { cout << ex.what() << endl; }*/

    return 0;
}
