#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;


// gray_code(n) = (append 0 in gray_code(n-1)) and (append 1 in mirror gray code (n-1))

// gray_code(1) = 0, 1
// mirror gray_code(1) = 1, 0;

// gray code (2) = 00, 01,  11, 10

void printBits(int num , int n){
    int t = 1 << (n-1);
    string res = "";
    while(t>0){
        if (t & num){
            res += "1";
        }
        else{
            res += "0";
        }
        t >>=1;
    }

    cout << res << endl;
}


vector<int> gray_code(int n){
    if (n==1){
        return {0, 1};
    }
    
    vector<int> res = gray_code(n-1);

    int k = res.size();
    int temp = 1<<(n-1);
    for (int i=k-1; i>=0; i--){
        res.push_back(res[i] | temp);
    }

    return res;
}

int main(){

    int n;
    cin >> n;

    vector<int> result = gray_code(n);

    for (int i=0; i<result.size(); i++){
        printBits(result[i], n);
    }

    return 0;
}