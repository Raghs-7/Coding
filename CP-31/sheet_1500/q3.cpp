#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

        vector<int> dp(n+1, -1);

        dp[n] = 0;
        dp[n-1] = 1;
        for (int i=n-2; i>=0; i--){
            
            int choose = INT_MAX;
            if (i+arr[i] < n) choose = dp[i+1+arr[i]];
            int notchoose = 1 + dp[i+1];

            dp[i] = min(notchoose, choose);
        }

        cout << dp[0] << endl;

    }

    return 0;
}