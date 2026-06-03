#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        map<int, int> mpp1;
        int prev;
        cin >> prev;
        int cnt = 1;
        mpp1[prev] = cnt;
        for (int i=0; i<n-1; i++){
            int curr;
            cin >> curr;
            if (curr==prev){
                cnt++;
            } else {
                if (mpp1.find(prev)!=mpp1.end()){
                    mpp1[prev] = max(mpp1[prev], cnt);
                } else {
                    mpp1[prev] = cnt;
                }
                cnt = 1;
            }
            prev = curr;
        }
        if (mpp1.find(prev)!=mpp1.end()){
            mpp1[prev] = max(mpp1[prev], cnt);
        } else {
            mpp1[prev] = cnt;
        }

        map<int, int> mpp2;
        cin >> prev;
        cnt = 1;
        mpp2[prev] = cnt;
        for (int i=0; i<n-1; i++){
            int curr;
            cin >> curr;
            if (curr==prev){
                cnt++;
            } else {
                if (mpp2.find(prev)!=mpp2.end()){
                    mpp2[prev] = max(mpp2[prev], cnt);
                } else {
                    mpp2[prev] = cnt;
                }
                cnt = 1;
            }
            prev = curr;
        }
        if (mpp2.find(prev)!=mpp2.end()){
            mpp2[prev] = max(mpp2[prev], cnt);
        } else {
            mpp2[prev] = cnt;
        }
        cnt = 1;

        int res = 0;
        for (auto it : mpp1){
            int num = it.first;
            int freq = it.second;
            
            if (mpp2.find(num)!=mpp2.end()) freq += mpp2[num];
            res = max(res, freq);
        }
        for (auto it : mpp2){
            int num = it.first;
            int freq = it.second;
            
            if (mpp1.find(num)!=mpp1.end()) freq += mpp1[num];
            res = max(res, freq);
        }

        cout << res << endl;
    }
}