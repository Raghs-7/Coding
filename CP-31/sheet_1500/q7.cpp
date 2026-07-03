#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void add_palandromic(vector<int> &arr){

    for (int i=1; i<10; i++) {
        arr.push_back(i);
    }

    for (int a=1; a<10; a++){
        int num = a*10 + a;
        arr.push_back(num);
    }

    for (int a=1; a<10; a++){
        for (int b=0; b<10; b++){
            int num = a*100 + b*10 + a;
            arr.push_back(num);
        }
    }
    
    for (int a=1; a<10; a++){
        for (int b=0; b<10; b++){
            int num = a*1000 + b*100 + b*10 + a;
            arr.push_back(num);
        }
    }

    for (int a=1; a<4; a++){
        for (int b=0; b<10; b++){
            for (int c=0; c<10; c++){
                int num = a*10000 + b*1000 + c*100 + b*10 + a;
                arr.push_back(num);
            }
        }
    }    
}


int main(){

    int t;
    cin >> t;

    vector<int> arr;

    add_palandromic(arr);

    const int N = 4*1e4+1;
    const int M = 1e9 + 7;
    vector<ll> dp(N, 0);

    dp[0] = 1;
    for (int num : arr){
        for (int i=num; i<N; i++){
            dp[i] += dp[i-num];
            dp[i] %= M;
        }
    }

    while(t--){
        int n;
        cin>> n;
        
        cout << dp[n] << endl;

    }

    return 0;
}