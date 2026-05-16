#include<iostream>
#include<vector>
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


        int mini = arr[0];
        for (int i=1; i<n; i++){
            if (arr[i]<=mini) mini = arr[i];
        }

        vector<int> b;
        vector<int> c;

        for (int i=0; i<n; i++){
            if (arr[i] == mini) b.push_back(arr[i]);
            else c.push_back(arr[i]);
        }

        if (c.size() <1 || b.size() < 1){
            cout << -1 << endl;
            continue;
        }

        cout << b.size() << " " << c.size() << endl;

        for (int num : b) cout << num << " ";
        cout << endl;
        for (int num : c) cout << num << " ";
        cout << endl;

    }
}