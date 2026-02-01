#include<bits/stdc++.h>
using namespace std;

vector<bool> flag;

void sieve(int n, set<int>&primes){
    for(int i = 2; i <= n; i++){
        if(flag[i]){
            primes.insert(i);

            for(int j = i+i; j <= n; j+=i){
                flag[j] = 0;
            }
        }
    }
}

int main(){
    int n; 
    cout << "To print all prime numbers in the range [2, n]. input n: ";
    
    cin >> n;
    set<int> primes;
    flag.resize(n, true);

    sieve(n, primes);

    for(auto& x: primes) cout << x << " ";
    cout << endl;
}