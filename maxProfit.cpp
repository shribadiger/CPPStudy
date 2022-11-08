/* Coding for greedy approach to solve stock issue*/
#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int result = 0;
    // buy and sell gives profit. so length-2 need to do

    for (int i = 0; i < prices.size() - 1; i++)
    {
        int sum = 0;
        for (int j = i; j < prices.size(); j = j + 2)
        {
            cout << "\n " << prices[j] << "-" << prices[j + 1];
            sum = sum + (prices[j] - prices[j + 1]);
        }
        if (sum > result)
            result = sum;
    }
    return result;
}

int main()
{
    vector<int> input = {7, 1, 5, 3, 6, 4};
    cout << "\n Result : " << maxProfit(input);
}