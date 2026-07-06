#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char> (n, '#'));

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }

    queue<pair<int, pair<int, string>>> q;
    q.push({0, 0, grid[0][0]});

    while(!q.empty()){

        int s = q.size(); 
        vector<pair<int, pair<int, string>>> level;

        for (int i=0; i<s; i++){
            auto it = q.top(); q.pop();
            int row = it.first;
            int colm = it.second.first;

            

        }

        string mini = level[0].second.second;
        for (auto it : level){
            mini = min(mini, it.second.second);
        }
        
    }

    return 0;
}