#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){
        long long n, k, b, s;
        cin >> n >> k >> b >> s;

        long long minSum = b * k;

        if( s < minSum ){
            cout << -1 << endl;
            continue;
        } 

        vector<long long> res(n, 0);

        long long idx=n-1;

        long long temp = (long long)k*(b+1)-1;
        if (temp<s) res[idx] = temp;
        else res[idx] = s;
        s -= res[idx];
        idx--;

        while(idx>=0 && s!=0){
            res[idx] = min(s, k-1);
            s -= res[idx];
            idx--;
        }
        
        if (s!=0) {
            cout << -1 << endl;
            continue;
        }

        for (int i=0; i<n; i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}