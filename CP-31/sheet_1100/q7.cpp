#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll water(vector<int> &arr, ll h, vector<ll> &prefix){
    ll low = 0;
    ll high = arr.size()-1;

    ll res = 0;
    while(low <= high){
        ll mid = low + (high-low)/2;

        if (arr[mid] <= h){
            res = mid;
            low = mid + 1;
        } else {
            high = mid-1;
        }
    }

    return (res+1)*h - prefix[res];
}

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> arr(n, 0);


        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        vector<ll> prefix(n, arr[0]);
        for (int i=1; i<n; i++){
            prefix[i] = arr[i] + prefix[i-1];
        }

        ll low = 0;
        ll high = arr.back();
        while(true){
            ll waterNeed = water(arr, high, prefix);
            if (waterNeed>x){
                break;
            }
            high = high << 1;
        }

        int res = 0;
        while(low <= high){
            
            ll mid = low + (high-low)/2;
            ll waterNeed = water(arr, mid, prefix);

            if (waterNeed <= x){
                res = mid;
                low = mid + 1;
            } else {
                high = mid-1;
            }
        }

        cout << res << endl;
    }

    return 0;
}