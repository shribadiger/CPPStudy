/* checking the array of elements which start from 1 to N */
#include<iostream>
#include<vector>
using namespace std;
void cyclicSort(vector<int>& input) {
    
    //checking the index of each numbers with each index
    int index=0;
    for(int i=0; i<input.size(); i++) {
       int pos = input[index]-1;
       if(pos != index) {
           //swap to position
           int temp = input[pos];
           input[pos]=input[index];
           input[index]=temp;
           continue;
       }
       index++;
    }
}


int main() {
    vector<int> input = {3,2,5,1,4};
    cyclicSort(input);
    for(auto val: input) {
        cout<<"\t"<<val;
    }
    return 0;
}
