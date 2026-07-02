#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int curr, int idx, vector<int> &cost, vector<int> &happiness, int x, map<pair<int, int>, int> &dp){
    
    int n = cost.size();
    if (idx>=n) return 0;
    if (dp.count({curr, idx})) return dp[{curr, idx}];

    int buy = 0;
    if (curr>=cost[idx]){
        buy = happiness[idx] + solve(curr-cost[idx]+x, idx+1, cost, happiness, x, dp);
    }
    int notbuy = solve(curr+x, idx+1, cost, happiness, x, dp);

    dp[{curr, idx}] = max(buy, notbuy);
    return dp[{curr, idx}];
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int m, x;
        cin >> m >> x;

        vector<int> cost(m, 0);
        vector<int> happiness(m, 0);

        for (int i=0; i<m; i++){
            cin >> cost[i] >> happiness[i];
        }
        
        map<pair<int, int>, int> dp;
        cout << solve(0, 0, cost, happiness, x, dp) << endl;

    }

    return 0;
}