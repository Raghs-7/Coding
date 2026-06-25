#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n, 0);
        
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        ll maxi = -1e18;
        for (int i=0; i<n; i++){
            ll temp;
            cin >> temp;
            arr[i] -= temp;

            maxi = max(maxi, arr[i]);
        }

        int cnt = 0;
        vector<int> res;

        for (int i=0; i<n; i++){
            if (arr[i]==maxi){
                cnt++;
                res.push_back(i+1);
            }            
        }

        cout << cnt << endl;
        
        for (int num : res){
            cout << num << " ";
        } cout << endl;
    }

    return 0;
}