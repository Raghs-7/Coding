#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int a = n-1;
        int b = n+1;
        if (a%3==0 || b%3==0) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    return 0;
}