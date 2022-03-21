#include "puzzle_breadth_first.h"
#include "Node.h"
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    string puzzle, goal;
    pair<string, int> res;
    while (true)
    {
        cout << "Enter your puzzle(enter \'q\' to quit.) : ";
        getline(cin, puzzle);
        if (puzzle == "q")
            break;
        cout << "Enter your goal:";
        getline(cin, goal);
        res = solve_puzzle(puzzle, goal);
        cout << "For solving this puzzle the movement will be " << res.first << " and it expanded " << res.second << " number of nodes while solving this puzzle." << endl;
        cout << "-------------------------------------------------------------------" << endl;
    }
    return 0;
}
// goal1: 123456780
// goal2: 123456789ABCDEF0

/*  "160273485"
    "462301587"
    "821574360"
    "840156372"
    "530478126"
    "068314257"
    "453207186"
    "128307645"
    "035684712"
    "684317025"
    "028514637"
    "618273540"
    "042385671"
    "420385716"
    "054672813"
    "314572680"
    "637218045"
    "430621875"
    "158274036"
    "130458726"


    EASY:
    "16235A749C08DEBF"
    "0634217859ABDEFC"
    "012456379BC8DAEF"
    "51246A38097BDEFC"
    "12345678D9CFEBA0"

    DIFFICULT:
    "71A92CE03DB4658F"
    "02348697DF5A1EBC"
    "39A1D0EC7BF86452"
    "EAB480FC19D56237"
    "7DB13C52F46E80A9" */