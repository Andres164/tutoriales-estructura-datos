#pragma once
#include <memory>
#include "NodoBinaryTree.h"

class BinarySearchTree
{
    public:
        BinarySearchTree();
        void agregarElemento(int);
        bool estaVacio();

    protected:
        std::shared_ptr<NodoBinaryTree> raiz;
        int numDeNodos;
};
