#pragma once
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct
{
    int elemento;
    struct SimpleListNode* siguienteNodo;
} SimpleListNode;

typedef struct
{
    SimpleListNode* raiz;
    int longitud;

} SimpleList;

SimpleListNode* nuevoNodo(int valorElemento)
{
    SimpleListNode* nuevoNodo = malloc( sizeof(SimpleListNode) );
    nuevoNodo->elemento = valorElemento;
    nuevoNodo->siguienteNodo = NULL;
    return nuevoNodo;
}

void push_back(SimpleList lista, int valorElemento)
{

}

void imprimirLista()
{

}

SimpleListNode* getPtr_predecesorDeElemento(SimpleListNode* raiz, int elemento)
{

}

void eliminarElemento(int elemento)
{

}

bool estaVacia()
{

}
