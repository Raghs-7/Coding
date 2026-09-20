#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int n;
    cin >> n;

    ll sum = 0;
    vector<ll> arr(n);

    ll maxi = 0, sec_maxi=0;

    for (int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
        
        if (arr[i] > maxi){
            swap(sec_maxi, maxi);
            maxi = arr[i];
        } else if (arr[i] > sec_maxi) {
            sec_maxi = arr[i];
        }
    }

    ll tar1 = sum - 2*maxi;
    ll tar2 = sum - 2*sec_maxi;

    vector<int> res;
    for (int j=1; j<=n; j++){
        ll aj = arr[j-1];
        if (aj!=maxi && aj==tar1){
            res.push_back(j);
        }
    }

    if (maxi + 2*sec_maxi == sum){
        for (int j=1; j<=n; j++){
            ll aj = arr[j-1];
            if (aj == maxi){
                res.push_back(j);
            }
        }
    }

    cout << res.size() << endl;
    
    for (auto it : res){
        cout << it << " ";
    } cout << endl;




    // a0, a1, a2, ..... an  ---- aj
    //      sum - aj              aj
    // if (aj == largest) then secound_largest = sum - aj - secound_largest
    // else largest = sum - aj - largest


    //  aj = sum - 2*largest (if aj!=largest)
    //  aj = sum - 2*secound_largest

}