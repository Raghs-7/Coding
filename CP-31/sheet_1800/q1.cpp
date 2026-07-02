#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool winner(pair<int, int> a, pair<int, int> b, pair<int, int> c, vector<string> &s){
    return (((s[a.first][a.second]=='A') + (s[b.first][b.second]=='A') + (s[c.first][c.second]=='A')) >= 2 ) ? true : false;
}

int solve(int i, int j, map<pair<int, int>, int> &mpp, vector<string> &s){

    int n = s[0].size();

    if ( i>=n || j>=n ) return 0;
    if ( mpp.count({i, j})) return mpp[{i, j}];

    int option1 = (max(i+2, j+2)<n) ? winner({0, i}, {0, i+1}, {0, i+2}, s) + winner({1, j}, {1, j+1}, {1, j+2}, s) + solve(i+3, j+3, mpp, s): 0;
    int option2 = (i==j || i+1==j) ? winner({0,i}, {0, i+1}, {1, j}, s) + solve(i+2, j+1, mpp, s) : 0;
    int option3 = (i==j || i==j+1) ? winner({1,j},{1,j+1},{0,i}, s) + solve(i+1, j+2, mpp, s) : 0;

    mpp[{i, j}] = max({option1, option2, option3});
    return mpp[{i, j}];

}


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<string> s(2, "");
        cin >> s[0];
        cin >> s[1];

        vector<vector<int>> dp(n, vector<int>(3, 0));
        
        map<pair<int, int>, int> mpp;
        
        cout << solve(0, 0, mpp, s) << endl;
    }
    return 0;
}