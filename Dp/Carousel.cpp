#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;

        vector<int> animal(n, 0);

        for (int i=0; i<n; i++){
            cin >> animal[i];
        }


        int diff = 1;
        int prev = 1;
        int curr = 2;

        vector<int> colour(n, 0);

        colour[0] = prev;
        for (int i=1; i<n; i++){
            if (animal[i]!=animal[i-1]){
                diff = max(diff, 2);
                swap(prev, curr);
            }
            colour[i] = prev;
        }
        if (colour[0]==colour[n-1] && animal[0]!=animal[n-1]) {
            colour[n-1] = 3;
            cout << 3 << endl;
        } else {
            cout << diff << endl;
        }
        
        for (int num : colour){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}