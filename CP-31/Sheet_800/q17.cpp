#include<iostream>
#include<vector>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, k, x;
        cin >> n >> k >> x;

        int target = n;
        int curr = k;
        vector<int> ans;

        while(target && curr){
            if (curr == x){
                curr--;
                continue;
            }
            int temp =  target % curr;
            int mul = target/curr;
            for (int i=0; i<mul; i++) ans.push_back(curr);
            
            curr = temp;
            target = temp;
        }
        

        if (target!=0){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << ans.size() << endl;
            for (int num : ans) cout << num << " ";
            cout << endl;
        }

    }
}