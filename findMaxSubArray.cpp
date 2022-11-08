/* Program to find the maxmum subarray length */
#include<iostream>
#include<vector>
using namespace std;


int findLength(vector<int>& num1, vector<int>& num2) {
    int maxLength = 0;
    int currMaxLength = 0;
    for(int i=0; i<num1.size();i++){
        int itr=i;
        for(int j=0; j<num2.size();j++) {
            if(num1[itr]==num2[j]) {
                 itr++;
                 currMaxLength++;
                 continue;
            }
            if(currMaxLength>maxLength){
                maxLength=currMaxLength;
            }
            currMaxLength=0;
        }
    }
    return maxLength;
}

int main() {
    vector<int> input1={3,2,1,1,2};
    vector<int> input2={1,2,3,2,1};

    cout<<"\n Max Length : "<<findLength(input1, input2);
    return 0;
}