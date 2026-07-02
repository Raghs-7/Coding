#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

vector<vector<ll>> dijkstra(vector<vector<pair<int,int>>> &adj,vector<int> &horse, int start) {

    int n = adj.size();

    vector<vector<ll>> dis(n, vector<ll>(2, INF));

    priority_queue<pair<ll, pair<int,int>>, vector<pair<ll, pair<int,int>>>, greater<pair<ll, pair<int,int>>>> pq;

    int state = horse[start];

    dis[start][state] = 0;
    pq.push({0, {start, state}});

    while (!pq.empty()) {

        auto cur = pq.top();
        pq.pop();

        ll d = cur.first;
        int u = cur.second.first;
        int mounted = cur.second.second;

        if (d > dis[u][mounted])
            continue;

        for (auto [v, w] : adj[u]) {

            int newMounted = mounted || horse[v];

            ll cost = mounted ? w / 2 : w;

            if (dis[v][newMounted] > d + cost) {
                dis[v][newMounted] = d + cost;
                pq.push({dis[v][newMounted], {v, newMounted}});
            }
        }
    }

    return dis;
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m, h;
        cin >> n >> m >> h;

        vector<int> horse(n, 0);

        for (int i = 0; i < h; i++) {
            int x;
            cin >> x;
            horse[x - 1] = 1;
        }

        vector<vector<pair<int,int>>> adj(n);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        auto disA = dijkstra(adj, horse, 0);
        auto disB = dijkstra(adj, horse, n - 1);

        ll ans = INF;

        for (int i = 0; i < n; i++) {

            ll alice = min(disA[i][0], disA[i][1]);
            ll bob   = min(disB[i][0], disB[i][1]);

            if (alice == INF || bob == INF)
                continue;

            ans = min(ans, max(alice, bob));
        }

        if (ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}