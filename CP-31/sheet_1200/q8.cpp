#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long


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

        int mini = 1;
        int maxi = n;
        int low = 0;
        int high = n-1;

        while(low<=high){
            if (arr[low]==mini){
                low++;
                mini++;
            } else if (arr[high]==mini){
                mini++;
                high--;
            } else if (arr[low]==maxi){
                maxi--;
                low++;
            } else if (arr[high]==maxi){
                high--;
                maxi--;
            } else {
                break;
            }
        }
        if (low>high){
            cout << -1 << endl;
        } else {
            cout << low+1 << " " << high+1 << endl;
        }
    }

    return 0;
}