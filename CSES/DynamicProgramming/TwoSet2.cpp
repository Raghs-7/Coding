#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll M = 1e9 + 7;


// if (idx==n) return 0;
// if (target>arr[idx]) choose = dp[idx+1][target-arr[idx]]
// notchoose = dp[idx+1][target]
// dp[idx][target] = max(choose, notchoose)

int main(){

    ll n;
    cin >> n;

    int target = (n)*(n+1)/2;

    if (target%2==1) {
        cout << 0 << endl;
        return 0;
    }
    else target /= 2;

    vector<int> arr(n);

    for (int i=0; i<n; i++){
        arr[i] = i+1;
    }
    

    return 0;
    
    
}