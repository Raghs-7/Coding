#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        struct Compare {
            bool operator()(pair<int,int> a, pair<int,int> b) {
                if (a.first == b.first)
                    return a.second > b.second; // smaller idx wins

                return a.first < b.first; // larger val wins
            }
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        
        for (int i=0; i<n; i++){
            int temp;
            cin >> temp;
            temp = temp % k;
            if (temp==0) temp = k;
            pq.push({temp, i});
        }

        vector<int> res;
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            it.first -= k;
            if (it.first>0){
                pq.push(it);
            } else {
                res.push_back(it.second+1);
            }
        }

        for (int num: res) cout << num << " ";
        cout << endl;
    }

}