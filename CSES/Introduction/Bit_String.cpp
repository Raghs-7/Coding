#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// binary exponentitation O(logb) for a ^ b


void naiveSolution(){
    int n;
    // cin >> n;

    const int M = 1e9 + 7;

    int ans = 2;
    for (int i=1; i<n; i++){
        ans *= 2;
        ans %= M;
    }
    cout << ans << endl;

    // return 0;
}


int main(){

    long long a = 2;
    long long b;
    cin >> b;

    const long long MOD = 1e9 + 7;
    long long res = 1;

    while(b > 0){

        if(b & 1){
            res = (res * a) % MOD;
        }

        a = (a * a) % MOD;

        b >>= 1;
    }

    cout << res << endl;

    return 0;
}