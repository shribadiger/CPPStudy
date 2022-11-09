/*
 Finding the longest sub string from the string
*/

// Idea is to use the sliding window and maintain the constant movement 


#include<iostream>
#include<vector>
#include<string>
using namespace std;
int getLongestNonDuplicateString(string str) {
    int len = str.length();
    vector<int> counter(256,0);
    int start = 0;
    int end = 0;
   
    //intializing for first char
    counter[str[0]-'A']++;
    int result = 1;

    while(end<len) {
        if(counter[str[end+1]-'A'] == 0) {
           end++;
           counter[str[end]-'A']=1;
           result = max(result,end-start+1);
        } else {
           counter[str[start]-'A']--;
           start++;
        }
    }
    return result;
}


// invoke of the function to calculate
int main() {
   string input = "abrexrzx";
   //string input = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWZYZ";
   cout<<"\n Result : "<<getLongestNonDuplicateString(input);
   return 0;
}
