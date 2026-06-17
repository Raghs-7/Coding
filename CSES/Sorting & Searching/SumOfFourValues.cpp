#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr(n, {0, 0});

    for (int i=0 ; i<n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    sort(arr.begin(), arr.end());

    bool done = false;
    if (n<4){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    } 


    for (int i=0; i<n-3; i++){
        if (done) break;
        for (int j=i+1; j<n-2 ; j++){
            if (done) break;
            int low = j+1;
            int high = n-1;
            int target = x - arr[i].first - arr[j].first;

            if (target < arr[low].first + arr[low+1].first) continue;
            if (target > arr[high].first + arr[high-1].first) continue;

            while(low<high){
                int temp = arr[low].first + arr[high].first;

                if (temp<target){
                    low++;
                } else if (temp==target){
                    done = true;
                    cout << arr[i].second << " " << arr[j].second << " " << arr[low].second << " " << arr[high].second << endl;
                    break;
                } else {
                    high--;
                }
            }
        }
    }    
    
    if (!done) cout << "IMPOSSIBLE" << endl;

    return 0;
}