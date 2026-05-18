#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void move(vector<vector<int>> &grid, int row, int colm, int num, queue<pair<int, int>> &q){

    // move(grid, row-2, colm-1, num+1);
    // move(grid, row-2, colm+1, num+1);
    // move(grid, row-1, colm-2, num+1);
    // move(grid, row-1, colm+2, num+1);
    // move(grid, row+1, colm-2, num+1);
    // move(grid, row+1, colm+2, num+1);
    // move(grid, row+2, colm-1, num+1);
    // move(grid, row+2, colm+1, num+1);

    vector<int> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> dy = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int i = 0; i < 8; i++) {
        if (row + dx[i] >= 0 && row + dx[i] < grid.size() && colm + dy[i] >= 0 && colm + dy[i] < grid[0].size() && grid[row + dx[i]][colm + dy[i]] == -1) {
            grid[row + dx[i]][colm + dy[i]] = num;
            q.push({row + dx[i], colm + dy[i]});
        }
    }

}


int main(){

    queue<pair<int, int>> q;
    int n;
    cin >> n ;
    vector<vector<int>> grid(n, vector<int>(n, -1));

    q.push({0, 0});
    grid[0][0] = 0;
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        int row = curr.first;
        int colm = curr.second;
        int num = grid[row][colm];

        move(grid, row, colm, num+1, q);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}