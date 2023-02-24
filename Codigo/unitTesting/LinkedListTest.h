#pragma once
#include <vector>
#include "LinkedList.h"

class LinkedListTest
{
    private:
        const static vector<int> setDeDatos;
    public:
        static bool test_push_back();
        static bool test_push_front();
        static bool test_pop_back();
        static bool test_pop_front();
        static bool test_InsertarElemento();
        static bool test_EliminarElemento();
        static bool test_EliminarEnIndex();
        static bool test_elementoEnIndex();
        static bool test_EstaVacia();
        static bool test_Vaciar();
        static bool test_Longitud();

    private:
        static int rellenarLinkedList(LinkedList<int>&, const vector<int>&);
        static bool contienenLosMismosElementos(LinkedList<int>&, const vector<int>&);
};
