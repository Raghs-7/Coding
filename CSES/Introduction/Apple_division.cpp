#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solution(int idx, vector<int> &arr, long long &ans, long long &total, long long curr){
    if (idx==arr.size()){
        if (ans > abs(total - 2*curr)) ans = abs(total - 2*curr);
        return;
    }

    solution(idx+1, arr, ans, total, curr); // not pick 
    solution(idx+1, arr, ans, total, curr + arr[idx]); // pick
    return;
}


int main(){

    int n;
    cin >>n;

    long long total = 0;
    vector<int> arr(n, 0);

    for (int i=0; i<n; i++){
        cin >> arr[i];
        total += arr[i];
    }

    long long ans = total;
    long long curr = 0;

    solution(0, arr, ans, total, curr);

    cout << ans << endl;
    return 0;
}