#include "LinkedBST.h"
#include <iostream>
using namespace std;

int main()
{

    LinkedBST l;

    l.remove(25);

    l.add(25, 1);
    l.add(30, 1);
    l.add(20, 3);
    l.add(27, 3);
    l.add(33, 3);
    l.add(32, 9);
    l.add(10, 4);
    l.add(24, 4);
    l.add(8, 5);

    l.inorder();
    int max, min;
    l.max(max);
    l.min(min);
    cout << "Min: " << min << "  Max: " << max << endl;
    cout << 10 << ": " << l.exists(10) << endl;
    cout << 99 << ": " << l.exists(99) << endl;
    cout << 35 << ": " << l.exists(35) << endl;
    
    l.inorder();
    l.remove(25);
    l.remove(30);
    l.inorder();
}