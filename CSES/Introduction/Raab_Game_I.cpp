#include<iostream>
#include<vector>

using namespace std;
  


void solve(vector<int> &player, int a, int b, int n){
    // assuming b is the loss and a is the win
    // b > a
    // player1 --> 1, 2, 3, 4 ... n
    // player2 --> -1, -1, -1,.... n


    int num = a+1;
    int idx = 0;
    while(num<=b){
        player[idx] = num;
        num++, idx++;
    }
    while(idx<b){
        player[idx] = num;
        idx++, num++;
    }

    for (int i=b; i<n-a; i++){
        player[i] = i+1;
    }

}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, a, b;
        cin >> n >> a >> b;

        vector<int> player1(n, 0);
        vector<int> player2(n, 0);

        if (a+b>n){
            cout << "NO" << endl;
        } else {
            // solve();
            if (a>b){
                for (int i=0; i<n; i++){
                    player1[i] = i+1;
                }
                solve(player2, b, a, n);

            } else {
                for (int i=0; i<n; i++){
                    player2[i] = i+1;
                }
                solve(player1, a, b, n);
   
            }
        }

        int win=0, loss=0;
        for(int i=0; i<n; i++){
            if (player2[i]>player1[i]) win++;
            else if (player2[2]<player1[i]) loss++;
        }

        if (win==b && loss==a){
            cout << "YES" << endl;
            // for (int i=0; i<n; i++){
            //     cout << player1[i] << " ";
            // } cout << endl;
            // for (int i=0; i<n; i++){
            //     cout << player2[i] << " ";
            // } cout << endl;
        }
        else cout << "NO" << endl;

        for (int i=0; i<n; i++){
            cout << player1[i] << " ";
        } cout << endl;
        for (int i=0; i<n; i++){
            cout << player2[i] << " ";
        } cout << endl;

    }

    return 0;
}