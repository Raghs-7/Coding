#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int n, m;
    cin >> n >> m;
    
    const int M = 1e9 + 7;
    vector<int> arr(n, 0);

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(m, 0));

    if (arr[n-1]==0){
        for (int i=0; i<m; i++){
            dp[n-1][i] = 1;
        }
    } else {
        dp[n-1][arr[n-1]-1] = 1;
    }

    // dp[i][num] --> how many ways we can fill this idx i with num
    for (int i=n-2; i>=0; i--){
        if (arr[i]==0){
            for (int num=0; num<m; num++){
                for (int diff = -1; diff<=1; diff++){
                    int temp = num + diff;
                    if (temp>=0 && temp<m){
                        dp[i][num] += dp[i+1][temp];
                        dp[i][num] %= M;
                    }
                }
            }
        } else {
            // already filled
            ll temp = 0;
            int num = arr[i] - 1;

            for (int diff = -1; diff <= 1; diff++) {
                int nxt = num + diff;
                if (nxt >= 0 && nxt < m) {
                    temp = (temp + dp[i+1][nxt]) % M;
                }
            }

            dp[i][num] = temp; 
        }
    }

    int res = 0;
    for (int i=0; i<m; i++){
        res += dp[0][i];
        res %= M;
    }

    cout << res << endl;
    return 0;
}