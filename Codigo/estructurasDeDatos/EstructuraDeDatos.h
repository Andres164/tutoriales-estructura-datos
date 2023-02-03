#pragma once
#include <memory>
#include "NodoEstructuraDatos.h"

class EstructuraDeDatos
{
    public:
        EstructuraDeDatos();
        std::shared_ptr<NodoEstructuraDatos> getRaiz();

    protected:
        std::shared_ptr<NodoEstructuraDatos> raiz;
};
