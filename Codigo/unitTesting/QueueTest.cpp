#include <iostream>
#include <exception>
#include "QueueTest.h"

using namespace std;

const vector<int> QueueTest::setDeDatos = { -20, 10, -1586, -2,147,483,648, 12, 10, -20, 789, 2,147,483,647, 0, 81, 39, -69 };

int QueueTest::test_PushPop()
{
    cout << "--------------------------- test_Push ---------------------------\n\n";
    Queue<int> testQueue = Queue<int>();
    int codigoFinalizacion = 0;
    try
    {
        for(int elemento : QueueTest::setDeDatos)
            testQueue.push(elemento);
    }
    catch( const exception& ex )
    {
        cout << "Ocurrio una Exepcion: " << ex.what() << endl;
        codigoFinalizacion = 1;
    }
    cout << "Push de elementos... " << ( codigoFinalizacion != 1 ? "Exitoso" : "Fallido" ) << endl;
    int numElementos = 0, numElementosEnOrden = 0;
    try
    {
        for(int elemento : QueueTest::setDeDatos)
        {
            numElementosEnOrden += ( elemento == testQueue.pop() ? 1 : 0 );
            numElementos++;
        }
    }
    catch ( const out_of_range& ex )
    {
        cout << "Ocurrio una excepcion: " << ex.what() << endl;
        codigoFinalizacion = 2;
    }
    catch ( const exception& ex)
    {
        cout << "Ocurrion una excepcion inesperada: " << ex.what() << endl;
        codigoFinalizacion = 3;
    }
    int numElementosEmpujados = QueueTest::setDeDatos.size();
    cout << "Pop elementos... " << ( codigoFinalizacion < 2 ? "Exitoso" : "Fallido" ) << endl;
    cout << "Elementos en queue... " << numElementos << "/" << numElementosEmpujados << endl;
    cout << "Elementos en orden... " << numElementosEnOrden << "/" << numElementosEmpujados << endl;
    cout << endl << "-----------------------------------------------------------------\n\n";
    codigoFinalizacion = numElementosEnOrden != numElementosEmpujados ? 4 : codigoFinalizacion;
    return codigoFinalizacion;
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
    int codigoTerminacion = 0;
    cout << "--------------------- test_PrimerElemento ---------------------\n\n";
    try
    {
        Queue<int> testQueue = Queue<int>();
        testQueue.push(1);
        codigoTerminacion = testQueue.primerElemento() != 1 ? 1 : codigoTerminacion;
        testQueue.pop();
        testQueue.push(2);
        testQueue.push(1);
        codigoTerminacion = testQueue.primerElemento() != 2 ? 2 : codigoTerminacion;
    }
    catch(const exception& ex)
    {
        cout << "Ocurrio una excepcion: " << ex.what() << endl;
        codigoTerminacion = 3;
    }
    cout << "test_PrimerElemento... " << ( codigoTerminacion == 0 ? "Exitoso" : "Fallido" ) << endl;
    cout << endl << "-----------------------------------------------------------------\n\n";
    return codigoTerminacion;
}

int QueueTest::test_UltimoElemento()
{
    int codigoTerminacion = 0;
    cout << "--------------------- test_UltimoElemento ---------------------\n\n";
    try
    {
        Queue<int> testQueue = Queue<int>();
        testQueue.push(1);
        testQueue.push(2);
        codigoTerminacion = testQueue.ultimoElemento() != 2 ? 1 : codigoTerminacion;
        testQueue.pop();
        testQueue.push(1);
        codigoTerminacion = testQueue.ultimoElemento() != 1 ? 2 : codigoTerminacion;
    }
    catch(const exception& ex)
    {
        cout << "Ocurrio una excepcion: " << ex.what() << endl;
        codigoTerminacion = 3;
    }
    cout << "test_UltimoElemento... " << ( codigoTerminacion == 0 ? "Exitoso" : "Fallido" ) << endl;
    cout << endl << "-----------------------------------------------------------------\n\n";
    return codigoTerminacion;
}

void QueueTest::test_TodosLosMetodos()
{
    QueueTest::test_PushPop();
    QueueTest::test_EstaVacia();
    QueueTest::test_Longitud();
    QueueTest::test_PrimerElemento();
    QueueTest::test_UltimoElemento();
}
