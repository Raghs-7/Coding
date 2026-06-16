#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while (t--){
        int n, k;
        cin >> n >> k;

        vector<long long> arr(n, 0);

        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        long long leftSum = 0;
        long long  rightSum = 0;
        long long total = 0;

        for (int i=n-1; i>=n-k; i--){
            rightSum += arr[i];
        }

        for (int num : arr){
            total += num;
        }

        long long res = leftSum + rightSum;

        int i = 0, j = n-k; 

        for (int _=0; _<k; _++){
            leftSum += arr[i] + arr[i+1];
            i+=2;
            rightSum -= arr[j];
            j++;
            res = min(res, leftSum + rightSum);
        }

        res = total - res;

        cout << res << endl;

    }
    

    return 0;
}