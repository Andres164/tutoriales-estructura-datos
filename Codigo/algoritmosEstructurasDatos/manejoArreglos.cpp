#include <iostream>
#include "manejoArreglos.h"

namespace manejoArreglos
{
    void intercambiarElementos(int arreglo[], int index1, int index2)
    {
        int elemento1 = arreglo[index1];
        arreglo[index1] = arreglo[index2];
        arreglo[index2] = elemento1;
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
}
