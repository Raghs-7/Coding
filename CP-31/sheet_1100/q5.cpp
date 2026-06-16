#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){

    int t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> arr(n, 0);

        ll sum = 0;
        for (int i=0; i<n; i++){
            int temp;
            cin >> temp;
            sum += temp;
            arr[i] = sum;
        }
        
        ll res = 0;
        for (ll k=1; k<n; k++){
            if (n%k) continue;
            ll start = k-1;
            ll maxi = arr[start];
            ll mini = arr[start];
            
            for (ll i = start+k; i<n; i++){
                ll curr = arr[i] - arr[i-k];
                maxi = max(maxi, curr);
                mini = min(mini, curr);
            }
            res = max(res, maxi-mini);
        }

        cout << res << endl;
    }


    return 0;
}