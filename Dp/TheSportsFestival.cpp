#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int n;
    cin>> n;
    vector<int> arr(n, -1);

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll diff = 0;

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    // dp[i][j] --> minimum from array i to j
    // dp[i][i] == 0
    // dp[i][i+1] = arr[i+1]-arr[i]

    // dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + arr[j]-arr[i];

    for (int i=1; i<n; i++){
        dp[i-1][i] = arr[i]-arr[i-1];
    }

    for (int j=1; j<n; j++){
        for (int i=j-1; i>=0; i--){
            dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + arr[j]-arr[i];
        }
    }

    cout << dp[0][n-1] << endl;

    return 0;
}