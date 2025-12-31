#include<iostream>
#include<vector>
#include<ctime>
#include<chrono>
#include<random>
#include<cstring>
#include<fstream>
#include<algorithm>

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

void insertionSort(vector<int>&arr){
    int size = arr.size();
    int key, j;
    for(int i = 1; i < size; i++){
        j = i-1;
        key = arr[i];

        while(j >= 0 and arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printV(const vector<int>&arr){
    for(auto& x: arr){
        cout << x << " ";
    }cout << endl;
}

int main(){
    auto start = chrono::high_resolution_clock::now();

    int n;
    string filename;
    //cin >> n >> filename;
    n = 1000; filename = "rem.txt";

    vector<int>arr = (readTest(filename));
    insertionSort(arr);
    printV(arr);

    auto end = chrono::high_resolution_clock::now();
    auto dur = duration_cast<milliseconds>(end-start);
    cout << "time spent: " << dur.count() << "ms\n";
}