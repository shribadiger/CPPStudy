/* checking the code with sub array of 1's */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int numSub(string input) {
   int length = input.length();
   int counter = 0;
   int result=0;
   for(int i=0; i<length;i++) {
      if(input[i]=='0') {
         //counter need to stop and calculate the result
         if(counter>1) {
             int res=(counter*(counter-1))/2;
             result=result+res;
             counter=0;
             
         }else {
             result=result+counter;
             counter=0;
         }
      }
      counter++;
   }
   if(counter>0) {
     int res=(counter*(counter-1))/2;
     result=result+res;
     counter=0;
   }
   return result;
}
int main() {
   std::string input = "0110111";
   cout<<"\n Number of Possible 1's : "<<numSub(input);
   std::string input1 = "101";
   cout<<"\n Number of Possible 1's : "<<numSub(input1);
   return 0;
}
