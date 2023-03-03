#include <iostream>
#include <memory>
#include <exception>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "BinarySearchTree.h"
#include "algoritmosEstructurasDatos/manejoEstructuraDatos.h"
#include "QueueTest.h"
#include "StackTest.h"
#include "BinarySearchTreeTest.h"
#include "LinkedListTest.h"

using namespace std;

int main()
{
    LinkedListTest::test_TodosLosMetodos();
    //cout << LinkedListTest::test_TodosLosMetodos() << endl;

    return 0;
}
