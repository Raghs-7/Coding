#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a >> b >> c;

        int first = a + (c+1)/2; 
        int second = b + c/2;
        if (first > second) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        } 
    }
    
    return 0;

}