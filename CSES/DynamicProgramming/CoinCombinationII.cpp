#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int n, target; 
    cin >> n >> target;
    vector<int> coins(n, 0);

    for (int i=0; i<n; i++){
        cin >> coins[i];
    }

    vector<int> dp(target+1, 0);
    const int M = 1e9 + 7;

    dp[0] = 1;
    for (int val : coins){
        for (int i=val; i<=target; i++){
            dp[i] += dp[i-val];
            dp[i] %= M;
        }
    }

    cout << dp[target] << endl;
    return 0;
}