#include "Puzzle_Depth_First.h"
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
        if (test_solution(puzzle, res.first) == goal)
            cout << "For solving this puzzle the movement will be " << res.first << " and it expanded " << res.second << " number of nodes while solving this puzzle." << endl;
        cout << "-------------------------------------------------------------------" << endl;
    }
    return 0;
}
// goal1: 123456780
// goal2: 123456789ABCDEF0

/*  "160273485" --output:  ddlulurdrullddruurdldr and it expanded 17726 number of nodes
    "462301587" --output: ruldlurdruldldruldrrulldrurd and it expanded 62078 number of nodes
    "821574360" --output:  lulurdrdlulurrdlldrulurddruuldldrr and it expanded 46025 number of nodes
    "840156372" --output: llddruurdllurdldrruulddluurddr and it expanded 19435 number of nodes
    "530478126" --output: lldrrdluulddrrullurddluurdrd and it expanded 10529 number of nodes
    "068314257" --output: rrdllurrdllurrdldrulldrrullurdrdlurd and it expanded 36033 number of nodes
    "453207186" --output: lurdlurdrdllurdluruldrdr and it expanded 9781 number of nodes
    "128307645" --output: ldrrullurrdldrululddrurd and it expanded 1646 number of nodes
    "035684712" --output: rrdlldrrulldrruulldrrdllurdruuldrd and it expanded 2446 number of node
    "684317025" --output: rrullurrdllurrdldrulldrrullurdrdlurd and it expanded 37234 number of nodes
    "028514637" --output: rrdluldrrdllurrulldrrdllururdd and it expanded 65372 number of nodes
    "618273540" --output: lulurrdldlurrulddruulddlurrdluurdd and it expanded 38481 number of nodes
    "042385671" --output: rrdlldrrullurrdlldruldruulddrr and it expanded 2808 number of nodes
    "420385716" --output: dldrullurdrdllurrullddrurd and it expanded 17745 number of nodes
    "054672813" --output: ddruldruruldrulldrrdluurdldr and it expanded 33523 number of nodes
    "314572680" --output: llurdrulurddlluruldrrulddr and it expanded 11772 number of nodes
    "637218045" --output: rruulldrrdluulddrruldr and it expanded 2733 number of nodes
    "430621875" --output: dlldruurdllurrddlurd and it expanded 3305 number of nodes
    "158274036" --output: ruurdlldrrullurrdllurdlurrddlurd and it expanded 58338 number of nodes
    "130458726" --output: ddlurdllurruldldrurdlurd and it expanded 22695 number of nodes


    EASY:
    "16235A749C08DEBF" -- output: luurrddldr and it expanded 851 number of nodes
    "0634217859ABDEFC" --output: rdlurdldrrrd and it expanded 1872 number of nodes
    "012456379BC8DAEF" --output: rrdrdlldrr and it expanded 220 number of nodes
    "51246A38097BDEFC" -output: rulurrddrd and it expanded 802 number of nodes
    "12345678D9CFEBA0" --output: lurdlurdlllurrdr and it expanded 12247 number of nodes

    DIFFICULT:
    "71A92CE03DB4658F" --output: 
    "02348697DF5A1EBC"
    "39A1D0EC7BF86452"
    "EAB480FC19D56237"
    "7DB13C52F46E80A9" */
