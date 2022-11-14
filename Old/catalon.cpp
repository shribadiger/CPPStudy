/*
 Finding the number of catalon
 */
#include <iostream>
#include <vector>
using namespace std;

int catalon_number(int num)
{
    // finding the catalon numbers
    unsigned long long int result = 0;
    if (num <= 1)
        return 1;
    for (int i = 0; i < num; i++)
    {
        result += catalon_number(i) * catalon_number(num - i - 1);
    }
    return result;
}

int catalon_number_dynamic(int number)
{
    // getting the number
    std::vector<int> DP(number + 1, 0); // initialize the vector to zeros
    DP[0] = DP[1] = 1;
    for (int i = 2; i <= number; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            DP[i] = 0;
            DP[i] = DP[i] + (DP[j] * DP[i - j - 1]);
        }
    }
    return DP[number];
}

int main()
{
    int number = 5;
    cout << "\n Number: " << catalon_number(number);
    cout << "\n Number : " << catalon_number_dynamic(number);
    return 0;
}