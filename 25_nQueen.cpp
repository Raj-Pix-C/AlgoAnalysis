#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int cb[MAX][MAX], row[MAX], ldiag[2*MAX], rdiag[2*MAX];

int nqueen(int col, int n){
    if(col == n) return 1;
    
    for(int r = 0; r < n; r++){
        if(row[r] == 0 && ldiag[r+col] == 0 && rdiag[n-1+col-r] == 0){
            // try
            cb[r][col] = 1;
            row[r] = ldiag[r+col] = rdiag[n-1+col-r] = 1;
            
            if(nqueen((col+1), n)) return 1;
            
            //backtrack if fail
            cb[r][col] = 0;
            row[r] = ldiag[r+col] = rdiag[n-1+col-r] = 0;
            
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    
    if(n < 4){
        cerr << "no solution!" << endl;
        return 0;
    }
    
    
    memset(cb, 0, sizeof(cb));
    memset(row, 0, sizeof(row));
    memset(ldiag, 0, sizeof(ldiag));
    memset(rdiag, 0, sizeof(rdiag));
    
    nqueen(0, n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << cb[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
