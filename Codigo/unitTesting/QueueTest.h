#pragma once
#include <vector>
#include "Queue.h"


class QueueTest
{
private:
     static const std::vector<int> setDeDatos;
public:
    static int test_PushPop();
    static int test_EstaVacia();
    static int test_Longitud();
    static int test_PrimerElemento();
    static int test_UltimoElemento();
    static void test_TodosLosMetodos();
};
