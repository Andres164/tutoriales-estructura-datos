#include <iostream>
#include "algoritmos_acomodo.h"
#include "manejo_arreglos.h"

using namespace std;

int main()
{
    int n = 10;
    int arreglo1[n/2] = {2, 5, 7, 9, 10};
    int arreglo2[n/2] = {1, 3, 4, 6, 8};
    int* arreglo;
//    int arreglo[n] = {2, 4, 5, 1, 9, 10, 8, 3, 7, 6};
    //algoritmos_acomodo::mergeSort(arreglo, n);
    arreglo = algoritmos_acomodo::unirArreglosAcomodados(arreglo1, n/2, arreglo2, n/2);
    manejo_arreglos::imprimirArreglo(arreglo, n);
    return 0;
}
