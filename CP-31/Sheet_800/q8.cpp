#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int k;
        cin >> k;

        int flag = 0;
        for (int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            if (temp == k) flag = 1;
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}