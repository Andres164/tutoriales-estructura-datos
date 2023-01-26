#include <iostream>

using namespace std;

void intercambiarElementos(int arreglo[], int index1, int index2)
{
    int elemento1 = arreglo[index1];
    arreglo[index1] = arreglo[index2];
    arreglo[index2] = elemento1;
}
void imprimirArreglo(int arreglo[])
{

}

int main()
{
    int n = 10;
    int arreglo[n] = {2, 4, 5, 1, 9, 10, 8, 3, 7, 6};
    for(int i = 0; i < n; i++)
    {
        int indexElementoMenor = i;
        for(int j = i+1; j < n; j++)
        {
            if(arreglo[j] < arreglo[indexElementoMenor])
                indexElementoMenor = j;
        }
        intercambiarElementos(arreglo, i, indexElementoMenor);
        cout << "Arreglo[" << i << "] =" << arreglo[i] << endl;
    }

    return 0;
}
