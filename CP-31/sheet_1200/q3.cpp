#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (1LL* a * b) / gcd(a, b);
}


int main(){

    int t;
    cin >> t;
    while(t--){

        ll n, x, y;
        cin >> n >> x >> y;


        ll mulx = n/x;
        ll muly = n/y;
        ll mulxy = n/lcm(x,y);

        ll res = 0;
        ll high = n;
        ll low = 1;

        mulx -= mulxy;
        muly -= mulxy;

        res = 1LL * mulx * (2LL*n - mulx + 1) / 2  - 1LL * muly * (muly + 1) / 2;
         
        cout << res << endl;
    }  

    return 0;
}