#pragma once
#include <memory>
#include "NodoBinaryTree.h"

class BinaryTree
{
    public:
        BinaryTree();
        void insertar(int, int);

    protected:
        std::shared_ptr<NodoBinaryTree> raiz;

        std::shared_ptr<NodoBinaryTree> getPtrElemento(int);
};
