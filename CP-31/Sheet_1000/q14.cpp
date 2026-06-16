#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int prev;
        cin >> prev;
        int start = 0;

        vector<int> res(n, 0);
        bool flag = true;

        for(int i=1; i<n; i++){
            int curr;
            cin>>curr;

            if (curr==prev){
                res[i] = i;
            } else {
                if (i-start == 1) {
                    flag = false;
                    break;
                }
                res[start] = i;
                start = i;
                prev = curr;
            }
        }
        
        if (n-start == 1){
            flag = false;
        }
        res[start] = n;

        if (!flag) {
            cout << -1 << endl;
            continue;
        } 
        for (int i=0; i<n; i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}