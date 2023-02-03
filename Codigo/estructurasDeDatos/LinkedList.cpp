#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() : raiz(nullptr) { }
shared_ptr<NodoLinkedList> LinkedList::getRaiz() { return this->raiz; }

bool LinkedList::estaVacia() { return this->raiz ? false : true; }

void LinkedList::push_back(int valorElemento)
{
    shared_ptr<NodoLinkedList> nuevoNodo = make_shared<NodoLinkedList>(NodoLinkedList());
    nuevoNodo->setElemento(valorElemento);
    if(this->estaVacia())
    {
        this->raiz = nuevoNodo;
        return;
    }
    shared_ptr<NodoLinkedList> nodoActual;
    for(nodoActual = this->raiz; nodoActual->getNodoSucesor(); nodoActual = nodoActual->getNodoSucesor() ) {}
    nuevoNodo->setNodoPredecesor(nodoActual);
    nodoActual->setNodoSucesor(nuevoNodo);
}

void LinkedList::eliminarElemento(int elemento)
{
    shared_ptr<NodoLinkedList> nodoEliminar = this->getPtrElemento(elemento);
    if(nodoEliminar && nodoEliminar != this->raiz)
    {
        shared_ptr<NodoLinkedList> predecesor = nodoEliminar->getNodoPredecesor();
        predecesor->setNodoSucesor(nodoEliminar->getNodoSucesor());
    }
    else if(nodoEliminar)
        this->raiz = this->raiz->getNodoSucesor();
}

// Private
shared_ptr<NodoLinkedList> LinkedList::getPtrElemento(int elemento)
{
    shared_ptr<NodoLinkedList> nodoActual = this->raiz;
    while(nodoActual && nodoActual->getElemento() != elemento)
        nodoActual = nodoActual->getNodoSucesor();
    return nodoActual ? nodoActual : nullptr;
}
