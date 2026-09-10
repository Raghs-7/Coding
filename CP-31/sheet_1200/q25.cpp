#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t; 
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        map<int, int> mpp;

        for (int i=0; i<n; i++){
            int temp; cin >> temp;

            temp = temp - i - 1;
            if (mpp.find(temp)!=mpp.end()){
                mpp[temp]++;
            } else {
                mpp[temp] = 1;
            }
        }

        ll res = 0;
        for (auto it : mpp){
            ll x = it.second;
            if (x>1){
                res += x*(x-1)/2;
            }
        }
        cout << res << endl;
    }
    return 0;
}