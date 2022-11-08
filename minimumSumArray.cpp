/*
 * code to check the minimum sub array
 */
#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int result = INT_MAX;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
    }
    if (target > sum)
    {
        return 0;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int counter = 0;
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum = sum + nums[j];
            counter++;
            if (sum == target)
            {
                if (counter < result)
                    result = counter;
                break;
            }
        }
    }
    if (result == INT_MAX)
        return 0;
    return result;
}

int main()
{
    std::vector<int> input = {2,
                              3,
                              1,
                              2,
                              4,
                              3};
    cout << "\n Minimum Sub Array Length: " << minSubArrayLen(7, input);
    return 0;
}