#include <iostream>
#include <memory>
#include "manejoEstructuraDatos.h"

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
    void vaciarStack(Stack<T> pilaAddress)
    {
        std::shared_ptr<Stack<T>> pila = std::make_shared<Stack<T>>(pilaAddress);
        for(int i = 0; !pila->estaVacia(); i++)
            std::cout << "Elemento " << i << ": " << pila->pop() << std::endl;
    }
}
