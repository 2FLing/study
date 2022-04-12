    #include <iostream>
    #include <vector>
    #include <climits>
    using namespace std;
    int coin(int);
    int min(int, int);
    int main()
    {
        cout<<coin(27);
        return 0;
    }
    int min(int a, int b)
    {
        return (a < b ? a : b);
    }
    int coin(int price)
    {
        if (price == 0)
        {
            return 0;
        }
        int res = INT_MAX;
        if (price >= 2)
        {
            res = min(coin(price - 2) + 1, res);
        }
        if (price >= 5)
        {
            res = min(coin(price - 5) + 1, res);
        }
        if (price>=7)
        {
            res = min(coin(price - 7) + 1, res);
        }
        return res;
    }