#include <iostream>
#include <memory>
#include "manejoEstructuraDatos.h"

namespace manejoEstructuraDatos
{
    void imprimirLinkedList(LinkedList lista)
    {
        std::shared_ptr<NodoLinkedList> nodoActual = lista.getRaiz();
        for(int i = 0; nodoActual ; nodoActual = nodoActual->getNodoSucesor())
        {
            std::cout << "Elemento[" << i <<"] = " << nodoActual->getElemento() << std::endl;
            i++;
        }
    }

    void vaciarStack(std::shared_ptr<Stack> pila)
    {
        for(int i = 0; !pila->estaVacia(); i++)
            std::cout << "Elemento " << i << ": " << pila->pop() << std::endl;
    }
}
