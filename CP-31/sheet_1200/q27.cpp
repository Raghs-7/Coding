#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool solve(string &a, string &b){
    int n = a.size();

    int diff = 0;
    bool sign = (a[0]==b[0]);
    int last = -1;
    
    for (int i=0; i<n; i++){
        if (a[i]=='1'){
            diff += 1;
        } else {
            diff -= 1;
        }

        bool curr = (a[i]==b[i]);
        if (sign!=curr){
            return false;
        }

        if (diff==0){
            last = i;
            if (i<n-1){
                sign = (a[i+1]==b[i+1]);
            }
        }
    }

    for (int i=last+1; i<n; i++){
        bool curr = (a[i]==b[i]);
        if (!curr) {
            return false;
        }
    }
    
    return true;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        bool res = solve(a, b);

        if (res){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }


    return 0;
}