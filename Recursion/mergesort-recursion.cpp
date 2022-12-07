/* recursive way meerge sort*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int> input, int start, int end)
{
    if (start == end)
    {
        return input;
    }

    int mid = input.size() / 2;

    vector<int> left = mergeSort(input, start, mid);
    vector<int> right = mergeSort(input, mid + 1, end);

    merge(left, right, start, mid, end);
}

int main()
{
    vector<int> input = {6, 5, 4, 3, 2, 1};
    vector<int> result = mergeSort(input);
}