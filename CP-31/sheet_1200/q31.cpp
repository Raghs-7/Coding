#include<bits/stdc++.h>
using namespace std;
#define ll long long

int firstSetBit(int num){

    int mask = 1<<30;

    for (int i=0; i<31; i++){
        if ((num & mask) ==  mask) return mask;
        mask >>= 1;
    }

    return -1;
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        map<int, int> mpp;

        for (int it : arr){
            it = firstSetBit(it);
            // cout << it << " ";
            if (mpp.find(it)!=mpp.end()){
                mpp[it]++;
            } else {
                mpp[it] = 1;
            }
        }
        // cout << endl;

        ll res = 0;
        for (auto it : mpp){
            int cnt = it.second;
            res += (cnt*1LL)*(cnt-1)/2; 
        }

        cout << res << endl;

    }

    return 0;
}