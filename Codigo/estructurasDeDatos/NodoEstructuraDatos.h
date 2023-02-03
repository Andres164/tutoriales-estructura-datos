#pragma once
#include <memory>

class NodoEstructuraDatos
{
    public:
        NodoEstructuraDatos();
        std::shared_ptr<NodoEstructuraDatos> getNodoSucesor();
        void setNodoSucesor(std::shared_ptr<NodoEstructuraDatos>);
        int getElemento();
        void setElemento(int);

    protected:
        std::shared_ptr<NodoEstructuraDatos> nodoSucesor;
        int elemento;
};
