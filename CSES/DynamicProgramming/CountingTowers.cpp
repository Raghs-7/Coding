#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){

    int t;
    cin >> t;

    const int M = 1e9 + 7;
    int n = 1e6+1;

    vector<vector<ll>> dp(n, vector<ll>(2, 0));

    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i=1; i<n; i++){
        dp[i][0] = 4 * dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0] + 2*dp[i-1][1];
        
        dp[i][0] %= M;
        dp[i][1] %= M;
    }

    while (t--){
        cin >> n;
        cout << (dp[n-1][0] + dp[n-1][1])%M << endl;
    }

    return 0;
}