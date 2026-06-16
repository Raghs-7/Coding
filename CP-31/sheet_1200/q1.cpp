#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){


    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<pair<int, int>> a(3, {0, 0});
        vector<pair<int, int>> b(3, {0, 0});
        vector<pair<int, int>> c(3, {0, 0});

        int temp;
        for (int i=0; i<n; i++){
            cin >> temp;

            int j=2; 
            pair<int, int> t;
            t.first = temp;
            t.second = i;
            while(j>=0 ){
                if ( t.first>a[j].first ){
                    swap(a[j].first, t.first);
                    swap(a[j].second, t.second);
                }
                j--;
            }
        }
        for (int i=0; i<n; i++){
            cin >> temp;

            int j=2; 
            pair<int, int> t;
            t.first = temp;
            t.second = i;
            while(j>=0  ){
                if (t.first>b[j].first){
                    swap(b[j].first, t.first);
                    swap(b[j].second, t.second);
                }
                j--;
            }
        }
        for (int i=0; i<n; i++){
            cin >> temp;
            
            int j=2; 
            pair<int, int> t;
            t.first = temp;
            t.second = i;
            while(j>=0 ){
                if (t.first>c[j].first){
                    swap(c[j].first, t.first);
                    swap(c[j].second, t.second);
                }
            j--;
            }
        }

        long long ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {

                    int dayA = a[i].second;
                    int dayB = b[j].second;
                    int dayC = c[k].second;

                    if (dayA != dayB && dayB != dayC && dayA != dayC) {
                        long long temp = a[i].first + b[j].first + c[k].first;
                        ans = max(ans, temp);
                    }
                }
            }
        }

        cout << ans << endl;

    }

    return 0;
}