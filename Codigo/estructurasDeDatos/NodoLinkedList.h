#pragma once
#include <memory>

template <typename T> class NodoLinkedList
{
    public:
        NodoLinkedList();
        NodoLinkedList(T);
        std::shared_ptr< NodoLinkedList<T> > getNodoPredecesor();
        void setNodoPredecesor(std::shared_ptr< NodoLinkedList<T> >);
        std::shared_ptr< NodoLinkedList<T> > getNodoSucesor();
        void setNodoSucesor(std::shared_ptr< NodoLinkedList<T> >);
        T getElemento();
        void setElemento(T);

    protected:
        T elemento;
        std::shared_ptr< NodoLinkedList<T> > nodoSucesor;
        std::shared_ptr< NodoLinkedList<T> > nodoPredecesor;

};
