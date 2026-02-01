#include<iostream>
#include<vector>
#include<ctime>
#include<chrono>
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

void printV(const vector<int>&arr){
    for(auto& x: arr){
        cout << x << " ";
    }cout << endl;
}

int partition(vector<int>&arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
            
        }
    }
    swap(arr[i+1], arr[high]);
    
    return i+1;
}

void quickSort(vector<int>&arr, int low, int high){
    if(low<high){
        int p = partition(arr, low, high);

        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

int main(){
    

    // int n;
    // string filename;
    // //cin >> n >> filename;
    // n = 10000; filename = "rem.txt";

    // vector<int>arr = (readTest(filename));
    // auto start = chrono::high_resolution_clock::now();
    // quickSort(arr, 0, n-1);
    // auto end = chrono::high_resolution_clock::now();
    // // printV(arr);

    // auto dur = duration_cast<milliseconds>(end-start);
    // cout << "Elapsed time: " << dur.count() << "ms" << endl;



    ifstream infile("rem.txt");
    ofstream outFile("temp.txt");

    if(infile.is_open() && outFile.is_open()){
        string buffer;
        int temp;
        for(int i = 0; i < 5; i++){
            getline(infile, buffer);
            outFile << buffer << endl;
            
        }
        
    }
    infile.close();


}
