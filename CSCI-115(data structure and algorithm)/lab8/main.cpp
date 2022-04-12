#include "List.h"
#include <string>
#include <vector>
void insert_elements(BST *, string);
int main()
{
    string choice = "", num;
    int num_for_look_up;
    vector<string> nums;
    while (choice != "n")
    {
        BST *bst = new BST();
        cout << "Insert a list of elements into Binary Search Tree: ";
        getline(cin, num);
        insert_elements(bst, num);
        cout << "Post-order: ";
        bst->printTree(bst->getRoot());
        cout << endl;
        cout << "Largest element in the list is: " << bst->Largest(bst->getRoot()) << endl;
        cout << "Insert a number for look up: ";
        cin >> num_for_look_up;
        if (!bst->FindNode(bst->getRoot(), num_for_look_up))
        {
            cout << num_for_look_up << " not found!" << endl;
        }
        getchar();
        cout << "continue test?(\'n\' for quit):";
        getline(cin, choice);
    }
    return 0;
}

void insert_elements(BST *bst, string nums)
{
    string number = "";
    nums.push_back(' ');
    for (auto ele : nums)
    {
        if (ele != ' ')
            number.push_back(ele);
        else
        {
            bst->InsertNode(bst->getRoot(),stoi(number));
            number = "";
        }
    }
}