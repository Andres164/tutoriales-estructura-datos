#include <iostream>
#include "algoritmos_acomodo.h"
#include "manejo_arreglos.h"

namespace algoritmos_acomodo
{
    void selectionSort(int arreglo[], int numElementos)
    {
        for(int i = 0; i < numElementos; i++)
        {
            int indexElementoMenor = i;
            for(int j = i+1; j < numElementos; j++)
            {
                if(arreglo[j] < arreglo[indexElementoMenor])
                    indexElementoMenor = j;
            }
            manejo_arreglos::intercambiarElementos(arreglo, i, indexElementoMenor);
        }
    }
    void insertionSort(int arreglo[], int numElementos)
    {
        for(int i = 1; i < numElementos; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                int indexPorAcomodar = j+1;
                if(arreglo[indexPorAcomodar] < arreglo[j])
                    manejo_arreglos::intercambiarElementos(arreglo, indexPorAcomodar, j);
                else
                    break;
            }
        }
    }
    void mergeSort(int arreglo[], int numElementos)
    {
        int numElementosIzquierda = 1, numElementosDerecha = 1;
        int* arregloDerecha;
        if(numElementos > 1)
        {
            numElementosIzquierda = numElementos / 2;
            arregloDerecha = arreglo+numElementosIzquierda;
            numElementosDerecha = numElementos - numElementosIzquierda;
            mergeSort(arreglo, numElementosIzquierda);
            mergeSort(arregloDerecha, numElementosDerecha);
        }
        arreglo = unirArreglosAcomodados(arreglo, numElementosIzquierda, arregloDerecha, numElementosDerecha);
    }
    int* unirArreglosAcomodados(int arreglo1[], int numElementosArr1, int arreglo2[], int numElementosArr2)
    {
        int numElementos = numElementosArr1 + numElementosArr2;
        int arregloUnido[numElementos];
        int i = 0, j = 0;
        //std::cout << "Before while" << std::endl;
        std::cout << numElementos << std::endl;
        do
        {
            //std::cout << "inside while" << std::endl;
            if(arreglo1[i] < arreglo2[j])
            {
                arregloUnido[i+j] = arreglo1[i];
                i++;
            }
            else
            {
                arregloUnido[i+j] = arreglo1[j];
                j++;
            }
        } while( i+j < (numElementosArr1 + numElementosArr2) -1 );
        //std::cout << "After while" << std::endl;
        return arregloUnido;
    }
}
