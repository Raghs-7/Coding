#include<bits/stdc++.h>

using namespace std;
#define ll long long


int main(){

    int t;
    cin >> t;

    const int N = 1e3+1;
    vector<vector<bool>> possible(N, false);

    possible[1][1] = true;
    for (int num = 2; num<N; n++){
        for (int j = 1; j<=num; j++){
            int rem = num%j;
            possible[num][rem] = true;
        }
    }

    vector<int> dp(N, 1e9);
    dp[0] = 0;
    dp[1] = 0;

    for (int i=2; i<N; i++){
        for (int j=i/2; j<=i; j++){
            int rem = i-j;
            if (rem>0 && possible[i][rem]){
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> b(n), c(n);
        vector<pair<int, int>> p(n);
        
        for (int i=0; i<n; i++){
            int temp;
            cin >> temp;
            p[i].second = dp[temp];
        }

        for (int i=0; i<n; i++){
            cin >> p[i].first;
        }

        sort(p.begin(), p.end());

        vector<ll> memo(k+1, 1e9); // maximum number of coins we can get with k steps
        memo[0] = 0;
        for (int i=1; i<=k; i++){
            
        }

    }



    return 0;

}
