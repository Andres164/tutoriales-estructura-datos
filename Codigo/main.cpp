#include <iostream>
#include "algoritmos_acomodo.h"
#include "manejo_arreglos.h"

using namespace std;

int main()
{
    int n = 10;

    /*
    int* arreglo;
    int* arreglo1;
    int* arreglo2;
    arreglo1 = algoritmos_acomodo::unirArreglosAcomodados(new int(2), 1, new int(4), 1);
    arreglo2 = algoritmos_acomodo::unirArreglosAcomodados(new int(5), 1, new int(1), 1);
    arreglo = algoritmos_acomodo::unirArreglosAcomodados(arreglo1, 2, arreglo2, 2);
    */
    int arreglo[n] = {2, 12, 52, 12, 900, 10, 8, 3, 1, 7};
    algoritmos_acomodo::mergeSort(arreglo, n);
    manejo_arreglos::imprimirArreglo(arreglo, n);
    return 0;
}
