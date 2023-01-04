/* code to find the minimum of the given input array */
#include <iostream>
#include <vector>
using namespace std;

int minimumSize(vector<int> input, int maxOp)
{
    std::sort(input.begin(), input.end()); // sorting the array 2 2 4 8
    std::vector<int> temp;
    temp.push_back(input[0]);
    while (maxOp > 0)
    {
        for (int i = 1; i < input.size(); i++)
        {
            if (input[i] > temp[i - 1])
            {
                // devide the number
                int val = input[i];
                temp.push_back(input[i] - input[i])
            }
        }
        maxOp--;
    }
}
int main()
{
    vector<int> input = {2,
                         4,
                         8,
                         2};
    int maxOperation = 4;
    cout << "\n Result: " << minimumSize(input, maxOperation);
}