/* Fib series of with concept of DP */
#include<iostream>
#include<vector>
using namespace std;

int fib(int n) {
    std::vector<int> DP(n+1,-1);
    if(n==0||n==1){
        DP[n]=n;
        return;
    }
    if(DP[n] == -1){
        DP[n] = DP[n - 1] + DP[n - 2];
        fib(n--)
    }
        


}