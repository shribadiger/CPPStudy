/* its a program to identify the course can be finished or not */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isPossibleToFinish(int numOfCourses, vector<vector<int>> input)
{
    bool isPossible = false; // initial assignment of result
    if (input.size() == 1)
        return true;

    std::map<int, int> dependency;
    for (int i = 0; i < input.size(); i++)
    {
        cout << "\n Course " << input[i][0] << " depends on " << input[i][1];
        dependency[input[i][i]]++;
    }
    return isPossible;
}
int main()
{
    vector<vector<int>> input = {{0, 1}, {1, 0}};
    int numOfCourses = 2;
    if (isPossibleToFinish(numOfCourses, input))
    {
        cout << "\n True\n";
    }
    else
    {
        cout << "\n False \n";
    }
    return 0;
}
