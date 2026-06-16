#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int n = s.size();
        int lastzero = -1;
        int maxi = 0;
        int cnt = 0;
        for (int i = 0; i<n; i++){
            if (s[i]=='0'){
                lastzero = i;
                maxi = max(maxi, cnt);
                cnt = 0;
            } else {
                cnt++;
            }
        }
        maxi = max(maxi, cnt);
        cnt = 0;

        if (lastzero!=-1){
            int i = lastzero + 1;
            while(s[i]=='1'){
                i++;
                i = i%n;
                cnt++;
            }
            maxi = max(maxi, cnt);
        } else {
            ll res = 1LL * n * n;
            cout << res << endl;
            continue;
        }

        ll res = maxi;

        for (ll i=1; i<maxi; i++){
            res = max(res, (i+1)*(maxi-i));
        }

        cout << res << endl;
    }


    return 0;
}