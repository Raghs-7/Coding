#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        vector<int> arr(n, 0);

        int mini = 1e9;
        for (int i=0; i<n; i++){
            cin >> arr[i];
            mini = min(mini, arr[i]);
        }

        map<int, int> mpp;
        for (int num : arr){
            if (mpp.find(num)!=mpp.end()){
                mpp[num]++;
            } else {
                mpp[num] = 1;
            }
        }

        ll res = 0;
        int currDolls = 0;
        int prev = mini-1;
        for (auto it: mpp){
            int dolls = it.second;
            int curr = it.first;
            

            if (curr==(prev+1)){
                res += max(dolls-currDolls, 0); 
            } else {
                res += dolls;
            }

            prev = curr;
            currDolls = dolls;
        }

        cout << res << endl;
    }

    return 0;
}