#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        int res = 0;
        for (int i=1; i<=n; i++){
            int ai = arr[i-1];
            // i = mul + rem
            // j > i and i+j % ai == 0;
            // j = mul + (ai-rem);

            int j =  ai - (i%ai);
            while (j<=i){
                j += ai;
            }

            for ( ; j <= n; j+=ai){
                int aj = arr[j-1];
                if ((i + j)/ai ==  aj){
                    res++;
                }
            }
        }

        cout << res << endl;
    }
    return 0;
}