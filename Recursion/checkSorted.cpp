/* checking the given array is sorted or not*/
#include <iostream>
#include <vector>
using namespace std;

bool helper(vector<int> input, int index)
{
    if (index == input.size() - 1)
        return true;

    return (input[index] <= input[index + 1] && helper(input, index + 1));
}
bool isSorted(vector<int> input)
{
    return helper(input, 0 /* begin Index*/);
}

int main()
{
    vector<int> input = {1, 2, 3, 6, 5};
    if (isSorted(input))
    {
        cout << "\n Sorted Array";
    }
    else
    {
        cout << "\n Not sorted Array";
    }
    return 0;
}