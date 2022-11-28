/* Binary search of the array */
#include<iostream>
#include<vector>
using namespace std;


bool isPresent(vector<int> input, int begin, int end, int num) {
    int mid = begin+(end-begin)/2;
    if(begin>end)
        return false;
    if(input[mid]==num)
       return true;
    if(input[mid]>num)
       return isPresent(input,begin,mid-1,num);
    else
       return isPresent(input,mid+1,end,num);
}
bool findNumber(vector<int> input, int num) {
    //finding the given number num in the vector
    return isPresent(input,0,input.size(),num);
}
int main() {
   vector<int> input = {1,2,3,4,5,6,7,8};
   if(findNumber(input,0)) {
       cout<<"\n Found";
    } else {
       cout<<"\n Not Found";
    }
    return 0;
}
