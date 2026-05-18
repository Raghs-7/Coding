#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<vector<int>> res(n, vector<int>(n, -1));

    vector<set<int>> memor(n, set<int>({0}));
    vector<set<int>> memoc(n, set<int>({0}));
    for (int i=0; i<n; i++){
        res[0][i] = i;
        memor[0].insert(i);
        memoc[i].insert(i);
        
        res[i][0] = i;
        memor[i].insert(i);
        memoc[0].insert(i);  

        res[i][i] = 0;
    }

    
    for (int row=0; row<n; row++){
        for (int colm=0; colm<n; colm++){
            if (res[row][colm]==-1){
                int temp = 0;
                while(memor[row].find(temp)!=memor[row].end() || memoc[colm].find(temp)!=memoc[colm].end()){
                    temp++;
                }
                res[row][colm] = temp;
                memor[row].insert(temp);
                memoc[colm].insert(temp);
            }
        }
    }


    for (vector<int> v : res){
        for (int num : v){
            cout << num << " ";
        }
        cout << endl;
    }




}