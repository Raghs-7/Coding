#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        vector<int> arr;
        int last;
        cin >> last;
        arr.push_back(last);

        int temp;
        for (int i=1; i<n; i++){
            cin >> temp;
            if (temp >= last){
                arr.push_back(temp);
            } else {
                arr.push_back(temp);
                arr.push_back(temp);
            }
            last = temp;
        }

        cout << arr.size() << endl;
        for (int num : arr) cout << num << " ";
        cout << endl;
    }
}