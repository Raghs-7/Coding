#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, x;
    cin >> n >> x;

    vector<int> coins(n, 0);

    for (int i=0; i<n; i++){
        cin >> coins[i];
    }

    vector<int> dp(x+1, 1e9);

    dp[0] = 0;
    for (int i=1; i<=x; i++){
        for (int num : coins){
            if (i>=num) dp[i] = min(dp[i], 1+dp[i-num]);
        }
    }

    if (dp[x]==1e9) cout << -1 << endl;
    else cout<< dp[x] << endl;

    return 0;
}