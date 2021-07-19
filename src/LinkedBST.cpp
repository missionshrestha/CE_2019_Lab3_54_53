#include <iostream>
#include "LinkedBST.h"
using namespace std;

LinkedBST::LinkedBST()
{
    root = NULL;
}
LinkedBST::~LinkedBST()
{
    delete root;
}
bool LinkedBST::isEmpty()
{
    return root == NULL;
}
bool LinkedBST::add(int key, int value)
{

    Node *newNode = new Node();
    newNode->data.key = key;
    newNode->data.value = value;
    newNode->leftchild = NULL;
    newNode->rightchild = NULL;
    Node *temp = new Node;
    temp = root;

    // add(root,newNode);
    if (isEmpty())
    {
        root = newNode;
    }
    else if (exists(key))
    {
        cout << "Target key: " << key << " already exists." << endl;
        return 0;
    }
    else
    {
        while (temp->leftchild != NULL || temp->rightchild != NULL)
        {
            if (newNode->data.key < temp->data.key)
            {
                if (temp->leftchild != NULL)
                {
                    temp = temp->leftchild;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (temp->rightchild != NULL)
                {
                    temp = temp->rightchild;
                }
                else
                {
                    break;
                }
            }
        }

        if (newNode->data.key < temp->data.key)
        {
            temp->leftchild = newNode;
        }
        else
        {
            temp->rightchild = newNode;
        }
    }
    cout << "New key: " << key << " with value " << value << " added." << endl;
    return 1;
}

void LinkedBST::max(int &output)
{
    if (!isEmpty())
    {
        Node *max = new Node();
        max = root;
        while (max->rightchild != NULL)
        {
            max = max->rightchild;
        }
        output = max->data.key;
    }
    else
    {
        cout << "Tree is Empty!" << endl;
    }
}
void LinkedBST::min(int &output)
{
    if (!isEmpty())
    {
        Node *min = new Node();
        min = root;
        while (min->leftchild != NULL)
        {
            min = min->leftchild;
        }
        output = min->data.key;
    }
    else
    {
        cout << "Tree is empty!" << endl;
    }
}

bool LinkedBST::exists(int targetkey)
{
    if (!isEmpty())
    {
        Node *temp = new Node();
        temp = root;
        while (temp != NULL && temp->data.key != targetkey)
        {
            if (temp->data.key > targetkey)
            {
                temp = temp->leftchild;
            }
            else
            {
                temp = temp->rightchild;
            }
        }
        return temp != NULL;
    }
    else
    {
        cout << "Tree is empty!" << endl;
        return false;
    }
}

bool LinkedBST::remove(int targetkey){
if(root==NULL){
    cout<<"BST is empty!"<<endl;
    return 0;
}
    Node *del=root;
    Node *parent_del=NULL;
    while(del!=NULL && del->data.key!=targetkey){
        parent_del=del;
        if(targetkey<del->data.key){
            del=del->leftchild;
        }
        else{
            del=del->rightchild;
        }
    }
    
    if(del==NULL){
        cout<<targetkey<<" doesn't exist."<<endl;
        return 0;
    }


    if(del->leftchild==NULL || del->rightchild==NULL){
if (parent_del==NULL){
    root = (root->leftchild!=NULL) ? root->leftchild : root->rightchild;
    cout<<targetkey<<" deleted!"<<endl;
    return true;
}

        if(del->leftchild!=NULL){
            if(parent_del->leftchild==del){
                parent_del->leftchild=del->leftchild;
            }
            else{
                parent_del->rightchild=del->leftchild;
            }
        }
        else{
            if(parent_del->leftchild==del){
                parent_del->leftchild=del->rightchild;
            }
            else{
                parent_del->rightchild=del->rightchild;
            }
        }
    }
    else{
         Node *temp=del->rightchild;
         Node *parent_temp=NULL;

         while(temp->leftchild!=NULL){
             parent_temp=temp;
             temp=temp->leftchild;
         }

         del->data.key=temp->data.key;

         if(parent_temp!=NULL){
             parent_temp->leftchild=temp->rightchild;

         }
         else{

             del->rightchild=temp->rightchild;
         }

// return true;

    }
    return true;

}

void LinkedBST::inorder()
{
    if (!isEmpty())
    {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }
    else
    {
        cout << "Nothing to Traverse!" << endl;
    }
}

void LinkedBST::inorder(Node *node)
{
    if (node != NULL)
    {
        inorder(node->leftchild);
        cout << node->data.key << " ";
        inorder(node->rightchild);
    }
}
