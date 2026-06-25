#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int root(int num){

}


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int high = root(n);
        int low = 2;

        for (int i=low; i<=high; i++){

            int k = i;

            ll val = ((k-1)*n+1);
            float n = log(val)/log(k);

            
        }

    }


    return 0;
}