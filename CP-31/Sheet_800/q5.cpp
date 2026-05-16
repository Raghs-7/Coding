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
        vector<int> arr(n);

        for (int i=0; i<n; i++) cin >> arr[i];

        int flag = 1;
        for (int i=1; i<n; i++){
            if (arr[0] > arr[i]){
                flag = 0;
                break;
            } 
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}