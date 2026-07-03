#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t;
    cin >> t;
    

    while(t--){
        int n;
        cin >> n;

        vector<vector<int>> index(n, vector<int>());
        vector<int> arr(n, 0);

        for (int i=0; i<n; i++){
            cin >> arr[i];
            index[arr[i]-1].push_back(i);
        }

        vector<int> res(n, INT_MAX);

        for (int i = 0; i<n; i++){
            
            int m = index[i].size();
            if (m>0){
                int window = index[i][0]+1;
                int prev = index[i][0];

                for (int idx = 1; idx<m; idx++){
                    window = max(window, index[i][idx]-prev);
                    prev = index[i][idx];
                }
                window = max(window, n-prev);
                res[window-1] = min(i+1, res[window-1]); 
            }
        }


        int mini = INT_MAX;
        for (int num : res){
            if (num==INT_MAX && mini==INT_MAX) cout << -1 << " ";
            else {
                mini = min(mini, num);
                cout << mini << " ";
            }
        }
        cout << endl;
    }

    return 0;
}