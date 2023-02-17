#include <iostream>
#include <memory>
#include <exception>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "BinarySearchTree.h"
#include "algoritmosEstructurasDatos/manejoEstructuraDatos.h"
#include "QueueTest.h"

using namespace std;

int main()
{
    int testResult = QueueTest::test_Longitud();
    cout << endl << "Codigo de terminacion: " << testResult << endl;

    /*
    BinarySearchTree bst = BinarySearchTree();
    bst.agregarElemento(5);
    bst.agregarElemento(1);
    bst.agregarElemento(0);
    bst.agregarElemento(3);
    bst.agregarElemento(8);
    bst.agregarElemento(9);
    bst.agregarElemento(4);
    bst.agregarElemento(6);
    bst.agregarElemento(7);
    cout << "El arbol esta balanceado? " << (bst.estaBalanceado() ? "Si" : "No") << endl;
    cout << "El arbol es perfecto? " << (bst.esPerfecto() ? "Si" : "No") << endl;
    cout << "El arbol esta lleno? " << (bst.estaLleno() ? "Si" : "No") << endl;
    cout << "altura del arbol: " << bst.altura() << endl;
    cout << "El elemento 8 existe? " << ( bst.existeElemento(8) ? "Si" : "No" ) << endl;
    cout << "El elemento 0 existe? " << ( bst.existeElemento(0) ? "Si" : "No" ) << endl;
    cout << "Numero de nodos: " << bst.getNumNodos() << endl;
    */
    /*
    Queue<string> myQueue = Queue<string>();
    myQueue.push("Jose");
    myQueue.push("Manuel");
    myQueue.push("Chuy");
    myQueue.push("Crhis");

    cout << "Elementos en cola: " << myQueue.Longitud() << endl;
    cout << "Primer elemento en la cola: " << myQueue.primerElemento() << endl;
    cout << "Ultimo elemento en la cola: " << myQueue.ultimoElemento() << endl;
    manejoEstructuraDatos::vaciarQueue(myQueue);
    cout << endl << "Elementos en cola: " << myQueue.Longitud() << endl;
    */


    return 0;
}
