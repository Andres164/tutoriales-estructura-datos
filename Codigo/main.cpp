#include <iostream>
#include <memory>
#include <exception>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "BinarySearchTree.h"
#include "algoritmosEstructurasDatos/manejoEstructuraDatos.h"
#include "algoritmosEstructurasDatos/algoritmosAcomodo.h"
#include "algoritmosEstructurasDatos/manejoArreglos.h"
#include "QueueTest.h"
#include "StackTest.h"
#include "BinarySearchTreeTest.h"
#include "LinkedListTest.h"
#include "algoritmosEstructurasDatos/algoritmosAcomodoTest.h"

using namespace std;

int main()
{
    algoritmosAcomodoTest::test_AlgoritmoAcomodo(algoritmosAcomodoTest::AlgoritmosDeAcomodo::ShellSort, 50000);
}



