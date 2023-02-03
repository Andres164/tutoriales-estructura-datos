#pragma once
#include <memory>

class NodoLinkedList
{
    public:
        NodoLinkedList();

        std::shared_ptr<NodoLinkedList> getNodoPredecesor();
        void setNodoPredecesor(std::shared_ptr<NodoLinkedList>);
        std::shared_ptr<NodoLinkedList> getNodoSucesor();
        void setNodoSucesor(std::shared_ptr<NodoLinkedList>);
        int getElemento();
        void setElemento(int);

    protected:
        int elemento;
        std::shared_ptr<NodoLinkedList> nodoSucesor;
        std::shared_ptr<NodoLinkedList> nodoPredecesor;

};
