#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 998244353;

ll fac(ll val){

    ll res = 1;
    while(val){
        res = (res*val)%M;
        val--;
    }

    return res;
}

int main(){
    
    int t;
    cin >> t;

    ll res = 1;
    while(t--){
        string s;
        cin >> s;

        vector<int> ans;
        int n = s.size();

        
        ll cnt = 1;
        for (int i=1; i<n; i++){
            if (s[i]!=s[i-1]){
                if (cnt>1) ans.push_back(cnt);
                cnt = 1;
            } else {
                cnt++;
            }
        }
        if (cnt>1) ans.push_back(cnt);

        ll res = 0;
        for (auto num : ans){
            res += num-1;
        }

        ll num = fac(res);

        for (auto it : ans){
            num = (num*it)%M;
        }
        
        cout << res << " " << num << endl;
    }

    return 0;
}