#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool present(vector<int> &arr, int idx, int x){
    int n = arr.size();

    int sum = 0;

    for (int i=idx; i<n; i++){
        sum = sum^arr[i];
        if (sum==x) return true;
    }
    
    return false;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> arr(n, 0);

        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        vector<int> pref(n, 0);

        pref[0] = arr[0];
        for (int i=1; i<n; i++){
            pref[i] = arr[i]^pref[i-1];
        }

        bool res = false;
        for (int i=1; i<n; i++){
            int temp = pref[n-1]^pref[i-1];
            if (temp==pref[i-1]){
                res = true;
            } else if (temp==0 && present(arr, i, pref[i-1])){
                res = true;
            }
        }

        if (res) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}