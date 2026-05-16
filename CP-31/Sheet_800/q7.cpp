#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m; 
        cin >> m;

        string x, s;

        cin >> x >> s;

        int result = 100;
        for (int i=0; i<n; i++){
            int loops = 1;
            int flag = 1;
            int idx = i;
            for (int j=0; j<m; j++, idx++){
                if (idx == n){
                    idx = 0;
                    loops++;
                }
                if (s[j] != x[idx]){
                    flag = 0;
                    break;
                }
            }
            if (flag){
                int temp = 1;
                int operations = 0;
                while(loops > temp){
                    temp = temp << 1;
                    operations++;
                }

                result = min(result, operations);
            }
        }

        if (result == 100) cout << -1 << endl;
        else cout << result << endl;
    }
}