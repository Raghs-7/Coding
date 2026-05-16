#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k; 
        cin >> k;

        int arr[n];
        for (int i=0; i<n; i++) cin >> arr[i];

        if (k>1) cout << "YES" << endl;
        else{
            int back = 0;
            int flag = 1; // SORTED
            for (int num : arr){
                if (back > num) {
                    flag = 0; break;
                }
                back = num;
            }
            if (flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}