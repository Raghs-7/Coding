#include<iostream>
#include<vector>

using namespace std;

void fill(int left, int right, int up, int down, vector<vector<int>>&matrix, int val){
    for (int i=up; i<=down; i++){
        matrix[i][left] = val;
        matrix[i][right] = val;
    }

    for (int i=left; i<=right; i++){
        matrix[up][i] = val;
        matrix[down][i] = val;
    }
}

int main(){

    int t;
    cin >> t;

    vector<vector<int>> target(10, vector<int>(10, 0));

    int low = 0;
    int high = 9;
    int val = 1;
    while(low<high){
        fill(low, high, low, high, target, val);
        low++;
        high--;
        val++;
    }
    
    while(t--){
        int result = 0;
        char temp;
        for (int i=0; i<10; i++){
            for (int j=0; j<10; j++){
                cin >> temp;
                if (temp == 'X'){
                    result += target[i][j];
                }    
            }
        }

        cout << result << endl;
    }
}