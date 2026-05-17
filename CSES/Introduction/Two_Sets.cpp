#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    
    long n;
    cin >> n;

    long target = (n)*(n+1)/2;

    if (target%2){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        vector<int> result(n+1, 0);

        int idx = n;
        target = target/2;
        int cnt = 0;
        while(target!=0){
            if (idx<=target){
                target = target - idx;
                result[idx] = 1;
                cnt++;
            } 
            idx--;
        }

        cout << cnt << endl;

        for (int i=1; i<=n; i++){
            if (result[i]) cout << i << " ";
        }
        cout << endl;

        cout << n-cnt << endl;
        for (int i=1; i<=n; i++){
            if (!result[i]) cout << i << " ";
        } cout << endl;


    }
    
    
    
    return 0;
}