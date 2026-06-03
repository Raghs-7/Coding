#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long possibleWays(int x, int k){
    if (x<k) return 0;

    int n = x-k+1;

    return (long long)n*(n+1)/2;
}


int main(){

    int t;
    cin >> t;

    while( t-- ){
        int n, k, q;
        cin >> n >> k >> q;

        int cnt = 0;
        long long res = 0;
        for (int i=0; i<n; i++){
            int curr;
            cin >> curr;
            if (curr<=q) {
                cnt++;
            } else {
                res += possibleWays(cnt, k);
                cnt = 0;
            }
        }
        res += possibleWays(cnt, k);
        cout << res << endl;
    }

    return 0;
}