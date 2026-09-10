#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solution(string &s, int i, int j, char c){
    if (i>j) return 0LL;
    if (c=='$'){
        if (s[i]==s[j]){
            return solution(s, i+1, j-1, c);
        } else {
            ll a = solution(s, i+1, j, s[i]);
            ll b = solution(s, i, j-1, s[j]);

            if (a==-1) return b;
            if (b==-1) return a;

            return min(a,b);
        }
    }

    ll res = 1;
    while (i<=j){
        if (s[i]==s[j]){
            i++, j--;
        } else if (s[i]==c){
            i++; res++;
        } else if (s[j]==c){
            j--; res++;
        } else {
            return -1;
        }
    }

    return res;
}

int main(){

    int t;
    cin >> t;

    while (t--){
        int n; 
        cin >> n;
        
        string str;
        cin >> str;

        cout << solution(str, 0, n-1, '$') << endl;
    }
}