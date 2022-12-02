/* code to check for the rotated binary search in the given array*/

#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int> input, int target, int start, int end)
{
    // cout << "\n Start:" << start;
    // cout << "\n End:" << end;
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    // cout << "\n Mid:" << mid;
    //  return 0;

    if (input[mid] == target)
        return mid;                 // found the element
    if (input[start] <= input[mid]) // it indicate the first section of given array is sorted
    {
        if (target >= input[start] && target <= input[mid])
        {
            // element is in the range
            // cout << "\n Calling from sorted range helper(" << start << "," << mid - 1 << ")" << endl;
            return helper(input, target, start, mid - 1);
        }
        else
        {
            return helper(input, target, mid + 1, end);
        }
    }

    // This case for second half values which is not sorted
    if (target >= input[mid] && target <= input[end])
    {
        // cout << "\n helper(" << mid + 1 << "," << end << ")"
        //<< "\n";
        return helper(input, target, mid + 1, end);
    }
    cout << "\n calling here";
    return helper(input, target, start, mid - 1);
}
int search(vector<int> input, int target)
{
    return helper(input, target, 0, input.size() - 1);
}
int main()
{
    vector<int> input = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    cout << search(input, 4);
    return 0;
}