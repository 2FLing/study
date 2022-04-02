#include "BinarySearchTree.h"
#include <string>
#include <vector>
void insert_elements(BST*, string);
int main()
{
    string choice = "", num;
    int num_for_look_up;
    vector<string> nums;
    while (choice != "n")
    {
        BST* bst = new BST();
        cout << "Insert a list of elements into Binary Search Tree: ";
        getline(cin, num);
        insert_elements(bst, num);
        cout << "Post-order: ";
        bst->post_order();
        cout << endl;
        cout << "Largest element in the list is: " << bst->maximum_tree() << endl;
        cout << "Insert a number for look up: ";
        cin >> num_for_look_up;
        bst->search(num_for_look_up);
        getchar();
        cout << "continue test?(\'n\' for quit):";
        getline(cin, choice);
    }
    return 0;
}

void insert_elements(BST* bst, string nums)
{
    string number = "";
    nums.push_back(' ');
    for (auto ele : nums)
    {
        if (ele != ' ')
            number.push_back(ele);
        else
        {
            bst->insert(stoi(number));
            number = "";
        }
    }
}