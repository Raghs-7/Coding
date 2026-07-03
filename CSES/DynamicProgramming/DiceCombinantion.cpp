#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> coins = {1, 2, 3, 4, 5, 6};
    vector<int> dp(n+1, 0);

    const int M = 1e9 + 7;
    dp[0] = 1;
    for (int i=1; i<=n; i++){
        for (int num : coins){
            if (i >= num){
                dp[i] += dp[i-num];
                dp[i] %= M;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}