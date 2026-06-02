#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void merge(vector<int> &idx, vector<int> &b, int low, int mid, int high){

    vector<int> temp;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {

        if ( b[idx[i]]
            <=  b[idx[j]] ) {

            temp.push_back(idx[i]);
            i++;
        }
        else {
            temp.push_back(idx[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(idx[i]);
        i++;
    }

    while (j <= high) {
        temp.push_back(idx[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++)
        idx[low + k] = temp[k];
}

void mergeSort(vector<int>& idx, vector<int> &b, int low, int high){
    if (low>=high) return;
    
    int mid = low + (high-low)/2;

    mergeSort(idx, b, low, mid);
    mergeSort(idx, b, mid+1, high);

    merge(idx, b, low, mid, high);

}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, p;
        cin >> n >> p;

        vector<int> a(n, 0);
        vector<int> b(n, 0);

        for (int i=0; i<n; i++) cin >> a[i];
        a.push_back(n);

        for (int i=0; i<n; i++) cin >> b[i];
        b.push_back(p);

        vector<int> idx(n+1, 0);
        for (int i=0; i<=n; i++){
            idx[i] = i;
        }

        mergeSort(idx, b, 0, n);

        long long cost = p;
        int left = n-1;
        int i = 0;

        while(left>0){
            cost += (long long) b[idx[i]]* (min(left, a[idx[i]]));
            left -= a[idx[i]]; 
            i++;
        }
        cout << cost << endl;
    }
}