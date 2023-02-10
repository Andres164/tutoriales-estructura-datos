#include <iostream>
#include <memory>
#include <exception>
#include "LinkedList.h"
#include "Stack.h"
#include "BinarySearchTree.h"
#include "algoritmosEstructurasDatos/manejoEstructuraDatos.h"

using namespace std;

int main()
{
    BinarySearchTree bst = BinarySearchTree();
    bst.agregarElemento(5);
    bst.agregarElemento(2);
    bst.agregarElemento(1);
    bst.agregarElemento(3);
    bst.agregarElemento(8);
    bst.agregarElemento(9);
    bst.eliminarElemento(2);
    bst.imprimirInOrder();
    cout << "El elemento 8 existe? " << ( bst.existeElemento(8) ? "Si" : "No" ) << endl;
    cout << "El elemento existe? " << ( bst.existeElemento(0) ? "Si" : "No" ) << endl;
    cout << "Numero de nodos: " << bst.getNumNodos() << endl;


    /*
    Stack pila = Stack();
    pila.push(9);
    pila.push(3);
    pila.push(1);
    cout << pila.pop() << endl;
    pila.push(-1);
    cout << "L:" << pila.Longitud() << endl;
    //manejoEstructuraDatos::vaciarStack(&pila);
    cout << "L:" << pila.Longitud() << endl;

    try
    {
        pila.top();
    } catch(out_of_range const& ex) { cout << ex.what() << endl; }*/

    return 0;
}
