#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q;
    cin >> n >> q;
 
    vector<vector<int>> up(n+1, vector<int>(18, 0));

    up[1][0] = 0;
    for (int i = 1; i < n; i++){
        cin >> up[i+1][0];
    }


    for (int j=1; j<18; j++){
        for (int i=1; i<=n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    for (int i=0; i<q; i++){
        int x, k;
        cin >> x >> k;

        int res = x;
        for (int j = 0; j < 18; j++) {
            if (k & (1 << j)) {
                res = up[res][j];
            }
        }
        
        if (res == 0) {
            cout << -1 << endl;
        } else {
            cout << res << endl;
        }
    }

    return 0;
}