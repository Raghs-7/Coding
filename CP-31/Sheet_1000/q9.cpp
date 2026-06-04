#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b; // Safe from overflow for typical ranges
}   

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a = 1;
        pair<int, int> res = {a, n-a};
        int mini = lcm(a, n-a);
        
        
        while(a<(n/2+1)){
            int temp = lcm(a, n-a);

            if (temp < mini) {
                res = {a, n-a};
                mini = temp;
            }
            a++;
        }

        cout << res.first << " " << res.second << endl;
    }

    return 0;
}