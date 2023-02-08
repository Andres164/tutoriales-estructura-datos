#pragma once
#include <memory>

class BinaryTree
{
    public:
        BinaryTree();
        void insertar(int valorElemento);

    protected:
        std::shared_ptr<NodoBinaryTree> raiz;
};
