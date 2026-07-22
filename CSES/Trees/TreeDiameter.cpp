#include<bits/stdc++.h>
using namespace std; 
#define ll long long

ll height(vector<vector<int>> &adj, int curr, int parent, ll &res){
    
    ll first = 0;
    ll secound = 0;
    for (auto child : adj[curr]){
        if (child!=parent){
            int temp = height(adj, child, curr, res);
            if (temp > first) {
                secound = first;
                first = temp;
            } else if (temp > secound){
                secound = temp;
            }
        }
    }
    
    res = max(res, 1 + first + secound);
    return 1 + max(first, secound);
}


int main(){

    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    for (int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll res = 0;
    height(adj, 1, -1, res);

    cout << res-1 << endl;
    return 0;
}