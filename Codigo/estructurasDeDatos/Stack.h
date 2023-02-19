#pragma once
#include "LinkedList.h"

template <typename T>
class Stack
{
    public:
        Stack() : contenedor(LinkedList<T>())
        { }

        void push(T valorElemento)
        {
            this->contenedor.push_back(valorElemento);
        }

        T pop()
        {
            T elemento = this->contenedor.elementoEnIndex(this->longitud() -1);
            this->contenedor.pop_back();
            return elemento;
        }

        bool estaVacia()
        {
            return this->contenedor.estaVacia();
        }

        int longitud()
        {
            return this->contenedor.Longitud();
        }

        T top()
        {
            return this->contenedor.elementoEnIndex(this->longitud() -1);
        }

    private:
        LinkedList<T> contenedor;
};
