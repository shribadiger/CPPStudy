/* code to merge the two sorted array */
#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArray(vector<int> A, vector<int> B)
{
    vector<int> result;
    int i = 0;
    int j = 0;
    for (; i < A.size() && j < B.size();)
    {
        cout << "\n Comapare: " << A[i] << " - " << B[j];
        if (A[i] <= B[j])
        {
            // first array has lesser value
            result.push_back(A[i]);
            i++;
        }
        else
        {
            result.push_back(B[j]);
            j++;
        }
    }
    // if the i index not reached to end
    while (i < A.size())
    {
        result.push_back(A[i]);
        i++;
    }
    while (j < B.size())
    {
        result.push_back(B[j]);
        j++;
    }
    return result;
}

// In the above solution, there is any unncessary check for limit conidtion, that need to be eliminated.
// in the interview, they will ask to remove the this extra checks that while loop added after the main check
// functionality is finished

vector<int> mergeOptimize(vector<int> A, vector<int> B)
{
    int i = 0;
    int j = 0;
    vector<int> result;                  // initilizing the both the elements
    while (i < A.size() || j < B.size()) // any one of the condition is statisfied, we still need to add the elements to result
    {
        if (j == B.size() || (i < A.size() && A[i] < B[j])) // let consider that j is reached at end, hence we need
        // to insert value from i
        // the second check in the if condition is to handle the ith bond check and comparision with B array
        {
            result.push_back(A[i++]); // add the element from A and increment the i index
        }
        else
        {
            result.push_back(B[j++]); // add the element from B and increment the j index
        }
    }
    return result;
}
int main()
{
    vector<int> A = {1, 2, 3, 4, 8};
    vector<int> B = {4, 5, 6, 9};
    vector<int> res = mergeSortedArray(A, B);
    for (auto val : res)
    {
        cout << "\t" << val;
    }
    cout << endl;
    vector<int> A1 = {1, 3, 5, 7, 8, 9, 11, 15};
    vector<int> B1 = {2, 4, 6, 8, 10, 12, 13, 14};
    vector<int> opRes = mergeOptimize(A1, B1);
    for (auto val : opRes)
    {
        cout << "\t" << val;
    }
    return 0;
}