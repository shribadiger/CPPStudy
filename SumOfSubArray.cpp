/* Finding the sum of the sub array in given vector */
#include<iostream>
#include<vector>
using namespace std;

// Time Complexity of this approach - O(n*k) times
vector<int> getSumOfSubArray(vector<int> input, int subArrayLength)
{
   vector<int> result;
   for(int i=0; i<=(input.size()-subArrayLength);i++) {
     int sum = 0;
     for(int j=i;j<(i+subArrayLength);j++) {
         sum+=input[j];
     }
     result.push_back(sum);
   }
   return result;
}

// Trying to solve the problem by using the sliding window approach 
vector<int> getSumOfSubArray_SlidingWindow(vector<int> input, int subArrayLength) {
    vector<int> result;
    int slidingSum = 0;
    for(int i=0; i<subArrayLength;i++) {
      slidingSum+=input[i];
    }

    // inserting the first computed sum to result container
    result.push_back(slidingSum);
    for(int i=1; i<(input.size()-subArrayLength+1);i++) {
       slidingSum-=input[i-1];
       slidingSum+=input[i+subArrayLength-1];
       // pusing sum to result vector
       result.push_back(slidingSum);
    }

    return result;
}

int main() {
   vector<int> input = { 1,2,3,4,5,6};
   vector<int> result = getSumOfSubArray_SlidingWindow(input, 3/* sub array length*/);
   for(auto i: result) {
       cout<<"\t"<<i;
   }
   return 0;
}
