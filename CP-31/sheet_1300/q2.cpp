#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int justGreater(vector<int> &arr, int x){
    int low = 0, high = arr.size()-1;

    int res = high;
    while(low <= high){

        int mid = low + (high-low)/2;

        if (arr[mid]>=x){
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
                pairs.push_back(i);
            }
            prev = curr;
        }

        

    }
    
    return 0;
}