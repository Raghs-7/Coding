#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i=0; i<n1; i++) L[i] = arr[left+i];
    for (int j=0; j<n2; j++) R[j] = arr[mid+1+j];

    int i=0, j=0, k=left;
    while (i<n1 && j<n2){
        if (L[i]<=R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i<n1) arr[k++] = L[i++];
    while (j<n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right){
    if (left>=right) return;

    int mid = left + (right-left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main(){
    int n;
    cin >> n;

    vector<int> arr;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    mergeSort(arr, 0, n-1);
    
    int distinctCount = 1;
    int prev = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] != prev){
            distinctCount++;
            prev = arr[i];
        }
    }
    cout << distinctCount << endl;
}