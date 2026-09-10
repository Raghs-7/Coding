#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<vector<char>> grid(n, vector<char>(n, '0'));

        for (int i=0; i<n; i++){
            string s;
            cin >> s;
            for (int j=0; j<n; j++){
                grid[i][j] = s[j];
            }
        }

        int up = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;

        int res = 0;

        while (left < right){
            
            int i = left;
            int j = up;
            int n = right;
            int m = down;

            for ( ; i<right; i++, j++, n--, m--){

                int a = grid[up][i];
                int b = grid[j][right];
                int c = grid[down][n];
                int d = grid[m][left];
                
                if (sign == 0) res += 2;
                else if (sign > 0) res += 1;
                else res += 1;

            }   

            left++;
            right--;
            up++;
            down++;

        }
        
        cout << res << endl;
    }

    return 0;
}