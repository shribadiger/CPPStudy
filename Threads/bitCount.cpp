/*
 vector to represent the bit counts
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n)
{
    vector<int> bitCounts;
    bitCounts.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        int num = i;
        // repeating the checks until reach to 0
        while (num != 0)
        {
            sum = sum + num % 2;
            num = num / 2;
        }
        bitCounts.push_back(sum);
    }
    return bitCounts;
}

int main()
{
    // testing the functions
    vector<int> res = countBits(5);
    for (int i = 0; i < res.size(); i++)
    {
        cout << "\t" << res[i];
    }
    return 0;
}