#pragma once
#include <memory>
#include "LinkedList.h"
#include "Stack.h"

namespace manejoEstructuraDatos
{
    void imprimirLinkedList(LinkedList);
    void vaciarStack(std::shared_ptr<Stack>);
}
