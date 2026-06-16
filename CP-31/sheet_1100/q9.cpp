#include<iostream>
#include<bits/stdc++.h>

#define ll long long

using namespace std;


ll squareRoot(ll num){
    if(num == 0) return 0;

    ll low = 1;
    ll high = num;
    ll res = 0;

    while(low <= high){
        ll mid = low + (high - low) / 2;

        if(mid <= num / mid){
            res = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return res;
}

int main(){


    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        ll c;
        cin >> c;

        vector<int> s(n, 0);
        ll sum = 0;
        for (int i=0; i<n; i++){
            cin >> s[i];
            sum += s[i];
        }

        ll b = 0;
        for (int i=0; i<n; i++){
            b += 1LL * s[i] * s[i];
        }

        // ll res = (-sum + 4*squareRoot((sum*sum)-n*(b-c)))>>1;
        ll D = (sum * sum) - n*(b-c);
        ll res = (-sum + squareRoot(D))/(2*n);

        cout << res << endl;
    }
    return 0;
}