#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        if (n % 2 == 0) {
            cout << (k - 1) % n + 1 << endl;
        }
        else {
            k--;
            ll shifts = k / (n / 2);
            cout << (k + shifts) % n + 1 << endl;
        }
    }
}