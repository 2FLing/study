#include"Puzzle_Depth_FIrst.h"
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
//123456789ABCDEF0
