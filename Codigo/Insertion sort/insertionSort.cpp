#include <iostream>

using namespace std;

void intercambiarElementos(int arreglo[], int index1, int index2)
{
    int elemento1 = arreglo[index1];
    arreglo[index1] = arreglo[index2];
    arreglo[index2] = elemento1;
}
void imprimirArreglo(int arreglo[], int numElementos)
{
    for(int i = 0; i < numElementos; i++)
        cout << "Arreglo[" << i << "] =" << arreglo[i] << endl;
}
void selectionSort(int arreglo[], numElementos)
{
    for(int i = 1; i < numElementos; i++)
    {
        for(int j = i-1; j >= 0; j--)
        {
            if(arreglo[i] < arreglo[j])
            {
                intercambiarElementos(arreglo, i, j);
            }
            else
                break;
        }
    }
}

int main ()
{


    return 0;
}
