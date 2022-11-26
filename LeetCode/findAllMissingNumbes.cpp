/* Finding all missing numbers from 1 to N */
#include<iostream>
#include<vector>
using namespace std;
vector<int> getMissingNumbers(vector<int>& input) {
   int index=0;
   for(int i=0; i<input.size(); i++) {
      int pos=input[index]-1;
      if(pos != index) {
        int temp = input[pos];
        input[pos]=input[index];
        input[index]=temp;
        continue;
      }
      index++;
   }
   
   vector<int> result;
   for(int i=0; i<input.size(); i++) {
      if(i+1 != input[i])  {
         result.push_back(i+1);
      }
   }

   return result;
}
int main() {
   vector<int> input = { 1,2,2,4,3,6};
   vector<int> missingNumbers = getMissingNumbers(input);
   for(auto val: missingNumbers) {
       cout<<"\t"<<val;
   }
   return 0;
}
