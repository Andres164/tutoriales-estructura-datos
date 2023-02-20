#pragma once
#include <vector>
#include "BinarySearchTree.h"

class BinarySearchTreeTest
{
    private:
        static const std::vector<int> setDeDatos;
    public:
        bool test_ExisteElemento();
        bool  test_EliminarElemento();
        bool test_EstaBalanceado();
        bool test_EstaLleno();
        bool test_EsPerfecto();
        bool test_Altura();
        bool test_GetNumNodos();
        bool test_EstaVacio();
};
