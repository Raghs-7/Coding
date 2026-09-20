#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        vector<int> memo(31);
        for (int i=1; i<=n; i++){
            
            int num = arr[i-1]; 
            int mask = 1;

            for (int j=0; j<=30; j++){
                if ((mask & num)==mask){
                    memo[j]++;
                }
                mask = mask << 1;
            }
        }

        cout << 1 << " ";
        for (int k=2; k<=n; k++){
            bool divisible = true;
            for (int num : memo){
                if (num%k != 0) {
                    divisible = false;
                    break;
                } 
            }
            if (divisible) cout << k << " ";
        }

        cout << endl;

    }


    return 0;
}