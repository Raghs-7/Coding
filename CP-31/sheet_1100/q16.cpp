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
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        ll reach = 1;
        
        if (arr[0]!=1){
            cout << "NO" << endl;
            continue;
        }
        bool res = true;
        for (int i=1 ; i<n; i++){
            if (arr[i] > reach){
                res = false;
                break;
            }
            reach += arr[i];
        }

        if (res==false){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }


    }


    return 0;
}