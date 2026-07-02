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

        vector<ll> arr(n, -1);

        for (int i=0; i<n; i++){
            cin >> arr[i];
            if (i%2==0) arr[i] = -arr[i];
        }

        set<ll> memo;

        bool res = false;
        ll sum = 0;
        memo.insert(sum);
        for (int i=0; i<n; i++){
            sum += arr[i];
            if ( memo.find(sum)!=memo.end()){
                res = true;
                break;
            }
            memo.insert(sum);
        }
        

        if (res) cout << "YES" << endl;
        else cout << "NO" << endl;


    }



    return 0;
}