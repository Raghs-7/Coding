#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


    int n;
    cin >> n;

    string s;
    cin >> s;

    int plus = 0;
    for (char c : s)
        if (c == '+') plus++;

    int minus = n - plus;

    int q;
    cin >> q;

    while (q--) {
        ll a, b;
        cin >> a >> b;

        if (a == b) {
            cout << (plus == minus ? "YES" : "NO") << endl;
            continue;
        }

        ll num = b * 1LL * (minus - plus);   // = b * (n - 2*plus)
        ll den = a - b;

        if (num % den != 0) {
            cout << "NO" << endl;
            continue;
        }

        ll d = num / den;

        if (d >= -minus && d <= plus)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}