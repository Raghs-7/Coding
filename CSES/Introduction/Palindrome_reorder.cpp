#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    string s;
    cin >> s;

    vector<int> memo(26,0);

    for(char c : s){
        memo[c-'A']++;
    }

    int cnt = 0;
    char char_odd;

    for(int i=0; i<26; i++){
        if(memo[i] % 2){
            cnt++;
            char_odd = 'A' + i;
        }
    }

    if(cnt > 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string first_half = "";

    for(int i=0; i<26; i++){
        for(int j=0; j<memo[i]/2; j++){
            first_half += ('A' + i);
        }
    }

    string second_half = first_half;
    reverse(second_half.begin(), second_half.end());

    string ans = first_half;

    if(cnt == 1){
        ans += char_odd;
    }

    ans += second_half;

    cout << ans << endl;

    return 0;
}