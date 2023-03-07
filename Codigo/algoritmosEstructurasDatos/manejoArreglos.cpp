#include <iostream>
#include <math.h>
#include "manejoArreglos.h"

namespace manejoArreglos
{
    void intercambiarElementos(int arreglo[], int index1, int index2)
    {
        int elemento1 = arreglo[index1];
        arreglo[index1] = arreglo[index2];
        arreglo[index2] = elemento1;
    }

    void intercambiarElementos(int* elemento1, int* elemento2)
    {
        int temp = *elemento1;
        *elemento1 = *elemento2;
        *elemento2 = temp;
    }

    void imprimirArreglo(int arreglo[], int numElementos)
    {
        for(int i = 0; i < numElementos; i++)
            std::cout << "Arreglo[" << i << "] =" << arreglo[i] << std::endl;
    }
    void copiarArreglo(int destino[], int origen[], int numElementosACopiar)
    {
        for(int i = 0; i < numElementosACopiar; i++)
            destino[i] = origen[i];
    }

    void binaryInsert(int arreglo[], int longitud, int nuevoElemento)
    {
        try
        {
            if( longitud < 1)
            {
                *(arreglo-1) = nuevoElemento;
                return;
            }
            if( longitud < 2 )
            {
                int* posicionCorrecta = ( nuevoElemento < arreglo[0] ? arreglo : arreglo +1 );
                *posicionCorrecta = nuevoElemento;
                return;
            }

            int indexAlMedio = longitud/2;
            if( nuevoElemento < arreglo[indexAlMedio] )
                binaryInsert(arreglo, longitud/2, nuevoElemento);
            else
            {
                int* subArreglo = arreglo + longitud/2 +1;
                binaryInsert(subArreglo, std::ceil( longitud/2 -1 ), nuevoElemento);
            }
        }
        catch(const std::exception& ex)
        {
            std::cout << "Ocurrio una excepcion al intentar insertar el elemento: " << ex.what() << std::endl;
        }
    }
}
