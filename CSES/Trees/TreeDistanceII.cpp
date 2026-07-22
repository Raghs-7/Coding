#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll count(vector<vector<int>> &adj, int curr, int par, vector<ll> &subNodes){
    ll cnt = 1;
    for (auto child : adj[curr]){
        if (child != par){
            cnt += count(adj, child, curr, subNodes);
        }
    }
 
    subNodes[curr] = cnt;
    return subNodes[curr];
}
 
ll subcounts(vector<vector<int>> &adj, int curr, int par,
             vector<ll> &cnt, vector<ll> &res){
 
    ll sum = 0;
 
    for (auto child : adj[curr]){
        if (child != par){
            sum += cnt[child] + subcounts(adj, child, curr, cnt, res);
        }
    }
 
    res[curr] = sum;
    return res[curr];
}
 
void solve(vector<vector<int>> &adj, int curr, int par,
           vector<ll> &cnt, vector<ll> &res){
 
    int n = adj.size() - 1;
 
    res[curr] = res[par] + n - 2 * cnt[curr];
 
    for (auto child : adj[curr]){
        if (child != par){
            solve(adj, child, curr, cnt, res);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    vector<vector<int>> adj(n + 1);
 
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    vector<ll> subNodes(n + 1);
    vector<ll> dp(n + 1);
 
    count(adj, 1, -1, subNodes);
    subcounts(adj, 1, -1, subNodes, dp);
 
    for (auto child : adj[1]){
        solve(adj, child, 1, subNodes, dp);
    }
 
    for (int i = 1; i <= n; i++){
        cout << dp[i] << " ";
    }
    cout << '\n';
 
    return 0;
}