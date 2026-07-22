#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int curr, vector<vector<int>> &adj, vector<ll>& dp){

    ll res = 0;
    for (int child : adj[curr]){
        solve(child, adj, dp);
        res += 1 + dp[child];
    }
    dp[curr] = res;
}

int main(){
    
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    for (int i=1; i<n; i++){
        int temp;
        cin >> temp;
        adj[temp-1].push_back(i);
    }
    
    vector<ll> dp(n);
    
    solve(0, adj, dp);

    for (auto num : dp){
        cout << num << " ";
    }
    cout << endl;
}