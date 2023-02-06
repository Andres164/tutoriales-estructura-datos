#include "Stack.h"

Stack::Stack() : contenedor(LinkedList()) { }

void Stack::push(int elemento) { this->contenedor.push_back(elemento); }

int Stack::pop()
{
    int elemento = this->contenedor.elementoEnIndex(this->Longitud() -1);
    this->contenedor.pop_back();
    return elemento;
}

bool Stack::estaVacia() { return this->contenedor.estaVacia(); }

int Stack::Longitud() { return this->contenedor.Longitud(); }

int Stack::top() { return this->contenedor.elementoEnIndex(this->Longitud() -1); }
