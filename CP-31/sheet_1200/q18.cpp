#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    int t;
    cin >> t;

    while(t--) {    
        int n;
        cin >> n;
        vector<ll> a(n);
        bool sorted = true;
        
        cin >> a[0];
        for (int i=1; i<n; i++) {
            cin >> a[i];
            if (a[i] < a[i-1]) {
                sorted = false;
            }
        }

        if (a[n-2] > a[n-1]) {
            cout << -1 << endl;
            continue;
        }

        if (a[n-1] < 0) {
            if (sorted) cout << 0 << endl;
            else cout << -1 << endl;
            continue;
        }

        cout << n-2 << endl;
        for (int i = 1; i <= n-2; i++) {
            cout << i << " " << n - 1 << " " << n << endl;
        }
    }
    return 0;
}