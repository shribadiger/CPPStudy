/*
 implementation of palindrom check in recursion method
 */
#include <iostream>
using namespace std;
bool isPalindrome(string input)
{
    cout << "\n INPUT: " << input;
    // base condition - smallest value is empty string or single charector
    if (input == "" || input.length() == 1)
        return true;
    // smallest amount of work that can contribute to solving the problem
    if (input[0] == input[input.length() - 1])
    {
        cout << "\n comapre    " << input[0] << " - " << input[input.length() - 1];
        return isPalindrome(input.substr(1, input.length() - 2));
    }
    // if none of the cases matches -- return false
    return false;
}

int main()
{
    if (isPalindrome("abbbbbbcfccbbbbbba"))
    {
        cout << "\n Yes I am palindrome string";
    }
    return 0;
}