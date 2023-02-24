#include "BinarySearchTreeTest.h"
#include <iostream>
#include <exception>
#include <stdexcept>
#include "Queue.h"

using namespace std;
using BST_test = BinarySearchTreeTest;

const vector<int> BinarySearchTreeTest::setDeDatos = { 5, 1, 8, 0, 9 };

bool BinarySearchTreeTest::test_AgregarElemento()
{
    cout << "--------------------------- test_AgregarElemento ---------------------------\n\n";
    bool testExitoso = true;
    BinarySearchTree testBST = BinarySearchTree();
    testExitoso = BST_test::rellenarBST(testBST, BST_test::setDeDatos) == 0 ? true : false;
    if(!BST_test::contienenLosMismosElementos(testBST, BST_test::setDeDatos))
    {
        cout << "El Binary Search Tree no contiene todos los elementos que fueron insertados" << endl;
        testExitoso = false;
    }
    cout << "test_AgregarElemento... " << ( testExitoso ? "Exitoso" : "Fallido" ) << "\n\n\n";
    return testExitoso;
}

bool BinarySearchTreeTest::test_ExisteElemento()
{
    cout << "--------------------------- test_ExisteElemento ---------------------------\n\n";
    bool testExitoso = true;
    BinarySearchTree testBST = BinarySearchTree();
    vector<int> setDatos = BST_test::setDeDatos;
    BST_test::rellenarBST(testBST, setDatos);
    unsigned int numElementosEncontrados = 0, numFalsosPositivos = 0;
    try
    {
        for(int elemento : BST_test::setDeDatos)
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
    cout << "Elementos encontrados... " << numElementosEncontrados << "/" << BST_test::setDeDatos.size() << endl;
    cout << "Falsos positivos... " << numFalsosPositivos << endl;
    if(numElementosEncontrados != BST_test::setDeDatos.size() || numFalsosPositivos > 0)
        testExitoso = false;
    cout << "test_ExisteElemento... " << ( testExitoso ?  "Exitoso" : "Fallido" ) << "\n\n\n";
    return testExitoso;
}

bool BinarySearchTreeTest::test_EliminarElemento()
{
    cout << "--------------------------- test_EliminarElemento ---------------------------\n\n";
    vector<int> setDeDatosEliminar = { 10, 5, 2, 4, 3, 8, 6, 7, 15, 12, 11, 13, 18, 16, 17, 19 };
    BinarySearchTree testBST = BinarySearchTree();
    bool testExitoso = true;
    int numElementosPorEliminar;
    int numElementosQueSiSeEliminaron = 0;
    Queue<int> elementosPorEliminar = Queue<int>();
    elementosPorEliminar.push(13);
    elementosPorEliminar.push(11);
    elementosPorEliminar.push(15);
    elementosPorEliminar.push(17);
    elementosPorEliminar.push(16);
    elementosPorEliminar.push(8);
    elementosPorEliminar.push(2);
    numElementosPorEliminar = elementosPorEliminar.Longitud();

    if(rellenarBST(testBST, setDeDatosEliminar) == 1)
        return false;
    while(!elementosPorEliminar.estaVacia())
    {
        int elemento = elementosPorEliminar.pop();
        eliminarElementoEnAmbos(testBST, setDeDatosEliminar, elemento);
        testExitoso = ( !contienenLosMismosElementos(testBST, setDeDatosEliminar) ? false : testExitoso );
        try
        {
            numElementosQueSiSeEliminaron += !testBST.existeElemento(elemento);
        }
        catch(const exception& ex)
        {
            cout << "Ocurrio una excepcion al intentar buscar un elemento eliminado: " << ex.what() << endl;
            testExitoso = false;
        }
    }
    cout << "Elementos eliminados... " << numElementosQueSiSeEliminaron << "/" << numElementosPorEliminar << endl;
    if(!testExitoso)
        cout << "test_EliminarElemento... Fallido: el BST no contiene los elementos que deberia tener" << "\n\n\n";
    else
        cout << "test_EliminarElemento... Exitoso" << "\n\n\n";
    return testExitoso;
}

bool BinarySearchTreeTest::test_EstaBalanceado()
{
    cout << "--------------------------- test_EstaBalanceado ---------------------------\n\n";
    bool testExitoso = true;
    vector<int> elementosDeArbolBalanceado = { 5, 1, 0, 3, 4, 8, 6, 7, 9};
    vector<int> elementosDeArbolInBalanceado = { 5, 1, 8, 6, 7, 9 };
    BinarySearchTree arbolBalanceado = BinarySearchTree();
    BinarySearchTree arbolInBalanceado = BinarySearchTree();
    BST_test::rellenarBST(arbolBalanceado, elementosDeArbolBalanceado);
    BST_test::rellenarBST(arbolInBalanceado, elementosDeArbolInBalanceado);
    testExitoso = arbolBalanceado.estaBalanceado();
    testExitoso = ( arbolInBalanceado.estaBalanceado() ? false : testExitoso );
    cout << "test_EstaBalanceado... " << ( testExitoso ? "Exitoso" : "Fallido" ) << "\n\n\n";

    return testExitoso;
}

bool BinarySearchTreeTest::test_EstaLleno()
{
    cout << "--------------------------- test_EstaLleno ---------------------------\n\n";
    vector<int> elementosArbolLleno = { 12, 5, 15, 2, 8 };
    BinarySearchTree testBST = BinarySearchTree();
    BST_test::rellenarBST(testBST, elementosArbolLleno);
    bool testExitoso = testBST.estaLleno();

    testBST.agregarElemento(6);
    testExitoso = testBST.estaLleno() ? false : testExitoso;
    testBST.agregarElemento(10);
    testExitoso = !testBST.estaLleno() ? false : testExitoso;

    cout << "test_EstaLleno... " << ( testExitoso ? "Exitoso" : "Fallido" ) << "\n\n\n";
    return testExitoso;
}

bool BinarySearchTreeTest::test_EsPerfecto()
{
    cout << "--------------------------- test_EsPerfecto ---------------------------\n\n";
    bool testExitoso = true;
    vector<int> elementosArbolPerfecto = {10, 5, 3, 7, 15, 12, 18};
    BinarySearchTree testBST = BinarySearchTree();
    BST_test::rellenarBST(testBST, elementosArbolPerfecto);
    try
    {
        testExitoso = testBST.esPerfecto();
        testBST.eliminarElemento(7);
        testExitoso = testBST.esPerfecto() ? false : testExitoso;
    }
    catch(const exception& ex)
    {
        cout << "Ocurrio una excepcion inesperada: " << ex.what() << endl;
        testExitoso = false;
    }
    cout << "test_EsPerfecto... " << ( testExitoso ? "Exitoso" : "Fallido" ) << "\n\n\n";
    return testExitoso;
}

bool BinarySearchTreeTest::test_Altura()
{
    cout << "--------------------------- test_Altura ---------------------------\n\n";
    bool testExitoso = true;
    BinarySearchTree bst = BinarySearchTree();
    vector<int> setDatos = BST_test::setDeDatos;
    BST_test::rellenarBST(bst, setDatos);
    testExitoso = ( bst.altura() == 2 ? true : false );
    bst.agregarElemento(-1);
    testExitoso = ( bst.altura() != 3 ? false : testExitoso);
    bst.eliminarElemento(9);
    testExitoso = ( bst.altura() != 3 ? false : testExitoso);
    bst.eliminarElemento(-1);
    testExitoso = ( bst.altura() != 2 ? false : testExitoso);
    cout << "test_Altura... " << ( testExitoso ? "Exitoso" : "Fallido" ) << "\n\n\n";
    return testExitoso;
}

bool BinarySearchTreeTest::test_GetNumNodos()
{
    cout << "--------------------------- test_GetNumNodos ---------------------------\n\n";
    BinarySearchTree testBST = BinarySearchTree();
    bool testExitoso = true;
    unsigned int i = 0;
    try
    {
        for(; i < BST_test::setDeDatos.size()/2; i++)
            testBST.agregarElemento(BST_test::setDeDatos[i]);
    }
    catch(const exception& ex)
    {
        cout << "Ocurrio una excepcion al intentar insertar los elementos: " << ex.what() << endl;
        testExitoso = false;
    }
    testExitoso = testBST.getNumNodos() != BST_test::setDeDatos.size()/2 ? false : testExitoso;
    try
    {
        for(; i < BST_test::setDeDatos.size(); i++)
            testBST.agregarElemento(BST_test::setDeDatos[i]);
    }
    catch(const exception& ex)
    {
        cout << "Ocurrio una excepcion al intentar insertar los elementos: " << ex.what() << endl;
        testExitoso = false;
    }
    testExitoso = testBST.getNumNodos() != BST_test::setDeDatos.size() ? false : testExitoso;
    cout << "testGetNumNodos... " << ( testExitoso ? "Exitoso" : "Fallido" ) << "\n\n\n";
    return testExitoso;
}

bool BinarySearchTreeTest::test_EstaVacio()
{
    cout << "--------------------------- test_EstaVacio ---------------------------\n\n";
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
    cout << "test_EstaVacio... " << ( testExitoso ? "Exitoso" : "Fallido" ) << "\n\n\n";
    return testExitoso;
}

void BinarySearchTreeTest::test_TodosLosMetodos()
{
    BST_test::test_AgregarElemento();
    BST_test::test_ExisteElemento();
    BST_test::test_EliminarElemento();
    BST_test::test_EstaBalanceado();
    BST_test::test_EstaLleno();
    BST_test::test_EsPerfecto();
    BST_test::test_Altura();
    BST_test::test_GetNumNodos();
    BST_test::test_EstaVacio();
}

// PRIVATE
void BinarySearchTreeTest::eliminarElementoEnAmbos(BinarySearchTree& BST, vector<int>& vector, int elementoAEliminar)
{
    try
    {
        BST.eliminarElemento(elementoAEliminar);
        std::vector<int>::iterator elementoActual = vector.begin();
        while(elementoActual != vector.end() && *elementoActual != elementoAEliminar)
            elementoActual++;
        if(elementoActual != vector.end())
            vector.erase(elementoActual);
        else
        {
            throw out_of_range("El elemento no pertenece al vector");
        }
    }
    catch(const out_of_range& ex)
    {
        rethrow_exception(current_exception());
    }
    catch(const exception& ex)
    {
        cout << "Ocurrio una excepcion al intentar eliminar un elemento: " << ex.what() << endl;
    }
}

int BinarySearchTreeTest::rellenarBST(BinarySearchTree& BST, const vector<int>& vector)
{
   try
   {
       for(int elemento : vector)
            BST.agregarElemento(elemento);
   }
   catch(const exception& ex)
   {
       cout << "Ocurrio una excepcion al intentar insertar el set de datos en el arbol: " << ex.what() << endl;
       return 1;
   }
   return 0;
}

bool BinarySearchTreeTest::contienenLosMismosElementos(BinarySearchTree& BST, const vector<int>& vector)
{
    try
    {
        bool contienenLosMismosElementos = true;
        for(int elemento : vector)
            contienenLosMismosElementos = ( !BST.existeElemento(elemento) ? false : contienenLosMismosElementos );
        return contienenLosMismosElementos;
    }
    catch(const exception& ex)
    {
        cout << "Ocurrio una excepcion al intentar comparar los elementos del set de datos y el BST: " << ex.what() << endl;
        return false;
    }
}





