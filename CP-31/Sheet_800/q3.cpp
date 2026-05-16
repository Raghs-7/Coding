#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n; 
        cin >> s;

        int ans = 0;
        int cnt = 0;
        int maxi = 0;
        for (int i=0; i<n; i++){
            if (s[i]=='.'){
                cnt++;
                maxi = max(maxi, cnt);
                if (cnt<=2) ans++;
            } else {
                cnt = 0;
            }
        }

        if (maxi>2){
            cout << 2 << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}