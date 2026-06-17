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
        
        int m = n*(n-1)/2;
        vector<int> b(m,0);
        for (int i=0; i<m; i++){
            cin >> b[i];
        }

        sort(b.begin(), b.end());

        vector<ll> ans;

        int cnt = n - 1;
        int idx = 0;

        while (cnt > 0) {
            ans.push_back(b[idx]);
            idx += cnt;
            cnt--;
        }

        ans.push_back(1000000000);

        for (auto x : ans){
            cout << x << ' ';
        }   
        cout << endl;

    }

    return 0;
}