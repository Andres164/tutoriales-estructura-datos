#include <iostream>
#include "LinkedList.h"
#include "Queue.h"
#include "algoritmosEstructurasDatos/manejoEstructuraDatos.h"

using namespace std;

int main()
{
    Queue que = Queue();
    cout << "Esta Vacia: " << (que.estaVacia() ? "Si" : "No") << endl;
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(6);
    que.push(7);
    int elemento = que.pop();
    cout << "Elemento: " << elemento << endl;
    que.imprimirElementos();
    cout << "Longitud: " << que.Longitud() << endl;
    cout << endl << "Primer elemento: " << que.primerElemento() << endl;
    cout << "Ultimo elemento: " << que.ultimoElemento() << endl;


    return 0;
}
