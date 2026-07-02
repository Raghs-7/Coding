#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<vector<int>> arr(n, vector<int>());

        for(int i=0; i<n; i++){
            int k;
            cin >> k;
            for (int j=0; j<k; j++){
                int num;
                cin>> num;
                arr[i].push_back(num);
            }
        }

        // vector<int> memo(26, 0);
        map<int, int> memo;

        for(int i=0; i<n; i++){

            int k = arr[i].size();
            for (int j=0; j<k; j++){
                int num = arr[i][j];
                if (memo.find(num-1)!=memo.end()){
                    memo[num-1]++;
                } else {
                    memo[num-1] = 1;
                }
            }
        }

        bool res = false;
        for(auto vec : arr){

            bool temp = true;
            for (auto num : vec){
                if (memo[num-1]<=1) temp = false;
            }

            if (temp) res = true;
        }

        if (res) cout << "YES" << endl;
        else cout << "NO" << endl;

    }


    return 0;
}