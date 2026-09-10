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
    vector<int> depth(n+1, 0);
    depth[1] = 0;
    for (int i = 2; i <= n; i++){
        cin >> up[i][0];
        depth[i] = 1 + depth[up[i][0]];
    }

    for (int j=1; j<18; j++){
        for (int i=1; i<=n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;

        if (depth[a] < depth[b]){
            swap(a,b);
        } 

        int jump = depth[a]-depth[b];
        for (int i=0; i<18; i++){
            if (jump & (1<<i)){
                a = up[a][i];
            }
        }

        if (a==b) {
            cout << a << endl;
            continue;
        }

        for (int j=17; j>=0; j--){
            if (up[a][j]!=up[b][j]){
                a = up[a][j];
                b = up[b][j];
            }
        }
        cout << up[a][0] << endl;
    }

    return 0;
}