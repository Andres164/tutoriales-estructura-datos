#pragma once
#include "LinkedList.h"

class Stack
{
    public:
        Stack();
        void push(int);
        int pop();
        bool estaVacia();
        int Longitud();
        int top();

    private:
        LinkedList contenedor;
};
