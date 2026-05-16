#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;
    if(n==1){
        cout << 1 << endl;
        return 0;
    }

    if (n<=3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }


    vector<int> result;
    int curr = 2;
    while(curr<=n){
        result.push_back(curr);
        curr += 2;
    }

    curr = 1;
    while(curr<=n){
        result.push_back(curr);
        curr += 2;
    }


    for (int i=0; i<n; i++){
        cout << result[i] << " ";
    }
    cout << endl;
    

    return 0;
}