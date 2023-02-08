#include "NodoBinaryTree.h"

using namespace std;

NodoBinaryTree::NodoBinaryTree() : izquierdo(nullptr), derecho(nullptr) {}

shared_ptr<NodoBinaryTree> NodoBinaryTree::getIzquierdo() { return this->izquierdo; }

void NodoBinaryTree::setIzquierdo(shared_ptr<NodoBinaryTree> nuevoNodo) { this->izquierdo = nuevoNodo; }

shared_ptr<NodoBinaryTree> NodoBinaryTree::getDerecho() { return this->derecho; }

void NodoBinaryTree::setDerecho(shared_ptr<NodoBinaryTree> nuevoNodo) { this->derecho = nuevoNodo; }
