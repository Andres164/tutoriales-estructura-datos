#include "NodoLinkedList.h"

NodoLinkedList::NodoLinkedList() : nodoPredecesor(nullptr) {}
std::shared_ptr<NodoLinkedList>  NodoLinkedList::getNodoPredecesor() { return this->nodoPredecesor; }
void NodoLinkedList::setNodoPredecesor(std::shared_ptr<NodoLinkedList> nuevoNodo) { this->nodoPredecesor = nuevoNodo; }
