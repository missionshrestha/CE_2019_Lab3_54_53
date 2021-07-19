#pragma once
#define MAX_NUM_NODES 128
#include "AbstractBST.h"

struct ArrayNode
{
    int key;
    int value;

    ArrayNode(int key, int value) : key(key), value(value) {}
};

class ArrayBinarySearchTree : public AbstractBST
{
public:
    ArrayBinarySearchTree();
    ~ArrayBinarySearchTree();

    bool isEmpty();
    void add(int key, int value);
    void max(int &output);
    void min(int &output);
    bool exists(int targetKey);
    void inorder();

private:
    ArrayNode *nodes[MAX_NUM_NODES];

    void inorder(int index, char sep = ' ');
};
