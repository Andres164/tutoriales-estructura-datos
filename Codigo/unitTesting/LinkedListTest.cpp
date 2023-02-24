#include <iostream>
#include <exception>
#include "LinkedListTest.h"

const vector<int> LinkedListTest::setDeDatos = { -20, 10, -1586, -2,147,483,648, 12, 10, -20, 789, 2,147,483,647, 0, 81, 39, -69 };


bool LinkedListTest::test_push_back()
{

}

bool LinkedListTest::test_push_front()
{

}

bool LinkedListTest::test_pop_back()
{

}

bool LinkedListTest::test_pop_front()
{

}

bool LinkedListTest::test_InsertarElemento()
{

}

bool LinkedListTest::test_EliminarElemento()
{

}

bool LinkedListTest::test_EliminarEnIndex()
{

}

bool LinkedListTest::test_elementoEnIndex()
{

}

bool LinkedListTest::test_EstaVacia()
{

}

bool LinkedListTest::test_Vaciar()
{

}

bool LinkedListTest::test_Longitud()
{

}


// PRIVATE
int LinkedListTest::rellenarLinkedList(LinkedList<int>& list, const vector<int>& vector)
{
    int i = 0;
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

bool LinkedListTest::contienenLosMismosElementos(LinkedList<int>& list, const vector<int>& vector)
{
    bool contienenLosMismosElementos = true;
    try
    {
        for(int i = 0; i < vector.size(); i++)
            contienenLosMismosElementos = ( vector[i] != list.elementoEnIndex(i) ? false : contienenLosMismosElementos );
    }
    catch(const exception& ex)
    {
        std::cout << "Ocurrio una excepcion al intentar comparar los elementos de las estructuras de datos: " << ex.what() << std::endl;
        return false;
    }
    return contienenLosMismosElementos;
}


