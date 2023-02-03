#pragma once
#include "NodoLinkedList.h"

class LinkedList
{
    public:
        LinkedList();
        std::shared_ptr<NodoLinkedList> getRaiz();
        bool estaVacia();
        void push_back(int);
        void eliminarElemento(int);

    private:
        std::shared_ptr<NodoLinkedList> raiz;
        std::shared_ptr<NodoLinkedList> getPtrElemento(int);
};
