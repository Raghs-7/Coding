#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int M = 1e9+7;
int main(){

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char> (n, ""));

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){

        }
    }

    return 0;
}