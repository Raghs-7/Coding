#include<iostream>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int row, colm;
        cin >> row >> colm;

        long long layer = max(row, colm);
        long long curr = (layer - 1) * (layer - 1);

        if(row > colm){

            if(row % 2){
                curr += colm;
            }
            else{
                curr = layer * layer;
                curr -= (colm - 1);
            }

        }
        else{

            if(colm % 2){
                curr = layer * layer;
                // cout << curr << endl;
                curr -= (row - 1);
            }
            else{
                curr += row;
            }

        }

        cout << curr << endl;
    }

    return 0;
}