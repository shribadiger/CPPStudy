/*
Finding the minimum fuel required to fill the vehicle to reach the target
Leet code daily challenge 
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int count = 0; // assuming no refil of fuel required initially
    
    //condition 1 - if the target and starting fuel is same
    /*if(target == startFuel) { 
        return count;
    }

    int n = stations.size();
    vector<int> dp(n+1);
    dp[0]=startFuel;

    for(int i=0;i<n; i++) {
        for(int refill =i;refill>=0 && dp[refill]>=stations[i][0];refill--){
            dp[refill+1]=std::max(dp[refill+1],dp[refill]+stations[i][1]);
        }
    }

    for(int i=0;i<=n;i++){
        if(dp[i]>=target){
            return i;
        }
    }

    return -1;*/

    //implementation of algorith with priority queue
    std::priority_queue<int> pq;
    int refil = 0;
    int i = 0; //starting position
    int distance = startFuel;
    while(distance <target){
        while(i<stations.size() && distance>=stations[i][0]){
            pq.push(stations[i][0]);
            i++;
        }
    }


}


int  main() {
    vector<vector<int>> stations = { { 10, 60 }, {20, 30}, {30, 30 }, { 60, 40 } };
    int target = 100;
    int startFuel = 10;
    cout << "\n Result: " << minRefuelStops(target,startFuel,stations);
    return 0;
}