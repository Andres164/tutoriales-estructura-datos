#pragma once
#include <memory>

template <typename T> class NodoLinkedList
{
    public:
        NodoLinkedList() : nodoSucesor(nullptr), nodoPredecesor(nullptr)
        {}

        NodoLinkedList(T valorElemento) : elemento(valorElemento), nodoSucesor(nullptr), nodoPredecesor(nullptr)
        {}

        std::shared_ptr< NodoLinkedList<T> > getNodoPredecesor()
        {
            return this->nodoPredecesor;
        }

        void setNodoPredecesor(std::shared_ptr< NodoLinkedList<T> > predecesor)
        {
            this->nodoPredecesor = predecesor;
        }

        std::shared_ptr< NodoLinkedList<T> > getNodoSucesor()
        {
            return this->nodoSucesor;
        }

        void setNodoSucesor(std::shared_ptr< NodoLinkedList<T> > sucesor)
        {
            this->nodoSucesor = sucesor;
        }

        T getElemento()
        {
            return this->elemento;
        }

        void setElemento(T nuevoValor)
        {
            this->elemento = nuevoValor;
        }

    protected:
        T elemento;
        std::shared_ptr< NodoLinkedList<T> > nodoSucesor;
        std::shared_ptr< NodoLinkedList<T> > nodoPredecesor;

};
