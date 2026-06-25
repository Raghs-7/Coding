#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){

    int t;
    cin >> t;
    while(t--){

        int n, s;
        cin >> n >> s;

        vector<int> idx;
        for (int i=0; i<n; i++){
            int temp;
            cin >> temp;
            if (temp==1) {
                idx.push_back(i);
            }
        }

        if (idx.size() < s){
            cout << -1 << endl;
            continue;
        }


        int res = 0;
        for (int i=s-1; i<idx.size(); i++){
            int high = n-1;
            int low = 0;
            if ((i-s) >= 0){
                low = idx[i-s];
                low++;
            }
            if ((i+1)<idx.size()){
                high = idx[i+1];
                high--;
            }

            int len = high-low+1;
            // cout << low << " " << high << " " << len << endl;
            res = max(len, res);
        } 
        
        cout << n-res << endl;

    }

    return 0;
}