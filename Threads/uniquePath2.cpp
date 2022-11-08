/* Program to find the unique path to reach to destination */
#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    // preparing the DP array hold the values
    int DP[rows][cols];
    bool flag = false; // obstacle found in the rows

    // Filling the first row
    for (int i = 0; i < cols; i++)
    {
        if (flag || obstacleGrid[0][i] == 1)
        {
            flag = true;
            DP[0][i] = 0;
            continue;
        }
        DP[0][i] = 1;
    }

    // Filling the first columns
    flag = false;
    for (int j = 1; j < rows; j++)
    {
        if (flag || obstacleGrid[j][0] == 1)
        {
            flag = true;
            DP[j][0] = 0;
            continue;
        }
        DP[j][0] = 1;
    }
    for (int i = 1; i < rows; ++i)
    {
        for (int j = 1; j < cols; ++j)
        {
            if (obstacleGrid[i][j] == 1)
                DP[i][j] = 0;
            else
                DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
        }
    }
    return DP[rows - 1][cols - 1];
}

int main()
{
    vector<vector<int>> obstacleGrid = {{1, 1, 1}, {1, 1, 1}, {0, 0, 0}};
    cout << "\n Number of Paths to reach : " << uniquePathsWithObstacles(obstacleGrid);
    return 0;
}