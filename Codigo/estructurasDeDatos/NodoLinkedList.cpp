#include "NodoLinkedList.h"

NodoLinkedList::NodoLinkedList() : nodoSucesor(nullptr), nodoPredecesor(nullptr) {}

std::shared_ptr<NodoLinkedList>  NodoLinkedList::getNodoPredecesor() { return this->nodoPredecesor; }
void NodoLinkedList::setNodoPredecesor(std::shared_ptr<NodoLinkedList> predecesor) { this->nodoPredecesor = predecesor; }

std::shared_ptr<NodoLinkedList> NodoLinkedList::getNodoSucesor() { return this->nodoSucesor; }
void NodoLinkedList::setNodoSucesor(std::shared_ptr<NodoLinkedList> sucesor) { this->nodoSucesor = sucesor; }

int NodoLinkedList::getElemento() { return this->elemento; }
void NodoLinkedList::setElemento(int nuevoValor) { this->elemento = nuevoValor; }
