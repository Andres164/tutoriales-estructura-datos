#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
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
        this->eliminarRaiz();
        return;
    }
    shared_ptr<NodoBinaryTree> padreElemento = this->getPtrPadreDelElemento(data);
    if(!padreElemento)
        return;
    shared_ptr<NodoBinaryTree> nodoEliminar = data < padreElemento->getData() ? padreElemento->getIzquierdo() : padreElemento->getDerecho();
    this->eliminarNodo(nodoEliminar, padreElemento);
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

void BinarySearchTree::imprimirLevelOrder()
{
    if(estaVacio())
        return;
    queue<shared_ptr<NodoBinaryTree>> que;
    que.push(this->raiz);
    while(!que.empty())
    {
        shared_ptr<NodoBinaryTree> nodoActual = que.front();
        cout << nodoActual->getData() << endl;
        que.pop();
        if(nodoActual->getIzquierdo())
            que.push(nodoActual->getIzquierdo());
        if(nodoActual->getDerecho())
            que.push(nodoActual->getDerecho());
    }
}

bool BinarySearchTree::estaBalanceado()
{
    int altura = 0;
    return this->estaBalanceado(this->raiz, altura);
}

bool BinarySearchTree::estaLleno()
{
    return this->estaLleno(this->raiz);
}

bool BinarySearchTree::esPerfecto()
{
    int nodosQueDebeTener = pow( 2, this->altura() +1 ) -1;
    return this->numDeNodos == nodosQueDebeTener ? true : false;
}

int BinarySearchTree::altura()
{
    return this->altura(this->raiz);
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

bool BinarySearchTree::estaBalanceado(shared_ptr<NodoBinaryTree> raiz, int &altura)
{
    int alturaIzquierdo = 0, alturaDerecho = 0;
    if(!raiz->getIzquierdo() && !raiz->getDerecho())
    {
        altura = 1;
        return true;
    }
    bool izquierdoEstaBalanceado = raiz->getIzquierdo() ? estaBalanceado(raiz->getIzquierdo(), alturaIzquierdo) : true;
    bool derechoEstaBalanceado = raiz->getDerecho() ? estaBalanceado(raiz->getDerecho(), alturaDerecho) : true;
    if(!izquierdoEstaBalanceado || !derechoEstaBalanceado)
        return false;
    unsigned int diferenciaAlturas = alturaIzquierdo > alturaDerecho ? alturaIzquierdo - alturaDerecho : alturaDerecho - alturaIzquierdo;
    altura = max(alturaIzquierdo, alturaDerecho) +1;
    return diferenciaAlturas > 1 ? false : true;
}

bool BinarySearchTree::estaLleno(shared_ptr<NodoBinaryTree> raiz)
{
    if(!raiz->getIzquierdo() != !raiz->getDerecho())
        return false;
    bool izquierdoEstaLleno = raiz->getIzquierdo() ? estaLleno(raiz->getIzquierdo()) : true;
    bool derechoEstaLleno = raiz->getDerecho() ? estaLleno(raiz->getDerecho()) : true;
    return izquierdoEstaLleno && derechoEstaLleno;
}

int BinarySearchTree::altura(shared_ptr<NodoBinaryTree> raiz)
{
    if(!raiz->getIzquierdo() && !raiz->getDerecho())
        return 0;
    int alturaIzquierdo = raiz->getIzquierdo() ? altura(raiz->getIzquierdo()) : 0;
    int alturaDerecho = raiz->getDerecho() ? altura(raiz->getDerecho()) : 0;
    return max( alturaIzquierdo, alturaDerecho ) +1;
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
    if(nodoEliminar->getIzquierdo() && nodoEliminar->getDerecho())
    {
        shared_ptr<NodoBinaryTree> padreElementoReemplazo = getPtrPadreElementoMenor(nodoEliminar->getDerecho()) ;
        if(padreElementoReemplazo)
        {
            shared_ptr<NodoBinaryTree> nodoReemplazo = padreElementoReemplazo->getIzquierdo();
            nodoEliminar->setData(nodoReemplazo->getData());
            padreElementoReemplazo->setIzquierdo(nodoReemplazo->getDerecho());
        }
        else
        {
            shared_ptr<NodoBinaryTree> nodoReemplazo = nodoEliminar->getDerecho();
            nodoEliminar->setData(nodoReemplazo->getData());
            nodoEliminar->setDerecho(nodoReemplazo->getDerecho());
        }
    }
    else
    {
        shared_ptr<NodoBinaryTree> nodoHijo = nodoEliminar->getIzquierdo() ? nodoEliminar->getIzquierdo() : nodoEliminar->getDerecho();
        if(nodoPadre->getIzquierdo() == nodoEliminar)
            nodoPadre->setIzquierdo(nodoHijo);
        else
            nodoPadre->setDerecho(nodoHijo);
    }
    this->numDeNodos--;
}

void BinarySearchTree::eliminarRaiz()
{
    if(this->estaVacio())
        return;

    if( this->raiz->getIzquierdo() && this->raiz->getDerecho() )
    {
        shared_ptr<NodoBinaryTree> padreElementoReemplazo = getPtrPadreElementoMenor( this->raiz->getDerecho() );
        if(padreElementoReemplazo)
        {
            shared_ptr<NodoBinaryTree> nodoReemplazo = padreElementoReemplazo->getIzquierdo();
            raiz->setData(nodoReemplazo->getData());
            padreElementoReemplazo->setIzquierdo(nodoReemplazo->getDerecho());
        }
        else
        {
            raiz->setData(raiz->getDerecho()->getData());
            raiz->setDerecho(raiz->getDerecho()->getDerecho());
        }
    }
    else
        this->raiz = this->raiz->getIzquierdo() ? this->raiz->getIzquierdo() : this->raiz->getDerecho();
    this->numDeNodos--;
}
