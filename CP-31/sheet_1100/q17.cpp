#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){


    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<vector<int>> grid(n, vector<int>(n, 0));

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cin >> grid[i][j];
            }
        }

        int low = 0;
        int high = n-1;

        ll cnt = 0;

        while(low<high){

            for (int i=0; i<n; i++){
                if (grid[i][low] != grid[n-i-1][high]){
                    cnt++;
                }
            }

            low++;
            high--;
        }

        if (low==high){
            int mid = (n+1)/2;
            for (int i=0; i<mid; i++){
                if (grid[i][low]!=grid[n-i-1][low]){
                    cnt++;
                }
            }
            
            if (cnt > k) cout << "NO" << endl;
            else cout << "YES" << endl;
        } else {
            if (cnt > k){
                cout << "NO" << endl;
                continue;
            }
            
            ll left = k-cnt;

            if (left%2) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        
    }
    return 0;
}