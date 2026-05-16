#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;


        int temp;
        int even = 0;
        int odd = 0;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        
        if (n == 1) {
            cout << "NO" << endl;
            continue;
        }


        if (odd + even == 2){
            if (odd == 0 || even == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            continue;
        }

        if (odd%2){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    
    return 0;

}