#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    // sorting each rows
    int sum = 0;
    for (int i = 0; i < triangle.size(); i++)
    {
        std::sort(triangle[i].begin(), triangle[i].end());
        sum = sum + triangle[i][0];
    }
    return sum;
}
int main()
{
    vector<vector<int>> input = {{2},
                                 {3, 4},
                                 {6, 5, 7},
                                 {4, 1, 8, 3}};
    cout << "\n Sum : " << minimumTotal(input);
    return 0;
}