#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<vector<int>> &adj, vector<vector<int>> &dp, int v, int parent, ll &ans, int k){
    dp[v][0] = 1;

    for (int child : adj[v]){
        if (child==parent) {
            continue;
        }
        dfs(adj, dp, child, v, ans, k);

        for (int i=0; i<k; i++){
            ans += (ll)dp[v][i]*dp[child][k-i-1];
        }

        for (int i=0; i<k; i++){
            dp[v][i+1] += dp[child][i];
        }
    }
}

int main(){

    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n, vector<int>());

    for (int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    // choosing 1 as a root node

    vector<vector<int>> dp(n, vector<int>(k+1, 0));

    ll ans = 0;
    dfs(adj, dp, 0, -1, ans, k);


    cout << ans << endl;
    return 0;
}