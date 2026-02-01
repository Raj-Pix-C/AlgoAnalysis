#include<bits/stdc++.h>
using namespace std;

int modExp(int a, int n, int m){
    if(n == 0) return 1;

    int x = modExp(a, n/2, m);
    if(n % 2 == 0) return (x*x)%m;
    else return (x*x*a)%m;
}

int main(){
    long long d, h, q, hashT, hashP, i, j, n, m;
    string P, T;

    cin >> T >> P;
    n = T.size(), m = P.size();

    q = 251;
    d = 256;
    h = modExp(d, m-1, q) % q;
    hashP = hashT = 0;

    for(i = 0; i < m; i++){
        hashP = (d*hashP + P[i]) % q;
        hashT = (d*hashT + T[i]) % q;
    }

    for(i = 0; i <= n-m; i++){
        if(hashT == hashP){
            for(j = 0; j < m; j++){
                if(T[i+j] != P[j]) break;
            }

            if(j == m){
                cout << "match found at index: " << i << endl;
            }
        }

        if(i < n-m){   
            hashT = (d*(hashT - h*T[i]) + T[i+m]) % q;
            if(hashT < 0) hashT += q;
        }

    }
}