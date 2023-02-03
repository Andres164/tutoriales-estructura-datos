#pragma once
#include "NodoLinkedList.h"

class LinkedList
{
    private:
        std::shared_ptr<NodoLinkedList> raiz;
        int longitud;
    public:
        LinkedList();
        std::shared_ptr<NodoLinkedList> getRaiz();
        bool estaVacia();
        void push_back(int);
        void pop_front();
        void eliminarElemento(int);
        void eliminarEnIndex(int);
        int Longitud();

    private:
        std::shared_ptr<NodoLinkedList> getPtrElemento(int);
        std::shared_ptr<NodoLinkedList> getPtrIndex(int);
        void eliminarNodo(std::shared_ptr<NodoLinkedList>);
};
