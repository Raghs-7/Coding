#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    n++;

    ll cnt = 0;
    ll len = 2;

    for (int i = 0; i < 62; i++) {
        cnt += (n / len) * (len / 2);

        ll rem = n % len;
        cnt += max(0LL, rem - len / 2);

        len <<= 1;
    }

    cout << cnt << '\n';
}