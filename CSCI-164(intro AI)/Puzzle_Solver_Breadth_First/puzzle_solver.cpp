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

/*  "160273485" --output:  ddluurdlldrruuldrd and it expanded 17649
    "462301587" --output: rdlurulldrdluruldrrulddr and it expanded 144794
    "821574360" --output:  luurdllurdldrulurrdluldrurdd and it expanded 179951
    "840156372" --output: dllurdldrurdlulurdrulddr and it expanded 129862
    "530478126" --output: dldlurdruulddrullurdldrr and it expanded 128902
    "068314257" --output: drrullddruldrruuldldrr and it expanded 84632
    "453207186" --output: rdluulddruuldrdr and it expanded 12853 number of nodes
    "128307645" --output: lurdrullddruldrruldr and it expanded 60545 number of nodes
    "035684712" --output: rddluruldrdlurrdllurruldrd and it expanded 167432 number of nodes
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
    "16235A749C08DEBF" -- output:
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