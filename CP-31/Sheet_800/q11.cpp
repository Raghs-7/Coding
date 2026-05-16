#include<iostream>
#include<vector>

using namespace std;


int main(){

    int n;
    cin >> n;

    int result = __INT_MAX__;
    int temp;
    for (int i=0; i<n; i++){
        cin >> temp;
        result = min(result, abs(temp));
    }

    cout << result << endl;

}