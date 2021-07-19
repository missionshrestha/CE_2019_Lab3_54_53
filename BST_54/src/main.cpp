#include <iostream>
#include "ArrayBST.h"
#include "AbstractBST.h"
using namespace std;

int main()
{
    ArrayBinarySearchTree a;
    int value, option;
    int max, min;

    do
    {
        cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. add()" << endl;
        cout << "2. inorder()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. max()" << endl;
        cout << "5. min()" << endl
             << endl;
        std::cin >> option;
        switch (option)
        {
        case 0:
            cout << "The program exited!" << endl;
            break;

        case 1:
            cout << "Enter the number you want: " << endl;
            std::cin >> value;
            a.add(value, 2);

            break;

        case 2:
            a.inorder();
            break;

        case 3:
            if (a.isEmpty())
            {
                cout << "The tree is emplty!" << endl;
            }
            else
            {
                cout << "The tree is not empty" << endl;
            }
            break;

        case 4:
            a.max(max);
            cout << "Max: " << max << endl;

            break;

        case 5:
            a.min(min);
            cout << "Min: " << min << endl;
            break;

        default:
            cout << "Enter numbers from options" << endl;
            break;
        }

    } while (option != 0);
    return 0;
}
