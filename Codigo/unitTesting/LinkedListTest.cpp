#include <iostream>
#include <exception>
#include "LinkedListTest.h"

const vector<int> LinkedListTest::setDeDatos = { -20, 10, -1586, -2,147,483,648, 12, 10, -20, 789, 2,147,483,647, 0, 81, 39, -69 };


bool LinkedListTest::test_push_back()
{
    std::cout << "--------------------------- test_push_back ---------------------------\n\n";
    bool testExitoso = true;
    LinkedList<int> testList = LinkedList<int>();
    unsigned int elementosInsertados = listaPushBackVector(testList, LinkedListTest::setDeDatos);
    std::cout << "Elementos insertados... " << elementosInsertados << "/" << LinkedListTest::setDeDatos.size() << std::endl;
    testExitoso = contienenLosMismosElementos(testList, LinkedListTest::setDeDatos);
    std::cout << "El linked list contiene los elementos insertados? " << (testExitoso ? "SI" : "NO") << std::endl;
    testExitoso = elementosInsertados != LinkedListTest::setDeDatos.size() ? false : testExitoso;
    std::cout << "test_push_back... " << ( testExitoso ? "Exitoso" : "Fallido" ) << std::endl;
    return testExitoso;
}

bool LinkedListTest::test_push_front()
{
    std::cout << "--------------------------- test_push_front ---------------------------\n\n";
    LinkedList<int> testList = LinkedList<int>();
    unsigned int elementosInsertados = listaPushFrontVector(testList, LinkedListTest::setDeDatos);
    std::cout << "Elementos insertados... " << elementosInsertados << "/" << LinkedListTest::setDeDatos.size() << std::endl;
    bool contienenLosMismosElementos = true;
    try
    {
        for(unsigned int i = 0; i < LinkedListTest::setDeDatos.size(); i++)
            contienenLosMismosElementos = ( LinkedListTest::setDeDatos[LinkedListTest::setDeDatos.size()-1 -i] != testList.elementoEnIndex(i) ? false : contienenLosMismosElementos );
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar comparar los elementos de las estructuras de datos: " << ex.what() << std::endl;
        contienenLosMismosElementos = false;
    }
    bool testExitoso = contienenLosMismosElementos;
    std::cout << "El linked list contiene los elementos insertados? " << (testExitoso ? "SI" : "NO") << std::endl;
    testExitoso = elementosInsertados != LinkedListTest::setDeDatos.size() ? false : testExitoso;
    std::cout << "test_push_front... " << ( testExitoso ? "Exitoso" : "Fallido" ) << std::endl;
    return testExitoso;
}

bool LinkedListTest::test_pop_back()
{
    bool testExitoso = true;

    return testExitoso;
}

bool LinkedListTest::test_pop_front()
{
    bool testExitoso = true;

    return testExitoso;
}

bool LinkedListTest::test_InsertarElemento()
{
    bool testExitoso = true;

    return testExitoso;
}

bool LinkedListTest::test_EliminarElemento()
{
    bool testExitoso = true;

    return testExitoso;
}

bool LinkedListTest::test_EliminarEnIndex()
{
    bool testExitoso = true;

    return testExitoso;
}

bool LinkedListTest::test_elementoEnIndex()
{
    bool testExitoso = true;

    return testExitoso;
}

bool LinkedListTest::test_EstaVacia()
{
    bool testExitoso = true;

    return testExitoso;
}

bool LinkedListTest::test_Vaciar()
{
    bool testExitoso = true;

    return testExitoso;
}

bool LinkedListTest::test_Longitud()
{
    bool testExitoso = true;

    return testExitoso;
}


// PRIVATE
int LinkedListTest::listaPushBackVector(LinkedList<int>& list, const vector<int>& vector)
{
    unsigned int i = 0;
    try
    {
        for(; i < vector.size(); i++)
            list.push_back(vector[i]);
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar insertar los elementos al linked lsit: " << ex.what() << std::endl;
    }
    return i;
}

int LinkedListTest::listaPushFrontVector(LinkedList<int>& list, const vector<int>& vector)
{
    unsigned int i = 0;
    try
    {
        for(; i < vector.size(); i++)
            list.push_front(vector[i]);
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar insertar los elementos al linked lsit: " << ex.what() << std::endl;
    }
    return i;
}

bool LinkedListTest::contienenLosMismosElementos(LinkedList<int>& list, const vector<int>& vector)
{
    bool contienenLosMismosElementos = true;
    try
    {
        for(unsigned int i = 0; i < vector.size(); i++)
            contienenLosMismosElementos = ( vector[i] != list.elementoEnIndex(i) ? false : contienenLosMismosElementos );
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar comparar los elementos de las estructuras de datos: " << ex.what() << std::endl;
        return false;
    }
    return contienenLosMismosElementos;
}


