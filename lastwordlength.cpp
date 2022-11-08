/* Program to find the the last word length in the given string */
#include<iostream>
#include<string>
using namespace std;

int lengthOfLastWord(string input) {
    int length = input.length();
    int result = 0;
    int lastCharPosition = length-1;
    while(input[lastCharPosition] ==  ' '){
        lastCharPosition--;
    }
    for (int i = lastCharPosition; i >= 0; i--)
    {
        if(input[i] == ' ')
            break;
        result++;
    }
    return result;
}

int main() {
    string input ="shrikant badiger   ";
    cout<<"\n result : "<<lengthOfLastWord(input);
    return 0;
}