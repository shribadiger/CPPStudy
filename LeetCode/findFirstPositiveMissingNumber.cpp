/* Given an array with numbers and findthe smallest positive missing number */
#include<iostream>
#include<vector>
using namespace std;

int getSmallestMissingNumber(vector<int>& input)  {
   int index=0;
   for(int i=0; i<input.size(); i++) {
     int pos = input[index]-1;
     if(pos>=0 && pos != index) {
       int temp = input[pos];
       input[pos]=input[index];
       input[index]=temp;
       continue;
     }
     index++;
   }

   //checking the first missig number
   for(int i=0; i<input.size(); i++) {
       if(input[i] != i+1) {
          return i+1;
       }
   }
   return -1;
}


int main() {
   vector<int> input = { -1,1,2,4};
   cout<<"\n Number = "<<getSmallestMissingNumber(input);
   return 0;
}
