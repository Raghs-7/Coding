#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll n, k, x;
    cin >> n >> k >> x;

    vector<ll> arr(n);

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    map<ll, ll> mpp;
    ll total = 0;
    for (int i=1; i<n; i++){
        ll diff = arr[i]-arr[i-1];
        if (diff > x){
            total++;
            ll need = (diff - 1) / x;
            if (mpp.find(need)!=mpp.end()){
                mpp[need]++;
            } else {
                mpp[need] = 1;
            }
        }
    }

    // k - n * c;

    // ai -----------------------------------ai+1
    //               t points insert
    // x * t+1 >= ai+1 - ai
    // t >= (ai+1 - ai)/x - 1
    for (auto it : mpp){

        ll used = min(k/it.first, it.second);
        total -= used;
        k -= used*it.first;

    }

    cout << total+1 << endl;

    return 0;
}