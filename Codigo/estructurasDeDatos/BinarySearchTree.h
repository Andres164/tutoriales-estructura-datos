#pragma once
#include <memory>
#include "NodoBinaryTree.h"

class BinarySearchTree
{
    private:
        std::shared_ptr<NodoBinaryTree> raiz;
        int numDeNodos;

    public:
        BinarySearchTree();
        void agregarElemento(int);
        bool existeElemento(int);
        void eliminarElemento(int);
        void imprimirInOrder();
        void imprimirPreOrder();
        void imprimirPostOrder();
        void imprimirLevelOrder();
        int getNumNodos();
        int altura();
        bool estaVacio();

        void imprimirInOrder(std::shared_ptr<NodoBinaryTree>);
        void imprimirPreOrder(std::shared_ptr<NodoBinaryTree>);
        void imprimirPostOrder(std::shared_ptr<NodoBinaryTree>);
        int altura(std::shared_ptr<NodoBinaryTree>);

    protected:
        std::shared_ptr<NodoBinaryTree> getPtrPadreDelElemento(int);
        std::shared_ptr<NodoBinaryTree> getPtrPadreElementoMenor(std::shared_ptr<NodoBinaryTree>);
        void eliminarNodo(std::shared_ptr<NodoBinaryTree>, std::shared_ptr<NodoBinaryTree>);
        void eliminarRaiz();
        bool estaBalanceado();
};
