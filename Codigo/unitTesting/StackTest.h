#pragma once
#include <vector>

class StackTest
{
private:
    static const std::vector<int> setDeDatos;

public:
    static bool test_PushPop();
    static bool test_Top();
};
