#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> books(n, pair<int, int>());

    for (int i=0; i<n; i++){
        cin >> books[i].first;
    }
    for (int i=0; i<n; i++){
        cin >> books[i].second;
    }

    sort(books.begin(), books.end());

    vector<vector<int>> dp(x+1, vector<int>(n+1, 0));

    for (int idx=n-1; idx>=0; idx--){
        for (int target=0; target<books[idx].first; target++){
            dp[target][idx] = dp[target][idx+1];
        }
        for (int target=books[idx].first; target<=x; target++){
            dp[target][idx] = max(dp[target][idx+1], books[idx].second + dp[target-books[idx].first][idx+1]);
        }
    }

    cout << dp[x][0] << endl;
 
    return 0;
}