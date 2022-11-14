/* 
Leetcode problem: number of weak charector to check and update the couunt
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
static bool columnSort(vector<int> v1, vector<int> v2) {
    return (v1[0]==v2[0]?v1[0]>v2[0]:v1[0]<v2[0]);
}
int numberOfWeakCharecters(vector<vector<int>>& properties) {
    int answer = 0;
    int difference = 0;
    int length = properties.size();

    std::sort(properties.begin(), properties.end(),columnSort);

    for(int i=length-2;i>=0;i--){
        if(properties[i][1]<difference){
            answer++;
        } else {
            difference = properties[i][1];
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> input = { {5, 5 }, { 6, 3 }, {3, 6 }};
    cout<<"\n Result: "<<numberOfWeakCharecters(input);
    return 0;
}