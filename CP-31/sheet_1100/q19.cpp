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
        
        int cnt = 0;
        ll mini = INT_MAX;
        ll total = 0;
        bool zero = false;

        for (int i=0; i<n; i++){
            ll temp;
            cin >> temp;
            if (temp<0){
                cnt++;
                total -= temp;
            } else if (temp==0){
                zero = true;
            } else {
                total += temp;
            }
            mini = min(mini, abs(temp));
        }

        if (zero){
            cout << total << endl;
            continue;
        }

        
        if (cnt%2==1){
            total -= 2 * mini;
        } 
        cout << total << endl;
    }


    return 0;     
}