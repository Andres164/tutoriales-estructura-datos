#pragma once
#include "LinkedList.h"

class Queue
{
    public:
        Queue();
        void push(int);
        int pop();
        bool estaVacia();
        int Longitud();
        int primerElemento();
        int ultimoElemento();

        // For Debugging
        void imprimirElementos();

    private:
        LinkedList contenedor;
};
