#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;

    while(t--){
        
        int n; 
        string s;
        cin >> n >> s;

        vector<int> right(26, 0);
        vector<int> left(26, 0);
        int a = 0;
        int b = 0;

        for (char c : s){
            if (right[c-'a']==0) b++;
            right[c-'a']++;
        }

        int res = a+b;
        for (char c : s){
            if (right[c-'a']==1) b--;
            right[c-'a']--;
            if (left[c-'a']==0) a++;
            left[c-'a']++;
            res = max(res, a + b);
        }

        cout << res << endl;
    }

    return 0;
}