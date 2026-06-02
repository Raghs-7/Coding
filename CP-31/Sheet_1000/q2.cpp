#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){

        int n, k;
        cin >> n >> k;
        if (k!=4) {
            int res = 0;
            bool flag = false;

            for (int i=0; i<n; i++){
                int x;
                cin >> x;
                if (x%k==0) flag = true;
                
                res = max(res, x%k);
            }
            if (flag) cout << 0 << endl;
            else cout << k-res << endl; 
        } else {

            bool flag = false;
            int res = 0;
            int cnt = 2;

            for (int i=0; i<n; i++){
                int x;
                cin >> x;

                if (x%k==0) flag = true;

                if (x%2==0) {
                    cnt = max(0, cnt-1);
                }

                res = max(res, x%k);
            }

            if (flag) cout << 0 << endl;
            else cout << min(k-res, cnt) << endl;
        }
    }
    return 0;
}