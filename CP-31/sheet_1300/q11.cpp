#include <bits/stdc++.h>
using namespace std;

int dfs(int u, vector<vector<int>>& adj, string& s, int& ans) {
    int balance = (s[u - 1] == 'W' ? 1 : -1);

    for (int child : adj[u]) {
        balance += dfs(child, adj, s, ans);
    }

    if (balance == 0) ans++;

    return balance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);

        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            adj[p].push_back(i);
        }

        string s;
        cin >> s;

        int ans = 0;

        dfs(1, adj, s, ans);

        cout << ans << '\n';
    }

    return 0;
}