#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (1LL* a * b) / gcd(a, b);
}


int main(){

    int t;
    cin >> t;
    while(t--){

        int n, x, y;
        cin >> n >> x >> y;


        int mulx = n/x;
        int muly = n/y;
        int mulxy = n/lcm(x,y);

        ll res = 0;
        int high = n;
        int low = 1;

        mulx -= mulxy;
        muly -= mulxy;
        
        for (int i=0; i<mulx; i++){
            res += high;
            high--;
        }
        for (int i=0; i<muly; i++){
            res -= low;
            low++;
        }
         
        cout << res << endl;
    }  

    return 0;
}