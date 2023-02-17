#include <iostream>
#include <exception>
#include "QueueTest.h"

using namespace std;

const vector<int> QueueTest::setDeDatos = { -20, 10, -1586, -2,147,483,648, 12, 10, -20, 789, 2,147,483,647, 0, 81, 39, -69 };

int QueueTest::test_Push()
{
    Queue<int> testQueue = Queue<int>();
    int codigoFinalizacion = 0;
    int count = 0;
    try
    {
        for(count = 0; count < setDeDatos.size(); count++)
            testQueue.push(setDeDatos[count]);
    }
    catch( const exception& ex )
    {
        cout << "Exepcion: " << ex.what() << endl;
        codigoFinalizacion = 1;
    }
    cout << "Elementos insertados... " << count << "/" << setDeDatos.size() << endl;
    return codigoFinalizacion;
}

int QueueTest::test_Pop()
{

}

int QueueTest::test_EstaVacia()
{

}

int QueueTest::test_Longitud()
{

}

int QueueTest::test_PrimerElemento()
{

}

int QueueTest::test_UltimoElemento()
{

}

int QueueTest::test_TodosLosMetodos()
{

}
