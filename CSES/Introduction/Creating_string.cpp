#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void f(vector<int> &memo, string curr, set<string> &res){
    bool flag = true;
    for (int i=0; i<26; i++){
        if (memo[i]>0){
            flag = false;
            memo[i]--;
            f(memo, curr+char(i+'a'), res);
            memo[i]++;
        }
    }
    if (flag) res.insert(curr);
    return;
}

int main(){


    string s;
    cin >> s;

    vector<int> memo(26, 0);

    for (int i=0; i<s.size(); i++){
        memo[s[i]-'a']++;
    }

    set<string> res;

    f(memo, "", res);

    cout << res.size() << endl;

    for (string s : res){
        cout << s << endl;
    }

    return 0;
}