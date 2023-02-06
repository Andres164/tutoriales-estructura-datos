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
        int elementoEnIndex(int);
        bool estaVacia();
        void insertarElemento(int, int);
        void push_front(int);
        void push_back(int);
        void pop_front();
        void pop_back();
        void eliminarElemento(int);
        void eliminarEnIndex(int);
        void vaciar();
        int Longitud();

    private:
        std::shared_ptr<NodoLinkedList> getPtrElemento(int);
        std::shared_ptr<NodoLinkedList> getPtrIndex(int);
        void eliminarNodo(std::shared_ptr<NodoLinkedList>);
};
