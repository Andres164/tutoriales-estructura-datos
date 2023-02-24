#pragma once
#include <stdexcept>
#include "NodoLinkedList.h"

using namespace std;

template <typename T> class LinkedList
{
private:
    std::shared_ptr< NodoLinkedList<T> > raiz;
    int longitud;
public:
    LinkedList() : raiz(nullptr), longitud(0) { }

    std::shared_ptr< NodoLinkedList<T> > getRaiz()
    {
        return this->raiz;
    }

    T elementoEnIndex(int index)
    {
        if(this->estaVacia())
            throw std::out_of_range("ElementoEnIndex: La lista esta vacia");
        shared_ptr< NodoLinkedList<T> > nodo = this->getPtrIndex(index);
        return nodo->getElemento();
    }

    bool estaVacia()
    {
        return this->longitud > 0 ? false : true;
    }

    void insertarElemento(int index, T valorElemento)
    {
        shared_ptr< NodoLinkedList<T> > nuevoNodo = make_shared< NodoLinkedList<T> >( NodoLinkedList<T> ());
        nuevoNodo->setElemento(valorElemento);
        shared_ptr< NodoLinkedList<T> > nodoEnIndex = this->getPtrIndex(index);
        shared_ptr< NodoLinkedList<T> > predecesor = nodoEnIndex->getNodoPredecesor();
        if(nodoEnIndex == this->raiz)
            this->raiz = nuevoNodo;
        else
            predecesor->setNodoSucesor(nuevoNodo);
        nuevoNodo->setNodoSucesor(nodoEnIndex);
        nuevoNodo->setNodoPredecesor(predecesor);
        nodoEnIndex->setNodoPredecesor(nuevoNodo);
        this->longitud++;
    }

    void push_front(T valorElemento)
    {
        if(this->estaVacia())
        {
            this->raiz = make_shared< NodoLinkedList<T> >( NodoLinkedList<T> (valorElemento));
            this->longitud++;
            return;
        }
        this->insertarElemento(0, valorElemento);
    }

    void push_back(T valorElemento)
    {
        shared_ptr< NodoLinkedList<T> > nuevoNodo = make_shared< NodoLinkedList<T> >( NodoLinkedList<T> ());
        nuevoNodo->setElemento(valorElemento);
        if(this->estaVacia())
        {
            this->raiz = nuevoNodo;
            this->longitud++;
            return;
        }
        shared_ptr< NodoLinkedList<T> > nodoActual;
        for(nodoActual = this->raiz; nodoActual->getNodoSucesor(); nodoActual = nodoActual->getNodoSucesor() ) {}
            nuevoNodo->setNodoPredecesor(nodoActual);
        nodoActual->setNodoSucesor(nuevoNodo);
        this->longitud++;
    }

    void pop_front()
    {
        if(this->estaVacia())
            throw std::out_of_range("Intento usar pop_front en una lista vacia");
        this->eliminarEnIndex(0);
    }

    void pop_back()
    {
        if(this->estaVacia())
            throw std::out_of_range("Intento usar pop_back en una lista vacia");
        this->eliminarEnIndex(this->longitud -1);
    }

    void eliminarElemento(T valorElemento)
    {
        shared_ptr< NodoLinkedList<T> > nodoEliminar = this->getPtrElemento(valorElemento);
        if(!nodoEliminar)
            return;
        this->eliminarNodo(nodoEliminar);
    }

    void eliminarEnIndex(int index)
    {
        shared_ptr< NodoLinkedList<T> > nodoEliminar = this->getPtrIndex(index);
        this->eliminarNodo(nodoEliminar);
    }

    void vaciar()
    {
        this->raiz = nullptr;
        this->longitud = 0;
    }

    int Longitud()
    {
        return this->longitud;
    }

private:
    std::shared_ptr< NodoLinkedList<T> > getPtrElemento(T valorElemento)
    {
        shared_ptr< NodoLinkedList<T> > nodoActual = this->raiz;
        while(nodoActual && nodoActual->getElemento() != valorElemento)
            nodoActual = nodoActual->getNodoSucesor();
        return nodoActual ? nodoActual : nullptr;
    }

    std::shared_ptr< NodoLinkedList<T> > getPtrIndex(int index)
    {
        if(index < 0 || index >= this->longitud)
            throw std::out_of_range("El Index esta fuera del rango de la lista");
        shared_ptr< NodoLinkedList<T> > nodoActual = this->raiz;
        for(int i = 1; i <= index; i++)
            nodoActual = nodoActual->getNodoSucesor();
        return nodoActual;
    }


    void eliminarNodo(std::shared_ptr< NodoLinkedList<T> > nodoEliminar)
    {
        if(nodoEliminar != this->raiz)
        {
            shared_ptr< NodoLinkedList<T> > predecesor = nodoEliminar->getNodoPredecesor();
            predecesor->setNodoSucesor(nodoEliminar->getNodoSucesor());
        }
        else
            this->raiz = this->raiz->getNodoSucesor();
        this->longitud--;
    }

};
