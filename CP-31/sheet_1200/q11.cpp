#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string str;
        cin >> str;

        ll res = 0;
        for (int i=1; i<=n; i++){
            if (str[i-1]!=1){
                for (int j=i; j<=n; j+=i){
                    if (str[j-1]=='1'){
                        break;
                    } else if (str[j-1]=='0'){
                        res += i;
                        str[j-1] = 'd';
                    }
                }
            }
        }

        cout << res << endl;
        
    }

    return 0;
}