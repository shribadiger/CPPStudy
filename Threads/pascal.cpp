/* generating the pascal triangle*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;
    int count = 2;
    if (numRows == 0)
        return result;
    if (numRows == 1)
    {
        result.push_back({1});
        return result;
    }
    if (numRows == 2)
    {
        result.push_back({1});
        result.push_back({1, 1});
        return result;
    }
    // inserting first digit
    result.push_back({1});
    result.push_back({1, 1});
    while (count < numRows)
    {
        vector<int> row(count + 1, 0);
        row[0] = 1;
        row[count] = 1;
        for (int i = 1; i <= count - 1; i++)
        {
            cout << "\n"
                 << result[count - 1][i - 1] << "+" << result[count - 1][i];
            row[i] = result[count - 1][i - 1] + result[count - 1][i];
        }
        result.push_back(row);
        count++;
    }
    return result;
}
int main()
{
    // testing the functionality
    int num = 8;
    vector<vector<int>> res = generate(num);
    for (int i = 0; i < res.size(); i++)
    {
        for (auto val : res[i])
        {
            cout << "\t" << val;
        }
        cout << "\n";
    }
}