#pragma once
#include <vector>
#include "BinarySearchTree.h"

class BinarySearchTreeTest
{
    private:
        static const std::vector<int> setDeDatos;
    public:
        static bool test_ExisteElemento();
        static bool test_EliminarElemento();
        static bool test_EstaBalanceado();
        static bool test_EstaLleno();
        static bool test_EsPerfecto();
        static bool test_Altura();
        static bool test_GetNumNodos();
        static bool test_EstaVacio();

    private:
        static void eliminarElementoEnAmbos(BinarySearchTree&, vector<int>&, int);
        static int rellenarBST(BinarySearchTree&, vector<int>&);
        static bool contienenLosMismosElementos(BinarySearchTree&, vector<int>&);
};
