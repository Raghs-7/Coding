#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){

    int n, m;
    cin >> n >> m;
    
    vector<int> a(n, 0), b(m, 0);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<m; i++){
        cin >> b[i];
    }

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for (int i=0; i<=n; i++){
        dp[i][0] = 0;
    }
    for (int j=0; j<=m; j++){
        dp[0][j] = 0;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }


    cout << dp[n][m] << endl;
    vector<int> res;

    int i = n, j= m;
    while(i!=0 && j!=0){
        if (a[i-1]!=b[j-1]){
            if (dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        } else {
            res.push_back(a[i-1]);
            i--; j--;
        }
    }


    for (int i=res.size()-1; i>=0; i--){
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}