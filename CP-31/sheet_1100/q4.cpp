#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maximumSubarraySum(vector<int>& arr, int low , int high){
    if (low>high){
        return 0;
    }

    int res = arr[low];
    int maxi = arr[low];
    int sum = 0;

    for (int i=low; i<=high; i++){
        sum = sum + arr[i];
        if (sum < 0){
            sum = 0;
        } 
        res = max(res, sum);
        maxi = max(maxi, arr[i]);
    }

    if (res == 0) return maxi;
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


        int start = 0;
        int prev = (arr[0]%2);
        int end = 0;

        int ans = arr[0];

        for (int i=1; i<n; i++){
            int curr = (abs(arr[i])%2);
            if (curr == prev){
                end = i-1;
                ans = max(ans, maximumSubarraySum(arr, start, end));
                start = i;
            }
            prev = curr;
        }
        ans = max(ans, maximumSubarraySum(arr, start, n-1));
        cout << ans << endl;
    }
}