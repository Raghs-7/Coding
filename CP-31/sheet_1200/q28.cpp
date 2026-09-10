#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        map<int, int> mpp;

        for (int i=0; i<n; i++){
            int temp;
            cin >> temp;
            
            int rem = temp%m;

            if (mpp.find(rem)!=mpp.end()){
                mpp[rem]++;
            }else {
                mpp[rem] = 1;   
            }
        }

        int res = 0;
        if (mpp.find(0)!=mpp.end()) res++;


        for (int i=1; i<=m/2; i++){
            if (mpp.find(i)!=mpp.end()){
                if (mpp.find(m-i)!=mpp.end()){
                    res += max(abs(mpp[i]-mpp[m-i]), 1);
                } else {
                    res += mpp[i];
                }
            } else {
                if (mpp.find(m-i)!=mpp.end()){
                    res += mpp[m-i];
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}