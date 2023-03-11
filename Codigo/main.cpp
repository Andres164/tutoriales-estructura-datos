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
    // LinkedListTest::test_TodosLosMetodos();
    //cout << LinkedListTest::test_EliminarElemento() << endl;
/*
    int longitud = 6;
    int arreglo[longitud] = { 153, 974, 1243, 1291, 1665, 1773 };
    std::cout << "&arreglo = ";
    for(int* i = &arreglo[0]; i < &arreglo[longitud]; i++)
        std::cout << i << ", ";
    std::cout << std::endl << "'posicionCorrecta': " << algoritmosAcomodo::ptr_posicionCorrecta(arreglo, longitud -1, arreglo[5]) << std::endl;
    std::cout << " posicionCorrecta : " << &arreglo[5] << std::endl;
    /*
    */
    int longitud = 6;
    int arreglo[longitud] = { 974, 153, 1243, 1665, 1291, 1773 };
    algoritmosAcomodo::binaryInsertionSort(arreglo, longitud);
    manejoArreglos::imprimirArreglo(arreglo, longitud);


/*
    for(int i = 1; i <=5; i++)
    {
        std::cout << std::endl;
        std::cout << "----------------------- Array No. " << i << " ----------------------- " << std::endl;
        algoritmosAcomodoTest::llenarSetDatosConValoresRandom(arreglo, longitud);
        std::cout << std::endl;
        manejoArreglos::imprimirArreglo(arreglo, longitud);
        algoritmosAcomodo::binaryInsertionSort(arreglo, longitud);
        std::cout << "Esta acomodado de menor a mayor? " << ( algoritmosAcomodoTest::estaElArregloAcomodadoMenorAMayor(arreglo, longitud) ? "SI" : "NO" ) << std::endl ;
        std::cout << std::endl;
        manejoArreglos::imprimirArreglo(arreglo, longitud);
    }
*/

    return 0;
}
