#include "Puzzle_A_Star.h"
#include "Pqueue.h"
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

/* "160273485"   --  ddluruldldrruuldruldrdluurdldr and it expanded 538 number of nodes
    "462301587" -- urdllurrdlurdluldrruldlurrdldruullddrulurrdd and it expanded 1327 number of nodes
    "821574360" -- luldrruulldrrdllurulddruuldrdluurddlurdluruldrdluurrdlldrurdllurdruulldrrdlluurrdldruulddrulurddlurdlurdllurrdluldrruldlurdlurrulldrdluurrdlldrurd and it expanded 3711 number of nodes
    "840156372" -- lldrurddluruldldrruuldruldldrulurrddllurulddruuldrdrulurddluurddluruldlurddruuldrulldrurdllurrddluuldrdr and it expanded 2147 number of nodes
    "530478126" -- ldrdluurddlurullddruuldruldrdluurdldrr and it expanded 297 number of nodes
    "068314257" -- drurdlurdldruullddrulurdlurdlurrdlurddllurruldruldldrruulldrrdlulurrdllurdlurddrullurrddllurrullddrrullurdlurdrulldrdr and it expanded 642 number of nodes
    "453207186" -- rdluulddrrululdrrd and it expanded 111 number of nodes
    "128307645" --  druldrulldrruuldldrruldruldrulldrruldrulurddllurrdluldrruuldldruldrruldruldrulldrrulurddllurrdluruldrdluldrrulurdldrulldruldrruldruldrulldrruldlurrdllurdlurrd and it expanded 697 number of nodes
    "035684712" -- rdrulldrrulddrullurrdldruuldrdluurdldruuldlurrdllurdrulldrrdlurulddrulurddlurulddrulurdllurrdluldrrulldruldrurddlurulldrurdldruuldrd and it expanded 780 number of nodes
    "684317025" -- urulddrruuldrdllurulddrulurdlurdrulldrruldlurrdllurdlurdrulldrdluurdrulldruldrrulldrruldrulldruldrrulldrdruulddr and it expanded 2554 number of nodes
    "028514637" -- drdrullurrddllurrulldrdrulldrruldluurdldrruulldrrdlurulldrurdd and it expanded 307 number of nodes
    "618273540" -- lulurdldrrulldruldruurddllurdruulldrrdlluurrdlldrruuldldruldruurddllurrullddrrullurrddluulddrrulldruldrulurrddluldrruuldldruldrurdluurddllurrulldrdluurrddluldrruuld
                -- ldruurddlluruldrdruulldrdlurdlururddllurdruulldrdlurdluurrddluldrrulldruldrurdllurdrullurdrulldrdlurdluurrddluldrrulldrr and it expanded 1313 number of nodes
   
    "042385671" -- rdldrrulurddllurdlurrdllurruldlurrdd and it expanded 816 number of nodes 
    "420385716" -- dldruuldlurdrdlurdluuldrurddlurulddrulurdllurdrulldrruldlurrdd and it expanded 509 number of nodes
    "054672813" -- drdluurdlurrdllurdrulldrruldruldldrurdllururdd and it expanded 269 number of nodes
    "314572680" -- luuldrrullddrrulurddllurdlurrulddrulldrurdllururdlldrurdllurrulldrrdlluurddr and it expanded 419 number of nodes
    "637218045" -- rruulldrrdlulurdlurdldrrullurrddluldrruulldruldruldrdluurrdlldrruulldruldrurdldruldruullddrr and it expanded 646 number of nodes
    "430621875" -- ddlurulddrulurddluruldlurrdldruulldrrdlluurddlurdrulldrurd and it expanded 1085 number of nodes
    "158274036" -- urrdllurdlurulddrrullurrddllururdlldrruldruulddruldlurruldruldldrrulurddluruldrulldrdluurdruldldrruuldruldrdluurdd and it expanded 761 number of nodes
    "130458726" -- ldrdluurddlurulddr and it expanded 75 number of nodes while solving this puzzle.


    EASY:
    "16235A749C08DEBF" --luurrddldr and it expanded 24 number of nodes
    "0634217859ABDEFC" -- drulddrrrd and it expanded 22 number of nodes
    "012456379BC8DAEF" -- rrdrdlldrr and it expanded 23 number of nodes
    "51246A38097BDEFC" -- rulurrddrd and it expanded 24 number of nodes
    "12345678D9CFEBA0" -- uldllurrdr and it expanded 26 number of nodes

    DIFFICULT:
    "71A92CE03DB4658F" 
    "02348697DF5A1EBC"
    "39A1D0EC7BF86452"
    "EAB480FC19D56237"
    "7DB13C52F46E80A9" */