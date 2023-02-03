#include <stdexcept>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() : raiz(nullptr), longitud(0) { }
shared_ptr<NodoLinkedList> LinkedList::getRaiz() { return this->raiz; }
int LinkedList::Longitud() { return this->longitud; }


bool LinkedList::estaVacia() { return this->longitud > 0 ? false : true; }

void LinkedList::push_back(int valorElemento)
{
    shared_ptr<NodoLinkedList> nuevoNodo = make_shared<NodoLinkedList>(NodoLinkedList());
    nuevoNodo->setElemento(valorElemento);
    if(this->estaVacia())
    {
        this->raiz = nuevoNodo;
        this->longitud++;
        return;
    }
    shared_ptr<NodoLinkedList> nodoActual;
    for(nodoActual = this->raiz; nodoActual->getNodoSucesor(); nodoActual = nodoActual->getNodoSucesor() ) {}
    nuevoNodo->setNodoPredecesor(nodoActual);
    nodoActual->setNodoSucesor(nuevoNodo);
    this->longitud++;
}

void LinkedList::pop_front()
{

}

void LinkedList::eliminarElemento(int elemento)
{
    shared_ptr<NodoLinkedList> nodoEliminar = this->getPtrElemento(elemento);
    if(!nodoEliminar)
        return;
    this->eliminarNodo(nodoEliminar);
}

void LinkedList::eliminarEnIndex(int index)
{
    shared_ptr<NodoLinkedList> nodoEliminar = this->getPtrIndex(index);
    this->eliminarNodo(nodoEliminar);
}

// Private
shared_ptr<NodoLinkedList> LinkedList::getPtrElemento(int elemento)
{
    shared_ptr<NodoLinkedList> nodoActual = this->raiz;
    while(nodoActual && nodoActual->getElemento() != elemento)
        nodoActual = nodoActual->getNodoSucesor();
    return nodoActual ? nodoActual : nullptr;
}

shared_ptr<NodoLinkedList> LinkedList::getPtrIndex(int index)
{
    if(index < 0 || index >= this->longitud)
        throw std::out_of_range("El Index esta fuera del rango de la lista");
    shared_ptr<NodoLinkedList> nodoActual = this->raiz;
    for(int i = 1; i <= index; i++)
        nodoActual = nodoActual->getNodoSucesor();
    return nodoActual;
}

void LinkedList::eliminarNodo(shared_ptr<NodoLinkedList> nodoEliminar)
{
    if(nodoEliminar != this->raiz)
    {
        shared_ptr<NodoLinkedList> predecesor = nodoEliminar->getNodoPredecesor();
        predecesor->setNodoSucesor(nodoEliminar->getNodoSucesor());
    }
    else
        this->raiz = this->raiz->getNodoSucesor();
    this->longitud--;
}
