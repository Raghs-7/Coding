#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// 1 2 3 4 5 6

// 1 2 3 4 5 6 7 8 9 10
// 4, 2, 1

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        
        vector<int> arr(m, 0);

        for (int i=0; i<m; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        vector<int> diff;
        for (int i=1; i<m; i++){
            diff.push_back(arr[i]-arr[i-1]-1);
        }

        diff.push_back(n-arr[m-1]+arr[0]-1);

        sort(diff.begin(), diff.end());
        reverse(diff.begin(), diff.end());

        int idx=0;
        ll saved = 0;
        ll day = 1;
        while(idx < m){
            ll temp = diff[idx]-(day-1)-day;
            if (temp==0){
                temp = 1;
            } 
            saved += max(temp, 0LL);
            day += 2;
            idx++;
        } 

        cout << n - saved << endl;
    }

    return 0;
}