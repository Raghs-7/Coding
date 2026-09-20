#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t;
    cin >> t;

    //       3-->
    //            6
    // 9 --> 8         2 <-- 1
    //            4
    //             <-- 7  

    map<int, pair<int, int>> mpp; // a to (b, edgeWeight)
    mpp[2] = {4, 0};
    mpp[4] = {8, 0};
    mpp[8] = {6, 1};
    mpp[6] = {2, 1};
    
    mpp[9] = {8, 1};
    mpp[3] = {6, 0};
    mpp[1] = {2, 0};
    mpp[7] = {4, 1};

    mpp[5] = {0, 1};

    while (t--){
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        vector<ll> weight(n);
        bool special = false;
        for (int i=0; i<n; i++){
            
            weight[i] = arr[i]/10;
            
            int rem = arr[i]%10;
            if (rem==0 || rem==5) {
                special = true;
                break;
            }

            while (rem!=2){
                auto [temp, w] = mpp[rem];
                weight[i] += w;
                rem = temp;
            }            
        }

        if (special){
            bool res = true;
            for (int i=0; i<n; i++){
            
                weight[i] = arr[i]/10;
                
                int rem = arr[i]%10;

                if (rem==5){
                    weight[i]++;
                } else if (rem!=0){
                    res = false;
                    break;
                }
            }

            if (!res) cout << "NO" << endl;
            else {
                bool temp = true;
                for (int i=0; i<n; i++){
                    if (weight[i]!=weight[0]){
                        temp = false;
                        break;
                    }
                }
                if (temp) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        } else {
            bool res = true;
            for (int i=1; i<n; i++){
                if (weight[i-1]%2 != weight[i]%2){
                    res = false;
                }
            }
            
            if (res) cout << "YES" << endl;
            else cout << "NO" << endl;
        }


    }

    return 0;
}