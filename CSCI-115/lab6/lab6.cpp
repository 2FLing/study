#include "quick_sort.h"
using namespace std;
void median_tester();
int main()
{
    string choice = "";
    vector<int> v;
    while (choice != "q")
    {
        cout << "1 for the first element in the list to be pivot." << endl;
        cout << "2 for a random element in the list to be pivot." << endl;
        cout << "3 for the median of the first,middle, and last elements in the array to be pivot" << endl;
        cout << "4 for testing pick_median function." << endl;
        cout << "enter \'q\' to quit" << endl;
        cout << "Please enter your choice: ";
        getline(cin, choice);
        if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "q")
        {
            continue;
        }
        else if (choice == "q")
            break;
        else
        {
            if (choice != "4")
            {
                v = create_vector();
                if (choice == "1")
                    quick_sort(v, 0, v.size() - 1);
                else if (choice == "2")
                    random_quick_sort(v, 0, v.size() - 1);
                else
                    median_quick_sort(v, 0, v.size() - 1);
                print_vector(v);
            }
            else
                median_tester();
            cout << "-------------------------------------------" << endl;
            cout << "want to continue?(enter \'q\' to quit): ";
            getline(cin, choice);
        }
    }
    return 0;
}
void median_tester()
{
    string numbers;
    vector<int> v;
    cout << "For testing pick_mdeian function, please only enter three numbers." << endl;
    v = create_vector();
    cout << "The median number of them will be: " << pick_median(v[0], v[1], v[2]) << endl;
}