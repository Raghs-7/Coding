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

        int one = -1;
        int zero = -1;

        int idx=0;
        while(idx<s.size()){
            if (s[idx]=='1'){
                one = idx;
                break;
            }
            idx++;
        }

        idx = 0;
        while(idx<s.size()){
            if (s[idx]=='0'){
                zero = idx;
                break;
            }
            idx++;
        }
        
        if (one==-1 || zero==-1){
            cout << s.size() << endl;
            continue;
        }

        while(one<s.size() && zero< s.size()){
            swap(s[one], s[zero]);
            while(one<s.size() && s[one]=='1') one++;
            while(zero<s.size() && s[zero]=='0') zero++;
        }

        if (one==s.size() && zero==s.size()){
            cout << 0 << endl;
            continue;
        } else if (zero!=s.size()){
            idx = zero;
        } else { // one == s.size()
            idx = one;
        }
        
        int diff = 0;
        while (idx<s.size()){
            int temp = idx+diff;
            while(temp<s.size() && s[idx]==s[temp]){
                diff++;
                temp = idx+diff;
            }
            if ( temp >= s.size() ) break;
            idx++;
        }

        cout << diff << endl;
    }
}