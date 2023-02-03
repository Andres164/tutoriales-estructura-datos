#include <memory>
#include "NodoEstructuraDatos.h"

NodoEstructuraDatos::NodoEstructuraDatos() : nodoSucesor(nullptr) {}

std::shared_ptr<NodoEstructuraDatos> NodoEstructuraDatos::getNodoSucesor() { return this->nodoSucesor; }
void NodoEstructuraDatos::setNodoSucesor(std::shared_ptr<NodoEstructuraDatos> sucesor) { this->nodoSucesor = sucesor; }
int NodoEstructuraDatos::getElemento() { return this->elemento; }
void NodoEstructuraDatos::setElemento(int nuevoValor) { this->elemento = nuevoValor; }

