#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() : raiz(nullptr), numDeNodos(0) {}

void BinarySearchTree::agregarElemento(int valorData)
{
    shared_ptr<NodoBinaryTree> nuevoNodo = make_shared<NodoBinaryTree>( NodoBinaryTree() );
    nuevoNodo->setData(valorData);
    if(this->estaVacio())
    {
        this->raiz = nuevoNodo;
        this->numDeNodos++;
        return;
    }
    shared_ptr<NodoBinaryTree> nodoActual = this->raiz;
    bool nodoAgregado = false;
    while(!nodoAgregado)
    {
        if(valorData < nodoActual->getData())
        {
            if(nodoActual->getIzquierdo())
                nodoActual = nodoActual->getIzquierdo();
            else
            {
                nodoActual->setIzquierdo(nuevoNodo);
                nodoAgregado = true;
            }
        }
        else
        {
            if(nodoActual->getDerecho())
                nodoActual = nodoActual->getDerecho();
            else
            {
                nodoActual->setDerecho(nuevoNodo);
                nodoAgregado = true;
            }
        }
    }
    this->numDeNodos++;
}

bool BinarySearchTree::estaVacio()
{
    return this->numDeNodos < 1 ? true : false;
}
