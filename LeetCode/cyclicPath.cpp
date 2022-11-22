/* Findging the cyclic path exist*/
#include <iostream>
#include <vector>
using namespace std;

bool isCyclePresentInGraph(vector<vector<int>> graph)
{
}

int main()
{
    // In the below graph, you can see the cycle
    vector<vector<int>> input = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}};
    if (isCyclePresentInGraph(input))
    {
        cout << "\n Its not a DAG";
    }
    else
    {
        cout << "\n Its a DAG";
    }
    return 0;
}