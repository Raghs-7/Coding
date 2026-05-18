#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void fill(vector<vector<int>> &grid, int row, int colm, int num){
    for (int i=0; i<8; i++){
        if (grid[row][i]==0) grid[row][i] = num;
        if (grid[i][colm]==0) grid[i][colm] = num;
    }


    int dis = 1;
    bool flag = true;
    while(flag){
        flag = false;
        if (row-dis>=0 && colm-dis>=0){
            if (grid[row-dis][colm-dis]==0) grid[row-dis][colm-dis] = num;
            flag = true;
        } 
        if (row-dis>=0 && colm+dis<8 ){
            if (grid[row-dis][colm+dis]==0) grid[row-dis][colm+dis] = num;
            flag = true;
        }
        if (row+dis<8 && colm-dis>=0 ){
            if (grid[row+dis][colm-dis]==0) grid[row+dis][colm-dis] = num;
            flag = true;
        }
        if (row+dis<8 && colm+dis<8){
            if (grid[row+dis][colm+dis]==0) grid[row+dis][colm+dis] = num;
            flag = true;
        }
        dis++;
    }
}

void remove(vector<vector<int>> &grid, int row, int colm, int num){
    for (int i=0; i<8; i++){
        if (grid[row][i]==num) grid[row][i] = 0;
        if (grid[i][colm]==num) grid[i][colm] = 0;
    }

    int dis = 1;
    bool flag = true;
    while(flag){
        flag = false;
        if (row-dis>=0 && colm-dis>=0){
            if (grid[row-dis][colm-dis]==num) grid[row-dis][colm-dis] = 0;
            flag = true;
        }
        if (row-dis>=0 && colm+dis<8 ){
            if (grid[row-dis][colm+dis]==num) grid[row-dis][colm+dis] = 0;
            flag = true;
        }
        if (row+dis<8 && colm-dis>=0 ){
            if (grid[row+dis][colm-dis]==num) grid[row+dis][colm-dis] = 0;
            flag = true;
        }
        if (row+dis<8 && colm+dis<8 ){
            if (grid[row+dis][colm+dis]==num) grid[row+dis][colm+dis] = 0;
            flag = true;
        }
        dis++;
    }
}

void solve(vector<vector<int>> &grid, int row, int &ans){
    if (row==7){
        for (int i=0; i<8; i++){
            if (grid[row][i]==0){
                ans++;
            }
        }
        return;
    }


    for (int i=0; i<8; i++){
        if (grid[row][i]==0){
            grid[row][i] = row;
            fill(grid, row, i, row);
            solve(grid, row+1, ans);
            remove(grid, row, i, row);
            grid[row][i] = 0;
        }
    }
}


int main(){

    vector<vector<int>> grid(8, vector<int>(8, 0));

    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            char c;
            cin >> c;
            if (c=='*'){
                grid[i][j] = -1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    
    int ans = 0;
    solve(grid, 0, ans);

    cout << ans << endl;


    return 0;
}