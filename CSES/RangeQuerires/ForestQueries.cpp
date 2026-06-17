#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, q;
    cin >> n >> q;

    vector<vector<int>> grid(n, vector<int>(n, 0));

    string s;
    cin >> s;
    if (s[0]=='*') {
        grid[0][0] = 1;
    }
    for (int i=1; i<n; i++){
        if (s[i]=='*'){
            grid[0][i] = 1 + grid[0][i-1];
        } else {
            grid[0][i] = grid[0][i-1];
        }
    }

    for (int i=1; i<n; i++){
        cin >> s;
        
        if (s[0]=='*'){
            grid[i][0] = 1 ;
        } 
        for (int j=1; j<n; j++){
            if (s[j]=='*'){
                grid[i][j] = 1 + grid[i][j-1];
            } else {
                grid[i][j] = grid[i][j-1];
            }
        }
        
        for ( int j=0; j<n; j++){
            grid[i][j] += grid[i-1][j];
        }
    }


    long long res = 0;
    for (int i=0 ;i<q; i++){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        pair<int, int> mini = {min(x1, x2), min(y1, y2)};
        pair<int, int> maxi = {max(x1, x2), max(y1, y2)};

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        res = grid[y2-1][x2-1];
        // - grid[y2-1][x1-2] - grid[y1-2][x2-1]
        if (x1>1) res -= grid[y2-1][x1-2];
        if (y1>1) res -= grid[y1-2][x2-1];
        if (x1>1 && y1>1) res += grid[y1-2][x1-2];
        cout << res << endl;
    }
    return 0;
}