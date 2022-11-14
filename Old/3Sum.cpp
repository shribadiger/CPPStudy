/* Program to check about the 3 sum values from the array */
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
   
   //define the result array 
   vector<vector<int>> result;
   
   //base condition : empty input
   if(nums.size() == 0) return result;

   //step 1: sort the array to avoid the duplicate tuples
   std::sort(nums.begin(), nums.end());

   //finding the x value and assign it from array
   int x = nums[0];
   int y=0,z=0;
   int iterator = 0;
   int i,j;
   while(iterator < nums.size()-3) {
      x=nums[iterator];
      cout<<"\n Starting from : "<<x<<" -- index:"<<iterator;
      for(int i=iterator+1; i<nums.size(); i++) {
          y=nums[i];:
          for(int j=
      iterator++;
   }
   
   //returning the result after finishing the filling values
   return result;
}

int main() {
   /* preapre the list to call threeSum function */
   vector<int> input={-1,0,1,2,-1,-4};
   vector<vector<int>> result = threeSum(input);
   for(int i=0; i<result.size();i++) {
      for(int j=0;j<result[i].size();j++) {
          cout<<"\t"<<result[i][j];
      }
      cout<<"\n";
   }
   return 0;
}
   
