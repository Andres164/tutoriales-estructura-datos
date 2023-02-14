#pragma once
#include "NodoLinkedList.h"

template <typename T> class LinkedList
{
    private:
        std::shared_ptr< NodoLinkedList<T> > raiz;
        int longitud;
    public:
        LinkedList();
        std::shared_ptr< NodoLinkedList<T> > getRaiz();
        T elementoEnIndex(int);
        bool estaVacia();
        void insertarElemento(int, T);
        void push_front(T);
        void push_back(T);
        void pop_front();
        void pop_back();
        void eliminarElemento(T);
        void eliminarEnIndex(int);
        void vaciar();
        int Longitud();

    private:
        std::shared_ptr< NodoLinkedList<T> > getPtrElemento(T);
        std::shared_ptr< NodoLinkedList<T> > getPtrIndex(int);
        void eliminarNodo(std::shared_ptr< NodoLinkedList<T> >);
};
