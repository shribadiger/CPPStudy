/*
 * Split the array into increasing the order and maintain the minimum length = 3 and more
 */
#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool isPossible(vector<int>& nums) {
   int size = nums.size(); 
   map<int,int> frequency, need;
   
   //iterating the complete array once
   for(auto i: nums) {
      //cout<<"\n Number: "<<i;
      frequency[i]++;
   }

   //lets itirate each elements from the input vectors
   for(int n : nums) {
     cout<<"\n Iterating element: "<<n;
     if(frequency[n] == 0) // element is not present in the list 
        continue; 
     if(need[n] > 0) {
        need[n]--; // its removed from the need if the element is added to possible array
        frequency[n]--;
        need[n+1]++;
     } 
     else if(frequency[n]>0 and frequency[n+1]>0 and frequency[n+2]>0) {
         //trying to create the possible list of minimum 3 elements
         frequency[n]--;
         frequency[n+1]--;
         frequency[n+2]--;
         //checking for next possible options 
         need[n+3]++;
     } else {
         return false;
     }
   }
   return true; // considered all the elements are splitted and in with order
 
}

int main() {
    std::vector<int> nums={1,2,3,4,5,6};
    if(isPossible(nums)) {
        cout<<"\n Test case 1 Passed";
    } else { cout<<"\n Test case 1 failed"; } 

    std::vector<int> nums1 = {1,2,3,4,4,5,5,6,6};
    if(isPossible(nums1)) { 
        cout<<"\n Test case 2 Passed";
    } else { cout<<"\n Test case 2 Failed"; }


    std::vector<int> nums2 = { 1,2,3,4,5,5};
    if(isPossible(nums2)) { 
        cout<<"\n Test case 3 Passed";
    } else { cout<<"\n Test case 3 Failed"; }

  } 
   
