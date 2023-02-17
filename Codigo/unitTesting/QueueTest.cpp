#include <iostream>
#include <exception>
#include "QueueTest.h"

using namespace std;

const vector<int> QueueTest::setDeDatos = { -20, 10, -1586, -2,147,483,648, 12, 10, -20, 789, 2,147,483,647, 0, 81, 39, -69 };

int QueueTest::test_Push()
{
    cout << "--------------------------- test_Push ---------------------------\n\n";
    Queue<int> testQueue = Queue<int>();
    int codigoFinalizacion = 0;
    int count = 0;
    try
    {
        for(count = 0; count < QueueTest::setDeDatos.size(); count++)
            testQueue.push(QueueTest::setDeDatos[count]);
    }
    catch( const exception& ex )
    {
        cout << "Ocurrio una Exepcion: " << ex.what() << endl;
        codigoFinalizacion = 1;
    }
    cout << "Elementos insertados... " << count << "/" << QueueTest::setDeDatos.size() << endl;

    count = 0;
    try
    {
        for(int i : QueueTest::setDeDatos)
            count += i == testQueue.pop() ? 1 : 0;
    }
    catch ( const exception& ex)
    {
        cout << "Ocurrion una Exepcion: " << ex.what() << endl;
        codigoFinalizacion = 2;
    }
    cout << "Elementos en orden... " << count << "/" << QueueTest::setDeDatos.size() << endl;
    codigoFinalizacion = count != QueueTest::setDeDatos.size() ? 3 : codigoFinalizacion;
    cout << endl << "-----------------------------------------------------------------\n\n";
    return codigoFinalizacion;
}

int QueueTest::test_Pop()
{

}

int QueueTest::test_EstaVacia()
{
    int codigoTerminacion = 0;
    cout << "----------------------- test_EstaVacia -----------------------\n\n";
    try
    {
        Queue<int> testQueue = Queue<int>();
        codigoTerminacion = !testQueue.estaVacia() ? 2 : codigoTerminacion;
        testQueue.push(1);
        codigoTerminacion = testQueue.estaVacia() ? 1 : codigoTerminacion;
        testQueue.pop();
        codigoTerminacion = !testQueue.estaVacia() ? 2 : codigoTerminacion;
    }
    catch ( const exception& ex )
    {
        cout << "Ocurrio una excepcion: " << ex.what() << endl;
        codigoTerminacion = 3;
    }

    cout << "test_EstaVacia... " << ( codigoTerminacion == 0 ? "Exitoso" : "Fallido" ) << endl;
    cout << endl << "-----------------------------------------------------------------\n\n";
    return codigoTerminacion;
}

int QueueTest::test_Longitud()
{
    int codigoTerminacion = 0;
    cout << "----------------------- test_Longitud ------------------------\n\n";
    try
    {
        Queue<int> testQueue = Queue<int>();
        codigoTerminacion = testQueue.Longitud() != 0 ? 2 : codigoTerminacion;
        testQueue.push(1);
        codigoTerminacion = testQueue.Longitud() <= 0 ? 1 : codigoTerminacion;
        testQueue.pop();
        codigoTerminacion = testQueue.Longitud() != 0 ? 2 : codigoTerminacion;
    }
    catch ( const exception& ex )
    {
        cout << "Ocurrio una excepcion: " << ex.what() << endl;
        codigoTerminacion = 3;
    }
    cout << "test_Longitud... " << ( codigoTerminacion == 0 ? "Exitoso" : "Fallido" ) << endl;
    cout << endl << "-----------------------------------------------------------------\n\n";
    return codigoTerminacion;
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
