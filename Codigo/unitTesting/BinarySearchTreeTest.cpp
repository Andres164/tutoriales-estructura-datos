#include "BinarySearchTreeTest.h"
#include <iostream>
#include <exception>

using namespace std;

const vector<int> BinarySearchTreeTest::setDeDatos = { 5, 1, 8, 0, 9 };

bool BinarySearchTreeTest::test_ExisteElemento()
{
    cout << "--------------------------- test_ExisteElemento ---------------------------\n\n";
    using BST_Test = BinarySearchTreeTest;
    bool testExitoso = true;
    BinarySearchTree testBST = BinarySearchTree();
    try
    {
        for(int elemento : BST_Test::setDeDatos)
            testBST.agregarElemento(elemento);
    }
    catch(const exception& ex)
    {
        cout << "Ocurrio una excepcion al intentar insertar los elementos: " << ex.what() << endl;
    }
    int numElementosEncontrados = 0, numFalsosPositivos = 0;
    try
    {
        for(int elemento : BST_Test::setDeDatos)
        {
            numElementosEncontrados += testBST.existeElemento(elemento);
            numFalsosPositivos += testBST.existeElemento(elemento-100);
        }
    }
    catch(const exception& ex)
    {
        cout << "Ocurrio una excepcion al intentar buscar los elementos insertados en el BST" << ex.what() << endl;
        testExitoso = false;
    }
    cout << "Elementos encontrados... " << numElementosEncontrados << "/" << BST_Test::setDeDatos.size() << endl;
    cout << "Falsos positivos... " << numFalsosPositivos << endl;
    if(numElementosEncontrados != BST_Test::setDeDatos.size() || numFalsosPositivos > 0)
        testExitoso = false;
    cout << "test_ExisteElemento... " << ( testExitoso ?  "Exitoso" : "Fallido" ) << endl;
    return testExitoso;
}

bool BinarySearchTreeTest::test_EliminarElemento()
{
    bool testExitoso = true;

    return testExitoso;
}

bool BinarySearchTreeTest::test_EstaBalanceado()
{
    bool testExitoso = true;

    return testExitoso;
}

bool BinarySearchTreeTest::test_EstaLleno()
{
    bool testExitoso = true;

    return testExitoso;
}

bool BinarySearchTreeTest::test_EsPerfecto()
{
    bool testExitoso = true;

    return testExitoso;
}

bool BinarySearchTreeTest::test_Altura()
{
    bool testExitoso = true;

    return testExitoso;
}

bool BinarySearchTreeTest::test_GetNumNodos()
{
    using BST_Test = BinarySearchTreeTest;
    bool testExitoso = true;
    int i;
    BinarySearchTree testBST = BinarySearchTree();
    try
    {
        for(i = 0; i < BST_Test::setDeDatos.size()/2; i++)
            testBST.agregarElemento(BST_Test::setDeDatos[i]);
    }
    catch(const exception& ex)
    {
        cout << "Ocurrio una excepcion al intentar insertar los elementos: " << ex.what() << endl;
        testExitoso = false;
    }
    testExitoso = testBST.getNumNodos() != BST_Test::setDeDatos.size()/2 ? false : testExitoso;
    try
    {
        for(; i < BST_Test::setDeDatos.size(); i++)
            testBST.agregarElemento(BST_Test::setDeDatos[i]);
    }
    catch(const exception& ex)
    {
        cout << "Ocurrio una excepcion al intentar insertar los elementos: " << ex.what() << endl;
        testExitoso = false;
    }
    testExitoso = testBST.getNumNodos() != BST_Test::setDeDatos.size() ? false : testExitoso;
    cout << "testGetNumNodos... " << ( testExitoso ? "Exitoso" : "Fallido" ) << endl;
    return testExitoso;
}

bool BinarySearchTreeTest::test_EstaVacio()
{
    bool testExitoso = true;
    BinarySearchTree testBST = BinarySearchTree();
    try
    {
        testExitoso = testBST.estaVacio();
        testBST.agregarElemento(4);
        testExitoso = testBST.estaVacio() ? false : testExitoso;
    }
    catch(const exception& ex)
    {
        cout << "Ocurrio una excepcion: " << ex.what() << endl;
        testExitoso = false;
    }
    cout << "test_EstaVacio... " << ( testExitoso ? "Exitoso" : "Fallido" ) << endl;
    return testExitoso;
}
