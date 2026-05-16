#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        int prev;
        cin >> prev;

        int curr;

        int diff = __INT_MAX__;
        for (int i=1; i<n; i++){
            cin >> curr;

            diff = min(diff, curr-prev);
            prev = curr;
        }

        if (diff < 0) cout << 0 << endl;
        else {
            cout << diff/2 + 1 << endl;
        }
    }

    return 0;
}