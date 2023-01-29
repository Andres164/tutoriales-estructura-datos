#include <iostream>
#include "algoritmos_acomodo.h"
#include "manejo_arreglos.h"

using namespace std;

int main()
{
    int n = 10;
    int arreglo[n] = {2, 4, 5, 1, 9, 10, 8, 3, 7, 6};
    algoritmos_acomodo::insertionSort(arreglo, n);
    manejo_arreglos::imprimirArreglo(arreglo, n);
    return 0;
}
