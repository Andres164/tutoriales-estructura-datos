#pragma once
#include "EstructuraDeDatos.h"

class LinkedList: public EstructuraDeDatos
{
    public:
        LinkedList();
        bool estaVacia();
        void push_back(int);
    private:
};
