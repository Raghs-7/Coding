#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> grid[i][j];
            }
        }


        ll res = 0;
        for( int i = 0; i<m; i++){
            vector<int> temp(n,0);
            for (int j=0; j<n; j++){
                temp[j] = grid[j][i];
            }
            
            sort(temp.begin(), temp.end());
            reverse(temp.begin(), temp.end());


            for(int i=0; i<n; i++){
                res += (n-2*i-1)*1LL*(temp[i]);
            }

        }
        
        cout << res << endl;
    }


    return 0;
}