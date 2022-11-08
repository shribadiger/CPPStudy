#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>& nums) {
    int sizeOfNums = nums.size();
    bool isRemainingNumbers = true;
    // If number of inputs are less than 3
    if(sizeOfNums<3) {
        return false;
    }
    int initialNumber = nums[0];
    int breakPoint = 0;
    
    while(isRemainingNumbers != false && breakPoint <sizeOfNums) {
        for(int i=1;i<sizeOfNums;i++) {
            if(nums[i-1]<nums[i] || nums[i-1]==INT_MAX){
                nums[i-1]=INT_MAX;
                continue;
            }else {
               isRemainingNumbers = false;
            } 
        }
        breakPoint++;     
    }
   
    return isRemainingNumbers;
}

int main() {
    std::vector<int> nums = { 1,2,3,4,4,5,5,6,6,7};
    if(isPossible(nums)) {
        cout<<"\n SUCCESS\n";
    } else {
        cout<<"\n FAILURE\n";
    }
   return 0;
}
