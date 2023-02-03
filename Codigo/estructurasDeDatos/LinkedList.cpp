#include "LinkedList.h"
#include "NodoLinkedList.h"

LinkedList::LinkedList()
{
    //ctor
}
bool LinkedList::estaVacia() { return this->raiz ? false : true; }
void LinkedList::push_back(int valorElemento)
{
    std::shared_ptr<NodoLinkedList> nuevoNodo;
    nuevoNodo->setElemento(valorElemento);
    if(this->estaVacia())
    {
        this->raiz = nuevoNodo;
        return;
    }
    std::shared_ptr<NodoEstructuraDatos> nodoActual;
    for(nodoActual = this->raiz; nodoActual )
}
