/* checking the functionality and understanding the code flow */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> ThreeSum(vector<int>& nums) {

   //declare the empty result vector list
   vector<vector<int>> result;
   //condition 1: checking the empty list and return empty result
   if(nums.size() < 3) {
      return {};
   }

   //sorting the input array
   std::sort(nums.begin(), nums.end());
  
   //checkign the first value after sorting the array
   if(nums[0] > 0) { 
       return {};
   }

   //iterating the complete loop
   for(int i=0; i<nums.size(); i++) {
      int low = i+1;
      int j = nums.size()-1;
      int sum = 0;
      
      if( i!=0 && nums[i] == nums[i-1]
   
       
