#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int n;
    cin >> n;

    vector<ll> arr(n, 0);
    ll sum = 0;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    bool res = true;
    for (int num : arr){
        if (num > sum/2) {
            res = false;
            break;
        }
    }

    if (res && sum%2==0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}