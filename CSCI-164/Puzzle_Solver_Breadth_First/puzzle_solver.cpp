#include "puzzle_breadth_first.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    string puzzle, goal;
    pair<string, int> res;
    cout << "Enter your puzzle:";
    getline(cin, puzzle);
    cout << "Enter your goal:";
    getline(cin, goal);
    res = solve_puzzle(puzzle, goal);
    cout << "For solving this puzzle the movement will be " << res.first << " and it expanded " << res.second << " number of nodes while solving this puzzle." << endl;
    return 0;
}