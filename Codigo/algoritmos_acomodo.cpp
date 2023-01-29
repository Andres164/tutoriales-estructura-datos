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

    }
}
