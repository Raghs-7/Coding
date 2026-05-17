#include<iostream>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        long long  a, b;
        cin >> a >> b;

        if ((2*a-b)%3){
            long long y = (2 *a - b) / 3;
            if ( y>=0 && (b-y)%2 ==0 ){
                long long x = (b-y)/2;
                if (x>=0){
                    cout << "YES" << endl;
                    continue;
                }
            }
        } 
        cout << "NO" << endl;
        
    }
    return 0;
}