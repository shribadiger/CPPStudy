/* Code to print the subset of the given string*/
#include <iostream>
#include <string>
using namespace std;

void subSetOfString(string pattern, string input)
{
   if (input.length() == 0)
   {
      cout << pattern << "\n";
      return;
   }
   // cout << "\n :Log:" << input;
   char ch = input[0];
   subSetOfString(pattern + ch, input.substr(1));
   subSetOfString(pattern, input.substr(1));
}

int main()
{
   // checking the sub string api
   string input = "abc";
   subSetOfString("", input);
   return 0;
}