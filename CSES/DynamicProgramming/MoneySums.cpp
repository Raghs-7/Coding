#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int n; 
    cin >> n;

    vector<int> arr(n, 0);

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<bool> dp(1e5+1, false);

    sort(arr.begin(), arr.end());
    dp[0] = true;

    for (int i=n-1; i>=0; i--){
        for (int curr=1e5; curr>=arr[i]; curr--){
            dp[curr] = dp[curr] || dp[curr-arr[i]];
        }
    }

    int res = 0;
    for (int i=1; i<1e5+1; i++){
        if (dp[i]) res++;
    }

    cout << res << endl;
    
    for (int i=1; i<1e5+1; i++){
        if (dp[i]) cout << i << " ";
    }
    cout << endl;
    return 0;
}