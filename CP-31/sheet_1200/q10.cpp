#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int binarySearch(vector<ll> &arr, ll k){

    int low = 0;
    int high = arr.size()-1;
    int res = 0;
    while(low <= high){
        int mid = low + (high-low)/2;
        if (arr[mid]<=k){
            res = mid;
            low = mid + 1;
        } else {
            high = mid-1;
        }
    }

    return res;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, q;
        cin >> n >> q;


        vector<ll> arr(n);
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        ll maxi = arr[0];
        vector<ll> pref(n);
        pref[0] = arr[0];
        for (int i=1; i<n; i++){
            pref[i] = arr[i] + pref[i-1];
            maxi = max(maxi, arr[i]);
            arr[i] = maxi;
        }

        while (q--){
            ll k;
            cin >> k;

            if (k < arr[0]){
                cout << 0 << " ";
            } else {
                int idx = binarySearch(arr, k);
                cout << pref[idx] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}