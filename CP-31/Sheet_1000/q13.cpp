#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, x;
        cin >> n >> x;

        vector<int> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        int res = 0;

        int low  = arr[0] - x;
        int high = arr[0] + x;

        for (int i=1; i<n; i++){
            int curr_low = arr[i]-x;
            int curr_high = arr[i]+x;

            if (curr_low > high || curr_high < low){
                res++;
                low = curr_low;
                high = curr_high;
            } else {
                low = max(curr_low, low);
                high = min(curr_high, high);
            }
            // cout << "low: " << low << " high: " << high << endl;
        }
        cout << res << endl;

    }

    return 0;
}