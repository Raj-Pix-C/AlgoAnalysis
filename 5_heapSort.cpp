#include<bits/stdc++.h>
using namespace std;

int parent(int i){
    return i/2;
}
int left(int i){
    return 2*i;
}
int right(int i){
    return 2*i+1;
}

void maxHeapify(vector<int>& arr, int i, int n){
    int l = left(i);
    int r = right(i);
    int largest;

    if(l <= n and arr[l] > arr[i]){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r <= n and arr[r] > arr[largest]){
        largest = r;
    }

    if(i != largest){
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, n);
    }
    
}

void buildMaxHeap(vector<int>& arr, int n){
    for(int i = n/2; i >= 1; i--){
        maxHeapify(arr, i, n);
    }
}

void heapSort(vector<int>& arr, int n){
    buildMaxHeap(arr, n);

    for(int i = n; i >= 2; i--){
        swap(arr[1], arr[i]);
        maxHeapify(arr, 1, i-1);
    }
}


int main(){
    int n; cin >> n;
    vector<int>arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    heapSort(arr, n);

    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}

