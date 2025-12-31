#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

vector<int> read(string name){
    ifstream inFile(name);
    vector<int> arr;

    if(inFile.is_open()){
        string buff;
        int temp;
        while(getline(inFile, buff, '\n')){
            temp = stoi(buff);
            arr.push_back(temp);
        }
    }
    else{
        cerr << "Error opening file!\n";
    }
    return arr;
}
void vPrint(const vector<int>& arr){
    for(auto& x : arr){
        cout << x << " ";
    }cout << endl;
}

int Rand(int low, int high){
    unsigned seed = steady_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    uniform_int_distribution<int>distribution(low, high);
    return distribution(generator);
}
int partition(vector<int>& arr, int low , int high){
    
    // int pivLoc = Rand(low, high);
    int pivLoc = low + rand()%(high-low+1);
    swap(arr[high],arr[pivLoc]);
    int pivot = arr[pivLoc];
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

void randQuickSort(vector<int>& arr, int low, int high){
    if(low<high){
        int p = partition(arr, low, high);

        randQuickSort(arr, low, p-1);
        randQuickSort(arr, p+1, high);

    }
}

void write(string name, const vector<int>& arr){
    ofstream outFile(name);
    if(outFile.is_open()){
        for(auto& x : arr)
        outFile << x << endl;
    }
    else{
        cerr << "Write Failed\n";
    }
    return;
}

int main(){
    string filename = "rem.txt";
    // string filename = "sorted.txt";
    vector<int> arr = read(filename);

    int n = 10000;

    auto start = chrono::high_resolution_clock::now();
    randQuickSort(arr, 0, n-1);
    auto end = chrono::high_resolution_clock::now();

    //vPrint(arr);
    write("sorted.txt", arr);
    auto dur = duration_cast<milliseconds>(end-start);
    cout << "time: " << dur.count() << "ms" << endl;
}