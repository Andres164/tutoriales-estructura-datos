#include <iostream>
#include <memory>
#include "manejoEstructuraDatos.h"
#include "NodoEstructuraDatos.h"

namespace manejoEstructuraDatos
{
    void imprimirEstructuraDatos(EstructuraDeDatos estructuraDatos)
    {
        std::shared_ptr<NodoEstructuraDatos> nodoActual = estructuraDatos.getRaiz();
        for(int i = 0; nodoActual ; nodoActual = nodoActual->getNodoSucesor())
        {
            std::cout << "Elemento[" << i <<"] = " << nodoActual->getElemento() << std::endl;
            i++;
        }
    }
}
