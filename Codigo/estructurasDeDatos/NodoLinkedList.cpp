#include "NodoLinkedList.h"
template <typename T>
NodoLinkedList<T>::NodoLinkedList() : nodoSucesor(nullptr), nodoPredecesor(nullptr) {}
NodoLinkedList::NodoLinkedList(T valorElemento) : elemento(valorElemento), nodoSucesor(nullptr), nodoPredecesor(nullptr) {}

std::shared_ptr< NodoLinkedList<T> >  NodoLinkedList::getNodoPredecesor() { return this->nodoPredecesor; }
void NodoLinkedList::setNodoPredecesor(std::shared_ptr< NodoLinkedList<T> > predecesor) { this->nodoPredecesor = predecesor; }

std::shared_ptr< NodoLinkedList<T> > NodoLinkedList::getNodoSucesor() { return this->nodoSucesor; }
void NodoLinkedList::setNodoSucesor(std::shared_ptr< NodoLinkedList<T> > sucesor) { this->nodoSucesor = sucesor; }

T NodoLinkedList::getElemento() { return this->elemento; }
void NodoLinkedList::setElemento(T nuevoValor) { this->elemento = nuevoValor; }
