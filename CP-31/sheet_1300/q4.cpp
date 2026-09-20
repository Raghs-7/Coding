#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        // if product % n == 0;
        // x**n = prod
        // x = (prod)**1/n
        
        
        map<int, int> mpp;
        for (auto num : arr){
            for (int i=2; i<num; i++){
                if (n%i==0) {
                    if (mpp.find(i)!=mpp.end()){
                        mpp[i]++;
                    } else {
                        mpp[i] = 1;
                    }
                }
            }
        }

        bool res = true;
        for (auto it : mpp){
            if (it.second < n) {
                res = false;
                break;
            }
        }

        if (res) cout << "YES" << endl;
        else cout << "NO" << endl;

    }


    return 0;
}