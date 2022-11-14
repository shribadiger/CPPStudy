/*
Trapping Rain Water*/
#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& input) {
    int number_of_pillers = input.size();

    int result = 0;
    //predefine the left and right piller and water level
    vector<int> left(number_of_pillers,0); //left level from existed point
    vector<int> right(number_of_pillers,0); // right from the existed point

    for(int i=1;i<number_of_pillers; i++) {
        left[i]=max(left[i-1],input[i-1]);
    }

    for(int i=number_of_pillers-2; i>=0; i--){
        right[i]=max(right[i+1],input[i+1]);
    }

    for(int i=1;i<number_of_pillers-1;i++) {
        result=result+max(0,min(left[i],right[i])-input[i]);
    }
    return result;
}