#pragma once
#include <iostream>
#include <memory>
#include "LinkedList.h"
#include "Stack.h"

namespace manejoEstructuraDatos
{
    template <typename T>
    void imprimirLinkedList(LinkedList<T> lista)
    {
        std::shared_ptr<NodoLinkedList<T>> nodoActual = lista.getRaiz();
        for(int i = 0; nodoActual ; nodoActual = nodoActual->getNodoSucesor())
        {
            std::cout << "Elemento[" << i <<"] = " << nodoActual->getElemento() << std::endl;
            i++;
        }
    }

    template <typename T>
    void vaciarStack(Stack<T>* ptrPila)
    {
        std::shared_ptr<Stack<T>> pila(ptrPila);
        for(int i = 0; !pila->estaVacia(); i++)
            std::cout << "Elemento " << i << ": " << pila->pop() << std::endl;
    }
}
