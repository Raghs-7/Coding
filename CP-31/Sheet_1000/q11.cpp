#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int left = n;
    int idx = n - 1;
    int teams = 0;

    while(idx >= 0){
        if (arr[idx] > d){
            teams++;
            left--;
        } else {
            long long req = (long long)d / arr[idx] + 1;
            if (req <= left){
                teams++;
                left -= req;
            } else break;
        }
        idx--;
    }

    cout << teams << endl;
    return 0;
}