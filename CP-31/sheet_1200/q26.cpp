#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    const ll M = 1e9 + 7;
    int t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;

        ll res = 1;
        for (int i=0; i<k; i++){
            res = (res * n)%M;
        }

        cout << res << endl;

    }


    return 0;
}