#pragma once
#include <memory>

using namespace std;

class NodoBinaryTree
{
    public:
        NodoBinaryTree();
        shared_ptr<NodoBinaryTree> getIzquierdo();
        void setIzquierdo(shared_ptr<NodoBinaryTree>);
        shared_ptr<NodoBinaryTree> getDerecho();
        void setDerecho(shared_ptr<NodoBinaryTree>);
        int getData();
        void setData(int);

    protected:
        shared_ptr<NodoBinaryTree> izquierdo;
        shared_ptr<NodoBinaryTree> derecho;
        int data;
};
