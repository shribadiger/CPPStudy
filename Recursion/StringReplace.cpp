/* Code to replace the char 'a' from the given string only with recurrsion */
#include<iostream>
#include<string>
using namespace std;

void replaceA(string input,int index, string& result){

   if(index==input.length())
	return;
   if(input[index]=='a') {
      index++;
   } else {
      result=result+input[index];
      index++;
   }
   replaceA(input,index,result);
}
int main() {
   std::string input="abbcaabb";
   string result;
   replaceA(input,0,result);
   assert(result=="bbcbb");
   return 0;
}
