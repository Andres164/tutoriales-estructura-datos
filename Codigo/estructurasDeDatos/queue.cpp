#include <memory>
#include "Queue.h"
#include "NodoLinkedList.h"

Queue::Queue() : contenedor(LinkedList()) {}

void Queue::push(int elemento) { this->contenedor.push_back(elemento); }

int Queue::pop()
{
    int elemento = this->contenedor.elementoEnIndex(0);
    this->contenedor.pop_front();
    return elemento;
}

bool Queue::estaVacia() { return this->contenedor.estaVacia(); }

int Queue::Longitud() { return this->contenedor.Longitud(); }

int Queue::primerElemento() { return this->contenedor.elementoEnIndex(0); }

int Queue::ultimoElemento() { return this->contenedor.elementoEnIndex(this->Longitud()-1); }

// FOR DEBUGGING
#include <iostream>
#include "../algoritmosEstructurasDatos/manejoEstructuraDatos.h"
void Queue::imprimirElementos()
{
    if(!this->estaVacia())
        manejoEstructuraDatos::imprimirLinkedList(this->contenedor);
    else
        std::cout << "Queue vacia" << std::endl;
}
