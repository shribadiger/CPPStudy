/*
 Inserting the vector in between the array
 */
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> newInterval)
{
    vector<vector<int>> result;
    int newIntervalBegin = newInterval[0];
    int newIntervalEnd = newInterval[1];
    bool isFound = false;
    int i = 0;
    int j = 0;
    for (i = 0; i < intervals.size(); i++)
    {
        if (intervals[i][1] >= newIntervalBegin)
        {
            // checking the intervals
            int lastDigit = (newInterval[1] - newInterval[0]) + newInterval[1];
            for (j = i; j < intervals.size(); j++)
            {
                cout << "\n Last Digit: " << lastDigit;
                if (intervals[j][0] == lastDigit)
                {
                    isFound = true;
                    break;
                }
                continue;
            }
        }
        else
        {
            result.push_back(intervals[i]);
        }
        if (isFound)
        {
            isFound = false;
            vector<int> newValue;
            newValue.push_back(intervals[i][0]);
            newValue.push_back(newInterval[1]);
            result.push_back(newValue);
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> input = {{1, 3}, {6, 9}};
    vector<int> interval = {2, 5};
    vector<vector<int>> result = insert(input, interval);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "\t{" << result[i][0] << "," << result[i][1] << "}";
    }
    return 0;
}