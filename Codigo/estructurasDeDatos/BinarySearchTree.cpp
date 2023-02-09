#include <iostream>
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

bool BinarySearchTree::existeElemento(int data)
{
    shared_ptr<NodoBinaryTree> nodoActual = this->raiz;
    while(nodoActual)
    {
        if(data == nodoActual->getData())
            return true;
        else if(data < nodoActual->getData())
            nodoActual = nodoActual->getIzquierdo();
        else
            nodoActual = nodoActual->getDerecho();
    }
    return false;
}

void BinarySearchTree::imprimirPreOrder()
{
    this->imprimirPreOrder(this->raiz);
}

void BinarySearchTree::imprimirInOrder()
{
    this->imprimirInOrder(this->raiz);
}

void BinarySearchTree::imprimirPostOrder()
{
    this->imprimirPostOrder(this->raiz);
}

bool BinarySearchTree::estaVacio()
{
    return this->numDeNodos < 1 ? true : false;
}

void BinarySearchTree::imprimirPreOrder(shared_ptr<NodoBinaryTree> nodoPadre)
{
    if(!nodoPadre)
        return;
    cout << nodoPadre->getData() << endl;
    imprimirPreOrder(nodoPadre->getIzquierdo());
    imprimirPreOrder(nodoPadre->getDerecho());
}

void BinarySearchTree::imprimirInOrder(shared_ptr<NodoBinaryTree> nodoActual)
{
    if(!nodoActual)
        return;
    imprimirInOrder(nodoActual->getIzquierdo());
    cout << nodoActual->getData() << endl;
    imprimirInOrder(nodoActual->getDerecho());

}

void BinarySearchTree::imprimirPostOrder(shared_ptr<NodoBinaryTree> nodoActual)
{
    if(!nodoActual)
        return;
    imprimirInOrder(nodoActual->getIzquierdo());
    imprimirInOrder(nodoActual->getDerecho());
    cout << nodoActual->getData() << endl;
}

void BinarySearchTree::imprimirLevelOrder(shared_ptr<NodoBinaryTree>)
{

}
