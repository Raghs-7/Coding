#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void move(int n, int source, int intermediate, int destination){
    if (n==1){
        cout << source << " " << destination << endl;
        return;
    }
    else {
        move(n-1, source, destination, intermediate);
        cout << source << " " << destination << endl;
        move(n-1, intermediate, source, destination);
        return ;
    }
}

int main(){

    int n;
    cin >> n;


    int temp = 1;
    for (int i=1; i<n; i++){
        temp = 2*temp + 1;
    }

    cout << temp << endl;
    move(n, 1, 2, 3);

    return 0;
}