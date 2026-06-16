#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int x, vector<int> green){
    
    int low = 0;
    int high = green.size()-1;

    int res = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if (x<green[mid]){
            res = green[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return res;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        char c;
        string s;
        cin >> n;
        cin >> c;
        cin >> s;

        if (c=='g'){
            cout << 0 << endl;
            continue;
        }

        vector<int> green;
        vector<int> nongreen;
        for (int idx=0; idx<s.size(); idx++){
            if (s[idx]=='g') green.push_back(idx);
            else if (s[idx]==c) nongreen.push_back(idx);
        }
        
        int res = 0;
        for (int i=0; i<nongreen.size(); i++){
            int end = binarySearch(nongreen[i], green);
            // cout << nongreen[i] << " " << end << endl;
            if (end==-1){
                res = max(res, n-nongreen[i]+green[0]);
            } else {
                res = max(res, end-nongreen[i]);
            }
        }
        cout << res << endl;
    }

    return 0;
}