/*
 Leet code problem to generate the matrix
 */
#include <iostream>
#include <vector>
using namespace std;

void left_insert(int &left, int &right, int &limit, int &number, vector<vector<int>> &result)
{
    int counter = 0;

    while (counter < limit)
    {
        result[left][++right] = ++number;
        counter++;
    }
}
void down_insert(int &left, int &right, int &limit, int &number, vector<vector<int>> &result)
{
    int counter = 0;
    while (counter < limit)
    {
        result[++left][right] = ++number;
        counter++;
    }
}

void right_insert(int &left, int &right, int &limit, int &number, vector<vector<int>> &result)
{
    int counter = 0;
    while (counter < limit)
    {
        result[left][--right] = ++number;
        counter++;
    }
}
void up_insert(int &left, int &right, int &limit, int &number, vector<vector<int>> &result)
{
    int counter = 0;
    while (counter < limit)
    {
        result[--left][right] = ++number;
        counter++;
    }
}
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> result;
    // initialize the result response
    for (int i = 0; i < n; i++)
    {
        vector<int> row(n, 0);
        result.push_back(row);
    }

    // initializing the number to one before start
    int number = 0;
    int left = 0;
    int right = -1;
    int limit = n;
    while (number < (n * n))
    {

        left_insert(left, right, limit, number, result);
        limit--;
        down_insert(left, right, limit, number, result);
        right_insert(left, right, limit, number, result);
        limit--;
        up_insert(left, right, limit, number, result);
    }
    return result;
}

int main()
{
    vector<vector<int>> result = generateMatrix(5);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << "\t" << result[i][j];
        }
        cout << "\n";
    }

    vector<vector<int>> result1 = generateMatrix(3);
    for (int i = 0; i < result1.size(); i++)
    {
        for (int j = 0; j < result1[i].size(); j++)
        {
            cout << "\t" << result1[i][j];
        }
        cout << "\n";
    }
    return 0;
}