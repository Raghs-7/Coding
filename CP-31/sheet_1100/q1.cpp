#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string str;
        cin >> str;

        set<int> s;

        int res = 1;
        s.insert(str[0]);
        for (int i=1; i<n; i++){
            s.insert(str[i]);
            res += s.size();
        }
        cout << res << endl;
    }
    return 0;
}