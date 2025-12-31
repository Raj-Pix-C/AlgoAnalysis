#include<iostream>
#include<vector>
#include<chrono>
#include<fstream>
#include<cstring>

using namespace std;
using namespace std::chrono;

vector<int> readTest(string name){
    ifstream inFile(name);
    vector<int>arr;

    if(!inFile){
        cerr << "Failed to open file!" << endl;
    }
    else{
        
        string buff;
        while(getline(inFile, buff, '\n')){
            int temp = stoi(buff);
            arr.push_back(temp);
        }
    }
    return arr;
}

void merge(vector<int>& arr, int left, int mid, int right){
    int nL = mid-left+1;
    int nR = right-mid;

    vector<int> L(nL), R(nR);

    for(int i = 0; i < nL; i++){
        L[i] = arr[left+i];
    }
    for(int i = 0; i < nR; i++){
        R[i] = arr[mid+1+i];
    }

    int i, j, k;
    i = j = 0;
    k = left;

    while (i < nL and j < nR){
        arr[k++] = L[i] <= R[j] ? L[i++] : R[j++];
    }
    
    while (i < nL){
        arr[k++] = L[i++];
    }
    while (j < nR){
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    if(left < right){
        int mid = (left+right)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

void printV(const vector<int>&arr){
    for(auto& x: arr){
        cout << x << " ";
    }cout << endl;
}

int main(){
    auto start = chrono::high_resolution_clock::now();
    string filename;
    filename = "rem.txt";

    vector<int>arr = (readTest(filename));
    mergeSort(arr, 0, arr.size()-1);
    printV(arr);
    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end-start);
    cout << "Time elapsed: " << duration.count() << "ms\n";
    return 0;
}