#include <iostream>
#include <math.h>
#include "algoritmosAcomodo.h"
#include "manejoArreglos.h"

namespace algoritmosAcomodo
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
            manejoArreglos::intercambiarElementos(arreglo, i, indexElementoMenor);
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
                    manejoArreglos::intercambiarElementos(arreglo, indexPorAcomodar, j);
                else
                    break;
            }
        }
    }
    void mergeSort(int arreglo[], int numElementos)
    {
        int numElementosIzquierda = 1, numElementosDerecha = 1;
        int* arregloDerecha = arreglo+1;
        if(numElementos > 2)
        {
            numElementosIzquierda = numElementos / 2;
            arregloDerecha = arreglo+numElementosIzquierda;
            numElementosDerecha = numElementos - numElementosIzquierda;
            mergeSort(arreglo, numElementosIzquierda);
            mergeSort(arregloDerecha, numElementosDerecha);
        }
        if (numElementos > 1)
        {
            int* arregloUnido = unirArreglosAcomodados(arreglo, numElementosIzquierda, arregloDerecha, numElementosDerecha);
            manejoArreglos::copiarArreglo(arreglo, arregloUnido, numElementos);
        }

    }
    int* unirArreglosAcomodados(int arreglo1[], int numElementosArr1, int arreglo2[], int numElementosArr2)
    {
        int numElementos = numElementosArr1 + numElementosArr2;
        int* arregloUnido = new int[numElementos];
        int i = 0, j = 0;
        do
        {
            if(arreglo1[i] < arreglo2[j])
            {
                arregloUnido[i+j] = arreglo1[i];
                i++;
            }
            else
            {
                arregloUnido[i+j] = arreglo2[j];
                j++;
            }
        } while( i < numElementosArr1 && j < numElementosArr2);
        for( ; i < numElementosArr1; i++)
            arregloUnido[i+j] = arreglo1[i];
        for( ; j < numElementosArr2; j++)
            arregloUnido[i+j] = arreglo2[j];
        return arregloUnido;
    }
    void quickSort(int arreglo[], int longitud)
    {
        if(longitud < 2)
            return;
        manejoArreglos::intercambiarElementos(arreglo, longitud/2, longitud-1);
        int* pivote = arreglo + (longitud-1),
             *elementoIzquierdo = arreglo,
             *elementoDerecho = pivote-1;
        while( elementoIzquierdo < elementoDerecho)
        {
            if(*elementoIzquierdo <= *pivote)
                elementoIzquierdo++;
            if(*elementoDerecho >= *pivote)
                elementoDerecho--;
            if( *elementoIzquierdo > *pivote && *elementoDerecho < *pivote )
                manejoArreglos::intercambiarElementos(elementoIzquierdo, elementoDerecho);
        }
        if( *elementoIzquierdo > *pivote )
            manejoArreglos::intercambiarElementos(elementoIzquierdo, pivote);
        int* subArregloIzquierdo = &arreglo[0],
             *subArregloDerecho = elementoIzquierdo+1;
        quickSort( subArregloIzquierdo, longitud/2 );
        quickSort( subArregloDerecho, ceil(longitud/2) -1 );
    }
}
