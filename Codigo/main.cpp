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
#include "algoritmosEstructurasDatos/algoritmosAcomodoTest.h"

using namespace std;

int main()
{
    //LinkedListTest::test_TodosLosMetodos();
    //cout << LinkedListTest::test_EliminarElemento() << endl;

    int longitud = 13;
    int arreglo[longitud];

    for(int i = 1; i <=5; i++)
    {
        algoritmosAcomodoTest::llenarSetDatosConValoresRandom(arreglo, longitud);
        manejoArreglos::imprimirArreglo(arreglo, longitud);
        std::cout << std::endl;
        algoritmosAcomodo::binaryInsertionSort(arreglo, longitud);
        std::cout << "Esta acomodado de menor a mayor? " << ( algoritmosAcomodoTest::estaElArregloAcomodadoMenorAMayor(arreglo, longitud) ? "SI" : "NO" ) << std::endl ;
        std::cout << std::endl;
        manejoArreglos::imprimirArreglo(arreglo, longitud);
    }

    return 0;
}
