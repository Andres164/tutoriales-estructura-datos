#pragma once
#include <memory>
#include "LinkedList.h"

template <typename T>
class Queue
{
    public:
        Queue() : contenedor(LinkedList<T>())
        {}

        void push(T valorElemento)
        {
            this->contenedor.push_back(valorElemento);
        }

        T pop()
        {
            T elemento = this->contenedor.elementoEnIndex(0);
            this->contenedor.pop_front();
            return elemento;
        }

        bool estaVacia()
        {
            return this->contenedor.estaVacia();
        }

        int Longitud()
        {
            return this->contenedor.Longitud();
        }

        T primerElemento()
        {
            return this->contenedor.elementoEnIndex(0);
        }

        T ultimoElemento()
        {
            return this->contenedor.elementoEnIndex(this->Longitud()-1);
        }

    private:
        LinkedList<T> contenedor;
};
