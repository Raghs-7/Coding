#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i=0; i<n; i++) cin >> arr[i];

        sort(arr.begin(), arr.end());
        int low = 0, high = n-1;

        int flag = 1; // 1--> reduce low, 0--> reduce high
        int ans = 1;
        int k = arr[low]+arr[high];
        while(low < high){
            if (arr[low]+arr[high] != k){
                ans = 0;
                break;
            }  
            if (flag ){
                low++;
            } else {
                high--;
            }
            flag = 1-flag;
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}