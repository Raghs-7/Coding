#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int binarySearch(vector<pair<int, int>> &arr, ll x){
    int low = 0;
    int high = arr.size()-1;
    
    int res = -1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if (arr[mid].first<=x){
            res = low;
            low = mid + 1;
        } else {
            high = mid-1;
        }
    }

    return res;
}

int main(){

    int t;
    cin>> t;

    while(t--){
        int n, q;
        cin >> n >> q;

        vector<int> original(n, 0);
        vector<pair<int, int>> arr(n, {0, 0});
        vector<ll> height(n, 0);
        
        int temp;
        cin>>arr[0].first;
        height[0] = arr[0].first;
        original[0] = arr[0].first;

        for (int i=1; i<n; i++){
            cin>> temp;
            arr[i].first = temp;
            arr[i].second = i;
            height[i] = 1LL*temp + height[i-1];
        }

        sort(arr.begin(), arr.end());

        for (int i=0; i<q; i++){
            cin >> temp;

            int res = binarySearch(arr, temp);
            if (res==-1) {
                cout << 0 << " ";
            } else {
                while(original[res]>=temp){
                    res++;
                }
                int idx = arr[res].second;

                // cout << res << " " << idx << endl;
                cout << height[idx] << " ";
            }
        } cout << endl;
    }


    return 0;
}