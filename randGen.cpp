#include<iostream>
#include<random>
#include<cstring>
#include<fstream>
#include<chrono>

using namespace std;
using namespace std::chrono;

void createTest(int n, string name){

    ofstream outFile(name);

    if(outFile){
        unsigned seed =chrono::steady_clock::now().time_since_epoch().count();
        mt19937 generator(seed);
        uniform_int_distribution<int> distribution(-n,n);
        int temp;
        for(int i = 0; i < n; i++){
            temp = distribution(generator);
            outFile << temp << endl;
        }
        cout << "Test genarated successfully.\n";
    }
    else{
        cerr << "Failed to open file!" << endl;
    }
    
}


int main(){
    auto start = chrono::high_resolution_clock::now();
    createTest(10000, "rem.txt");
    auto end = chrono::high_resolution_clock::now();
    auto dur = duration_cast<milliseconds>(end-start);
    cout << "time spent: " << dur.count() << "ms\n";
}