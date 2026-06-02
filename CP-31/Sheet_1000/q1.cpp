#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        int ones = 0;
        int zeros = 0;

        for (char c : s){
            if (c=='1') ones++;
            else zeros++;
        }
        
        int idx = 0;
        while(idx<s.size()){
            if (s[idx]=='1'){
                if (zeros>0) zeros--;
                else break;
            } else {
                if (ones>0) ones--;
                else break;
            }
            idx++;
        }

        cout << s.size()-idx << endl;
    }
}