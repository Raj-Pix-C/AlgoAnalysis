#include<random>
#include<string>
#include<chrono>
#include<fstream>
#include <climits>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main(){
    auto startT = chrono::high_resolution_clock::now();
    string fileName;
    fileName = "randomNumbers1B.txt";

    int n = INT_MAX;
    ofstream outFile(fileName);

    if(!outFile){
        cerr << "Failed to open write file!\n";
    }
    else{
        unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
        mt19937 generator(seed);
        uniform_int_distribution<int> distribution(-n, n);
        int temp;

        for(long long i = 0; i < 1000000000; i++){
            temp = distribution(generator);
            outFile << temp << endl;
        }
        cout << "Succesful\n";
    }
    auto endT = chrono::high_resolution_clock::now();
    auto dur = duration_cast<seconds>(endT-startT);
    cout << "Time: " << dur.count() << "s" << endl;
}