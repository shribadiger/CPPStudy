/*
 This is the program to illustrate to buy the shares
*/
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int result = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        int iterationResult = 0;
    }
}

int main()
{

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "\n Max Profit: " << maxProfit(prices);
    return 0;
}
