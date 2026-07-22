#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll height(vector<vector<int>> &adj, int curr, int par, vector<ll> &dp) {
    ll maxi = 0;
 
    for (auto child : adj[curr]) {
        if (child != par) {
            maxi = max(maxi, height(adj, child, curr, dp));
        }
    }
 
    dp[curr] = maxi + 1;
    return dp[curr];
}
 
void solve(vector<vector<int>> &adj, int curr, int par, ll up,
           vector<ll> &dp, vector<ll> &res) {
 
    ll mx1 = 0, mx2 = 0;
 
    for (auto child : adj[curr]) {
        if (child != par) {
            ll temp = dp[child];
 
            if (temp > mx1) {
                swap(mx1, mx2);
                swap(mx1, temp);
            } else if (temp > mx2) {
                swap(temp, mx2);
            }
        }
    }
 
    res[curr] = max(up + 1, dp[curr]);
 
    for (auto child : adj[curr]) {
        if (child != par) {
            if (dp[child] == mx1) {
                solve(adj, child, curr, max(up + 1, mx2 + 1), dp, res);
            } else {
                solve(adj, child, curr, max(up + 1, mx1 + 1), dp, res);
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    vector<vector<int>> adj(n + 1);
 
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    vector<ll> dp(n + 1);
    vector<ll> res(n + 1);
 
    height(adj, 1, -1, dp);
    solve(adj, 1, -1, 0, dp, res);
 
    for (int i = 1; i <= n; i++) {
        cout << res[i] - 1 << " ";
    }
    cout << '\n';
 
    return 0;
