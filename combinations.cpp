/* finding the combination of the given input numbers */
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> result;
void combination_util(vector<int> nums, vector<int> comb, int k, int index) {
    // if the input is having the k numbers, then add it to result
    if(comb.size() == k)
    {
        result.push_back(comb);
        return;
    }

    // iterate the each elements form the range and add it for tracking
    for(int i=index;  i< nums.size(); i++) {
        comb.push_back(nums[i]);
        combination_util(nums, comb,k,i+1);
        comb.pop_back();
    }

}
vector<vector<int>> combinations(int n, int k) 
{
    // case 1: if both n and k are equal - then return input range
    if(k>=n) {
        return result; // returning the empty result
    }
    //case 2: if the range is not equal and less 
    std::vector<int> visitor;
    std::vector<int> nums;
    for(int i=1; i<=n; i++){
        nums.push_back(i);
    }
    combination_util(nums,visitor,k,0);
    return result;
}

int main() {
    vector<vector<int>> result = combinations(5,3);
    for(int i=0;i<result.size();i++) {
        for(auto val:result[i]) {
            cout<<"\t"<<val;
        }
        cout<<"\n";
    }
    return 0;
}