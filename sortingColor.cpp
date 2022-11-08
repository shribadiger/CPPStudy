#include <iostream>
#include <vector>
using namespace std;

void sortingVector(std::vector<int> &inputs)
{

    // let the consider the index from the begin and end of the inputs
    int low = 0;
    int mid = 0;
    int end = inputs.size() - 1;

    // let consider the 3 cases from here to check values
    while (mid <= end)
    {
        if (inputs[mid] == 0)
        {
            std::swap(inputs[low], inputs[mid]);
            low++;
            mid++;
        }
        else if (inputs[mid] == 1)
        {
            mid++;
        }
        else if (inputs[mid] == 2)
        {
            std::swap(inputs[mid], inputs[end]);
            end--;
        }
    }
}

int main()
{
    std::vector<int> inputs = {2, 1, 0, 2, 1, 0};
    sortingVector(inputs);
    for (int i = 0; i < inputs.size(); i++)
    {
        cout << "\t" << inputs[i];
    }
}