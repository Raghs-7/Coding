#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int justGreater(vector<int> &arr, int x){
    int low = 0, high = arr.size()-1;

    int res = -1;
    while(low <= high){

        int mid = low + (high-low)/2;

        if (arr[mid] > x){
            res = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return res;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        vector<int> arr(n, 0);

        for (int i=0; i<n; i++){
            cin >> arr[i];
        } 

        vector<int> pairs;
        int prev = arr[0];
        for (int i=0; i<n; i++){
            int curr = arr[i];
            if (curr!=prev){
                pairs.push_back(i+1);
            }
            prev = curr;
        }

        int q;
        cin >> q;

        vector<pair<int, int>> p(q, {0, 0});

        for (int i=0; i<q; i++){
            cin >> p[i].first >> p[i].second;
        }

        for (auto it : p){
            int idx = justGreater(pairs, it.first);

            if ( idx==-1 || pairs[idx]>it.second ){
                cout << -1 << " " << -1 << endl;
            } else {
                cout << pairs[idx]-1 << " " << pairs[idx] << endl;
            }
        }
        cout << endl;
    }
    
    return 0;
}