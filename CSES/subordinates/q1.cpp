#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int n;
     
    cin >> n;

    vector<int> dp(n, -1);
    for (int i=0; i<n-1; i++){
        int temp;
        cin >> temp;
        dp[temp-1] = 0; 
    }
    dp[0] = n-1;

    int bottom_nodes = 0;
    for (int num : dp){
        if (num==-1){
            bottom_nodes++;
        }
    }
    
    int level = 1;
    int j = n-1;
    while(j>=0){
        int temp = 0;
        for (; temp<bottom_nodes && j>=0; j--){
            if (dp[j]==0){
                dp[j] = level;
                temp++;
            }
        }
        level++;
    }
    
    for (int i=0; i<n; i++){
        if (dp[i]==-1) cout << 0 << " ";
        else cout << dp[i] << " ";
    }
    cout << endl;
}