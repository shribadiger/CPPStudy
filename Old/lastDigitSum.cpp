#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> plusOne(vector<int> &digits)
{
    stack<int> tempStack;
    vector<int> result;
    int carry=0;
    for (int i = digits.size()-1; i>=0; i--) {
        //adding the number to the last digit
        int result = digits[i]+1+carry;
        if(result>9){
            tempStack.push(0);
            carry=1;
        }
        else {
            tempStack.push(result);
            carry=0;
        }
    }
    if(carry==1) {
        tempStack.push(carry);
    }

    // pop all elements of stack
    while(!tempStack.empty()) {
        result.push_back(tempStack.top());
        tempStack.pop();
    }
    return result;
}

int main() {
    vector<int> input={9,9};
    vector<int> result = plusOne(input);
    for(int i=0;i<result.size();i++) {
        cout<<"\t"<<result[i];
    }
    return 0;
}