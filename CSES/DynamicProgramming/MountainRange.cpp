#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int i, int j, int prev_idx){ // max u can get from 
    int res = 0;
    for (int idx = i; idx<=j; idx++){
        if ( prev_idx == -1 || arr[idx] < arr[prev_idx]){
            int temp = 1 + solve(arr, i, idx-1, idx) + solve(arr, idx+1, j, idx);
            res = max(res, temp);
        }
    }
    return res;
}

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << solve(arr, 0, n-1, -1) << endl;
    

    return 0;
}