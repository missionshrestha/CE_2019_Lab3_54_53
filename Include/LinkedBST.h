#pragma once
#include "AbstractBST.h"
struct Data
{
    int key;
    int value;
};

struct Node
{
    Data data;
    Node *leftchild;
    Node *rightchild;
};

class LinkedBST : public AbstractBST
{
public:
    LinkedBST();
    ~LinkedBST();
    bool isEmpty();
    bool add(int key, int value);
    void max(int &output);
    void min(int &output);
    bool exists(int targetkey);
    bool remove(int targetkey);
    void inorder();

private:
    Node *root;

    void inorder(Node *node);
};
