/* Finding the sum of array numbers */
#include <iostream>
#include <vector>
using namespace std;

void prepareResultSet(vector<int> &candidates,
                      int target,
                      int nextIndex,
                      vector<int> includedArray,
                      vector<vector<int>> result)

{
    if (target == 0)
    {
        // got actual sum so pushing the includedArray into result
        result.push_back(includedArray);
    }

    // if the target is in negetive range. it means, next index Values are not going to match to sum
    if (target < 0)
    {
        return;
    }

    int temp = -1;
    for (int i = nextIndex; i < candidates.size(); i++)
    {
        if (temp == candidates[i])
        {
            continue;
        }
        includedArray.push_back(candidates[i]);
        prepareResultSet(candidates, target - candidates[i], i, includedArray, result);
        temp = includedArray[includedArray.size() - 1]; // assign the inserted value to temp for next comparision
        includedArray.pop_back();                       // remove the element from included array
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> result;
    std::sort(candidates.begin(), candidates.end());
    vector<int> includedArray;
    prepareResultSet(candidates, target, -1, includedArray, result);
    /*for (int i = 0; i < candidates.size(); i++)
    {
        vector<int> includedArray;
        includedArray.push_back(candidates[i]);
        prepareResultSet(includedArray, target - candidates[i], i + 1, candidates, result, candidates.size());
    } */
    return result;
}

int main()
{
    // test code
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = combinationSum2(candidates, target);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << "\t" << result[i][j];
        }
        cout << endl;
    }
}