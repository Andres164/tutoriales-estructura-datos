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

void BinarySearchTree::eliminarElemento(int data)
{
    if(data == this->raiz->getData())
    {

        return;
    }
    shared_ptr<NodoBinaryTree> padreElemento = this->getPtrPadreDelElemento(data);
    if(!padreElemento)
        return;
    shared_ptr<NodoBinaryTree> nodoEliminar = data < padreElemento->getData() ? padreElemento->getIzquierdo() : padreElemento->getDerecho();
    eliminarNodo(nodoEliminar, padreElemento);
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

int BinarySearchTree::getNumNodos()
{
    return this->numDeNodos;
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


// PRIVATE
shared_ptr<NodoBinaryTree> BinarySearchTree::getPtrPadreDelElemento(int data)
{
    shared_ptr<NodoBinaryTree> nodoPadre = this->raiz;
    while(nodoPadre)
    {
        if(data < nodoPadre->getData())
        {
            shared_ptr<NodoBinaryTree> nodoIzquierdo = nodoPadre->getIzquierdo();
            if(nodoIzquierdo && data == nodoIzquierdo->getData())
                return nodoPadre;
            nodoPadre = nodoIzquierdo;
        }
        else
        {
            shared_ptr<NodoBinaryTree> nodoDerecho = nodoPadre->getDerecho();
            if(nodoDerecho && data == nodoDerecho->getData())
                return nodoPadre;
            nodoPadre = nodoDerecho;
        }
    }
    return nullptr;
}

shared_ptr<NodoBinaryTree> BinarySearchTree::getPtrPadreElementoMenor(shared_ptr<NodoBinaryTree> raiz)
{
    shared_ptr<NodoBinaryTree> padreElementoMenor = raiz;
    shared_ptr<NodoBinaryTree> nodoIzquierdo = raiz->getIzquierdo();
    if(!nodoIzquierdo)
        return nullptr;
    while(nodoIzquierdo->getIzquierdo())
    {
        padreElementoMenor = padreElementoMenor->getIzquierdo();
        nodoIzquierdo = padreElementoMenor->getIzquierdo();
    }
    return padreElementoMenor;
}

void BinarySearchTree::eliminarNodo(shared_ptr<NodoBinaryTree> nodoEliminar, shared_ptr<NodoBinaryTree> nodoPadre)
{
    if(!nodoEliminar->getIzquierdo() && !nodoEliminar->getDerecho())
    {
        if(nodoPadre->getIzquierdo() == nodoEliminar)
            nodoPadre->setIzquierdo(nullptr);
        else
            nodoPadre->setDerecho(nullptr);
        this->numDeNodos--;
        return;
    }
    else if(nodoEliminar->getIzquierdo() && nodoEliminar->getDerecho())
    {
        shared_ptr<NodoBinaryTree> padreElementoReemplazo = getPtrPadreElementoMenor(nodoEliminar->getDerecho()) ;
        if(padreElementoReemplazo)
        {
            int dataElementoReemplazo = padreElementoReemplazo->getIzquierdo()->getData();
            nodoEliminar->setData(dataElementoReemplazo);
            padreElementoReemplazo->setIzquierdo(nullptr);
        }
        else
        {
            int dataElementoReemplazo = nodoEliminar->getDerecho()->getData();
            nodoEliminar->setData(dataElementoReemplazo);
            nodoEliminar->setDerecho(nullptr);
        }
        this->numDeNodos--;
        return;
    }
    shared_ptr<NodoBinaryTree> nodoHijo = nodoEliminar->getIzquierdo() ? nodoEliminar->getIzquierdo() : nodoEliminar->getDerecho();
    if(nodoPadre->getIzquierdo() == nodoEliminar)
        nodoPadre->setIzquierdo(nodoHijo);
    else
        nodoPadre->setDerecho(nodoHijo);
    this->numDeNodos--;
}
