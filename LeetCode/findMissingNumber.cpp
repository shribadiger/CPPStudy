/* Code to find the missing numbers from given range 0 to N */
#include<iostream>
#include<vector>
using namespace std;

int getMissingNumber(vector<int>& input){
    // first sort the numbers and match
    int i=0;
    int index=0;
    while(i<input.size()) {
       int pos = input[index];
       if(pos != index) {
          int temp = input[pos];
          input[pos]=input[index];
          input[index]=temp;
       }else {
          index++;
       }
       i++;
    }
    //checking the each position
    int position=0;
    for(int i=0; i<input.size();i++) {
        if(i!=input[i])
          return i;
    }
    
    return -1;
}
int main() {
    vector<int> input={0,2,1,4,6,3};
    cout<<getMissingNumber(input);
    return 0;
}
