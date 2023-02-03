#include "EstructuraDeDatos.h"

EstructuraDeDatos::EstructuraDeDatos() : raiz(nullptr)
{
    //ctor
}
std::shared_ptr<NodoEstructuraDatos> EstructuraDeDatos::getRaiz() { return this->raiz; }
