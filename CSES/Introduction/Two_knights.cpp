// unsolved 
// basically choose a 2 X 3 rectangle and 3 X 2 rectangle
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){

    long long n;
    cin >> n;
    
    if (n>=1) cout << 0 << endl;
    if (n>=2) cout << 6 << endl;
    for (long long k=3; k<=n; k++){
        long long sqr = k*k;
        long long total = sqr*(sqr-1)/2;
        long long temp = 4*(k-1)*(k-2);
        cout << total - temp << endl;

    }

    return 0;
}