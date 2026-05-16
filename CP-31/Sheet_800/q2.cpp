#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int x;
        cin >> n >> x;
        vector<int> arr(n);

        for (int i=0; i<n; i++) cin >> arr[i];

        int curr = arr[0];
        for (int i=1; i<n; i++){
            int temp = arr[i];
            arr[i] = arr[i] - curr;
            curr = temp;
        }


        int ans = 0;
        for (int num : arr){
            ans = max(ans, num);
        }
        
        ans = max(ans, 2*(x-curr));

        cout << ans << endl;
        

    }
}