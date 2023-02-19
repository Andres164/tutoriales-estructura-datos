#include <iostream>
#include <exception>
#include "StackTest.h"
#include "Stack.h"

using namespace std;

const vector<int> StackTest::setDeDatos = { -20, 10, -1586, -2,147,483,648, 12, 10, -20, 789, 2,147,483,647, 0, 81, 39, -69 };

bool StackTest::test_PushPop()
{
    cout << "--------------------------- test_PushPop ---------------------------\n\n";
    Stack<int> testStack = Stack<int>();
    bool pushExitoso = true;
    try
    {
        for(int elemento : StackTest::setDeDatos)
            testStack.push(elemento);
    }
    catch( const exception& ex )
    {
        cout << "Ocurrio una Exepcion: " << ex.what() << endl;
        pushExitoso = false;
    }
    cout << "Push de elementos... " << ( pushExitoso ? "Exitoso" : "Fallido" ) << endl;
    bool popExitoso = true;
    int numElementos = 0, numElementosEnOrden = 0;
    try
    {
        vector<int>::const_reverse_iterator rit;
        for(rit = StackTest::setDeDatos.rbegin(); rit != StackTest::setDeDatos.rend(); rit++)
        {
            numElementosEnOrden += ( *rit == testStack.pop() ? 1 : 0 );
            numElementos++;
        }
    }
    catch ( const out_of_range& ex )
    {
        cout << "Ocurrio una excepcion: " << ex.what() << endl;
        popExitoso = false;
    }
    catch ( const exception& ex)
    {
        cout << "Ocurrion una excepcion inesperada: " << ex.what() << endl;
        popExitoso = false;
    }
    int numElementosEmpujados = StackTest::setDeDatos.size();
    cout << "Pop elementos... " << ( popExitoso ? "Exitoso" : "Fallido" ) << endl;
    cout << "Elementos en Stack... " << numElementos << "/" << numElementosEmpujados << endl;
    cout << "Elementos en orden... " << numElementosEnOrden << "/" << numElementosEmpujados << endl;
    cout << endl << "-----------------------------------------------------------------\n\n";
    return pushExitoso && popExitoso;
}

bool StackTest::test_Top()
{
    cout << "----------------- test_Top -----------------\n\n";
    Stack<int> testStack = Stack<int>();
    bool testExitoso = true;
    try
    {
        testStack.push(1);
        testStack.push(2);
        testExitoso = ( testStack.top() != 2 ? false : testExitoso);
        testStack.pop();
        testExitoso = ( testStack.top() != 1 ? false : testExitoso);
    }
    catch(const exception& ex)
    {
        cout << "Ocurrio una excepcion: " << ex.what() << endl;
        testExitoso = false;
    }
    cout << "test_Top... " << ( testExitoso ? "Exitoso" : "Fallido" ) << endl;
    return testExitoso;
}
