/* Program to add the number and store in vector*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    if (nums.size() < 3)
        return result;
    if (nums.size() == 3)
    {
        if (nums[0] + nums[1] + nums[2] == 0)
            result.push_back(nums);
        return result;
    }
    sort(nums.begin(), nums.end()); // sorting to avoid greater values

    for (int i = 0; i < nums.size() - 2; i++)
    {
        int remainingValue = (0 - nums[i]);
        for (int j = i + 1; j < nums.size() - 1 && remainingValue <= nums[j]; j++)
        {
            int lastNum = remainingValue - nums[j];
            for (int k = j + 1; k < nums.size() && lastNum <= nums[k]; k++)
            {
                if (lastNum == nums[k])
                {
                    vector<int> elements = {nums[i], nums[j], nums[k]};
                    result.push_back(elements);
                }
            }
        }
    }

    return result;
}
/*
vector<vector<int>> threeSum(vector<int> &nums)
{
    // resutl of the values
    set<vector<int>> result;
    vector<vector<int>> final_result;
    // first case:  if the given array has less than 3 values
    if (nums.size() < 3)
        return final_result;
    if (nums.size() == 3)
    {
        if (nums[0] + nums[1] + nums[2] == 0)
            final_result.push_back(nums);
        return final_result;
    }

    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> value = {nums[i], nums[j], nums[k]};
                    sort(value.begin(), value.end());
                    result.insert(value);
                }
            }
        }
    }
    // copy from set and assign to vector
    // vector<vector<int>> final_result;
    for (auto itr : result)
    {
        final_result.push_back(itr);
    }
    return final_result;
} */
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // Sorted Array
    if (nums.size() < 3)
    { // Base Case 1
        return {};
    }
    if (nums[0] > 0)
    { // Base Case 2
        return {};
    }
    unordered_map<int, int> hashMap;
    for (int i = 0; i < nums.size(); ++i)
    { // Hashing of Indices
        hashMap[nums[i]] = i;
    }
    vector<vector<int>> answer;
    for (int i = 0; i < nums.size() - 2; ++i)
    { // Traversing the array to fix the number.
        if (nums[i] > 0)
        { // If number fixed is +ve, stop there because we can't make it zero by searching after it.
            break;
        }
        for (int j = i + 1; j < nums.size() - 1; ++j)
        {                                            // Fixing another number after first number
            int required = -1 * (nums[i] + nums[j]); // To make sum 0, we would require the -ve sum of both fixed numbers.
            if (hashMap.count(required) && hashMap.find(required)->second > j)
            { // If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet.
                answer.push_back({nums[i], nums[j], required});
            }
            j = hashMap.find(nums[j])->second; // Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
        }
        i = hashMap.find(nums[i])->second; // Update i to last occurence of 1st fixed number to avoid duplicate triplets.
    }
    return answer; // Return answer vector.
}

int main()
{
    vector<int> input = {-1,
                         0,
                         1,
                         2,
                         -1,
                         -4};
    vector<vector<int>> result = threeSum(input);
    for (int i = 0; i < result.size(); i++)
    {
        for (auto itr : result[i])
        {
            cout << "\t" << itr;
        }
        cout << "\n";
    }
    return 0;
}