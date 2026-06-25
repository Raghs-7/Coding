#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t;
    cin >> t;

    while(t--){


        int n, x, y;
        cin >> n >> x >> y;
        vector<int> arr(n, 0);

        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        map<pair<int, int>, int> mpp;

        ll res = 0;
        for (int i=0; i<n; i++){
            int num = arr[i];
            int c = num%x;
            int a = (x-c)%x;
            int b = (num%y);
            
            pair<int, int> p = {a, b};

            if (mpp.find(p)!=mpp.end()){
                res += mpp[p];
            } 

            if (mpp.find({c, b})!=mpp.end()){
                mpp[{c, b}]++;
            } else {
                mpp[{c,b}] = 1;
            }
        }

        cout << res << endl;
    }



    return 0;
}