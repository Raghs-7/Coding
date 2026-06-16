#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> arr, int x){
    int low = 0;
    int high = arr.size()-1;

    int res = 0;
    while(low <= high){
        int mid = low + (high-low)/2;
        
        if (arr[mid]<=x){
            res = mid;
            low = mid+1;
        } else {
            high = mid-1;
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

        vector<int> a(n, 0);
        vector<int> b(n, 0);

        int sum = 0;
        for (int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            a[i] = temp;
            b[i] = temp;
        }

        sort(b.begin(), b.end());

        vector<long long> prefix_sum(n, b[0]);

        for( int i=1; i<n; i++){
            prefix_sum[i] = b[i] + prefix_sum[i-1];
        }

        unordered_map<int, int> indexes;
        for (int idx=0; idx<n; idx++){
            indexes[b[idx]] = idx;
        }

        vector<int> res(n, 0);

        for (int i=0; i<n; i++){
            // int idx = binary_search(b, a[i]); // find the last occurance of a[idx];
            int idx = indexes[a[i]];

            res[i] = idx;
            idx++;
            while(idx<n && prefix_sum[idx-1] >= b[idx] ){
                res[i]++;
                idx++;
            }
        }

        for (int num : res) {
            cout << num << " ";
        } cout << endl;

    }
    return 0;
}