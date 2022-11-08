/* How to solve the problem of Dynamically Sliding window issue
   Here, The problem is to find the sub array which sum should be greater than the 
   given value but it should have minimum length */

#include<iostream>
#include<vector>
using namespace std;

int minSubArrayLength(vector<int> input, int minSum) {
    int minLength = INT_MAX; // setting the max length possible

    int start = 0;
    int end = 0;
    int currSum = 0;

    //extending the each element until reach to end of the list
    while(end<input.size()) {
      currSum+=input[end];
      end=end+1;
      
      //contract the array untill reaches our condition
      while(start<end && currSum>= minSum) {
         currSum=currSum-input[start];
         start=start+1;
         minLength = std::min(minLength,end-start+1);
      }
    }
    

    return minLength;
}

int main() {
    vector<int> input = { 1,2,3,4,5,6};
    int minSum = 7;
    cout<<"\n Result : "<<minSubArrayLength(input,minSum)<<endl;
    vector<int> input1 = { 1,2,3,4,5,6,9,10,11,13,14,15,5,4,1,1,5};
    int minSum1 = 27;
    cout<<"\n Result : "<<minSubArrayLength(input1,minSum1)<<endl;
    return 0;
}
