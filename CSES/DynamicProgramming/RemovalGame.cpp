#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    ll total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    vector<ll> dp(n);

    for (int i = n - 1; i >= 0; i--) {
        dp[i] = a[i];

        for (int j = i + 1; j < n; j++) {
            dp[j] = max(
                a[i] - dp[j],      // take left
                a[j] - dp[j - 1]   // take right
            );
        }
    }

    ll diff = dp[n - 1];
    ll firstPlayer = (total + diff) / 2;

    cout << firstPlayer << endl;

    return 0;
}