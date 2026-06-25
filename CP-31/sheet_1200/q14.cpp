#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<vector<char>> grid(n, vector<char>(n, 'a'));

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cin >> grid[i][j];
            }
        }

        
    }



    return 0;
}