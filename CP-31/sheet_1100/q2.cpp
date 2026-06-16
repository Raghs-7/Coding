#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n, 0);
        vector<int> b(n, 0);

        int sum = 0;
        for (int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            sum += temp;
            a[i] = sum;
        }
        for (int i=0; i<n; i++) cin >> b[i];

        priority_queue<int> pq;
        for (int i=0; i<min(k,n); i++) {
            pq.push(b[i]);
        }

        int res = a[min(k, n)-1];
        map<int, int> removed;


        // for (int num : a){
        //     cout << num << " ";
        // }
        // cout << endl;

        for (int i = min(k-1, n-1); i>=0; i--) {
            int largest = pq.top(); 
            while(removed.find(largest) != removed.end() && removed[largest]>0){
                pq.pop();
                removed[largest]--;
                largest = pq.top();
            }

            int temp = a[i] + (k-i-1)*largest;
            // cout << temp << endl;
            res = max(res, temp);
            
            if (removed.find(b[i]) != removed.end()){
                removed[b[i]]++;
            } else removed[b[i]] = 1;
        }

        cout << res << endl;

    }
    return 0;
}