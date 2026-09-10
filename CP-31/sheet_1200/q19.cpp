#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){

    int t;
    cin >> t;
    
    while (t--){
        int n;
        cin >> n;
        char c;
        cin >> c;
        
        string s;
        cin >> s;

        
        int others = n;
        for (auto it : s){
            if (it==c){
                others--;
            }
        }
        if (others==0){
            cout << 0 << endl;
            continue;
        }
        
        int ans = -1;
        for (int sep=2; sep<=n; sep++){
            bool res = true;
            for (int i=sep-1; i<n; i+=sep){
                if (s[i]!=c){
                    res = false;
                    break;
                }
            }

            if (res){
                ans = sep;
                break;
            }
        }

        if (ans!=-1){
            cout << 1 << endl;
            cout << ans << endl;
            continue;
        }

        cout << 2 << endl;
        cout << n << " " << n-1 << endl;
    }

    return 0;
}