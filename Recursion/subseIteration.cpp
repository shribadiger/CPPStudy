/* Truying the nubers subset by iterations*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsetIteration(vector<int> input)
{
    vector<vector<int>> result;
    // case 1:I will always have an empty list first case
    result.push_back({}); // empty list insertion

    // case 2: every number in the given array, I need to take size and add to vector each number
    for (int num : input)
    {
        int n = result.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> internal = result[i];
            internal.push_back(num);
            result.push_back(internal);
        }
    }

    return result;
}

int main()
{
    vector<int> input = {1, 2, 3};
    vector<vector<int>> result = subsetIteration(input);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << "\t" << result[i][j];
        }
        cout << "\n";
    }
}