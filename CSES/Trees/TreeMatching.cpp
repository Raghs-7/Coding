#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int solve(vector<vector<int>> &adj, int curr, vector<int> &dp){

    if (dp[curr]!=-1) return dp[curr];
    
    int sum = 0;
    
    for (auto child : adj[curr]){
        if (child!=curr){
            sum += solve(adj, child, dp);
        }
    }
    
    int res = sum;
    for (auto child : adj[curr]){
        if (child!=curr){
            int temp = 0;
            for (auto subchild : adj[child]){
                if (subchild!=child){
                    temp += solve(adj, subchild, dp);
                }
            }
            res = max(res, sum - solve(adj, child, dp) + 1 + temp);
        }
    }

    dp[curr] = res;

    return dp[curr];
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

    vector<int> dp(n+1);

    int res = 0;
    for (int i=1; i<=n; i++){
        if (dp[i]==-1){
            res += solve(adj, i, dp);
        }
    }

    cout << res << endl;
    return 0;
}