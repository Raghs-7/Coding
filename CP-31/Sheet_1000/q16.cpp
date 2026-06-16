#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, r, b;

        cin >> n >> r >> b;

        string s;
        int j = 0;

        for (int i=0; i<b; i++){
            int maxi = (r-j)/(b-i+1);
            for (int _=0; _< maxi; _++){
                s += 'R';
                j++;
            }
            s += 'B';
        }
        
        for (; j<r; j++){
            s += 'R';
        }
        cout << s << endl;
    }
}