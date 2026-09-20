#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    string s;
    cin >> s;

    int n = s.size();

    for (int i=1; i<n; i++){
        if (s[i-1]==s[i]){

            char c1 = s[i-1];
            char c2 = '$';
            if (i<n-1) c2 = s[i+1];
            
            char c = 'a';
            while (c==c1 || c==c2) c++;

            s[i] = c;
        }
    }
    cout << s << endl;

    return 0;
}