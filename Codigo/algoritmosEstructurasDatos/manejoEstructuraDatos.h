#pragma once
#include <memory>
#include "LinkedList.h"
#include "Stack.h"

namespace manejoEstructuraDatos
{
    template <typename T>
    void imprimirLinkedList(LinkedList<T>);

    template <typename T>
    void vaciarStack(Stack<T>);
}
