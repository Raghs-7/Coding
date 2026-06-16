#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, c;
        cin >> n >> c;
        
        vector<ll> arr(n, 0);

        for (int i=0; i<n; i++){
            ll temp;
            cin >> temp;

            arr[i] = (i+1) + temp;
        }

        sort(arr.begin(), arr.end());

        

        int idx = 0;
        
        ll res = 0;
        while(idx<n && arr[idx]<=c){
            res++;
            c -= arr[idx];
            idx++;
        }

        cout << res << endl;
    }
}