#pragma once
#include <memory>
#include "NodoEstructuraDatos.h"

class NodoLinkedList: public NodoEstructuraDatos
{
    public:
        NodoLinkedList();
        std::shared_ptr<NodoLinkedList> getNodoPredecesor();
        void setNodoPredecesor(std::shared_ptr<NodoLinkedList>);

    protected:
        std::shared_ptr<NodoLinkedList> nodoPredecesor;

};
