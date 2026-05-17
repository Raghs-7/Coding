#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){


    int n;
    cin >> n;

    int NumberOfFive = n/5;
    int power = (int) log(n)/log(5);
    n = n/5;

    while(n>0){
        NumberOfFive += n/5;
        n = n/5;
    }

    cout << NumberOfFive << endl;

    return 0;
}