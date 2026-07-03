#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> getdigits(int num){
    vector<int> res;

    while(num!=0){
        int digit = num%10;
        if (digit!=0) res.push_back(digit);
        num /= 10;
    }

    return res;
}

int main(){

    int n; 
    cin >> n;

    vector<int> dp(n+1, 1e9);
    const int M = 1e9 + 7;

    dp[0] = 0;
    for (int i=1; i<=n; i++){
        vector<int> digits = getdigits(i);
        for (int val : digits){
            if (i>=val) dp[i] = min(dp[i], 1 + dp[i-val]);
        }
    }
    
    cout << dp[n] << endl;
    return 0;
}