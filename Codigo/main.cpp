#include <iostream>
#include <memory>
#include <exception>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "BinarySearchTree.h"
#include "algoritmosEstructurasDatos/manejoEstructuraDatos.h"
#include "algoritmosEstructurasDatos/algoritmosAcomodo.h"
#include "algoritmosEstructurasDatos/manejoArreglos.h"
#include "QueueTest.h"
#include "StackTest.h"
#include "BinarySearchTreeTest.h"
#include "LinkedListTest.h"

using namespace std;

int main()
{
    //LinkedListTest::test_TodosLosMetodos();
    //cout << LinkedListTest::test_EliminarElemento() << endl;

    int arreglo[] = {1, 3, 5, 7, 2, 4};
    algoritmosAcomodo::binaryInsertionSort(arreglo, 6);
    manejoArreglos::imprimirArreglo(arreglo, 6);

    return 0;
}
