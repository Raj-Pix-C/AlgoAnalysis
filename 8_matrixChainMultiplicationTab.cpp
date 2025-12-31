#include<bits/stdc++.h>
using namespace std;

int matrixChainOrder(const vector<int>& arr, int n, vector<vector<int>>& parens) {
    vector<vector<int>> memo(n, vector<int>(n));


    for (int i = 0; i < n; ++i) memo[i][i] = 0;

    for (int len = 2; len < n; ++len) {
        for (int i = 1; i < n-len+1; ++i) {
            int j = i+len-1;
            memo[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = memo[i][k]+memo[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(cost < memo[i][j]){
                    memo[i][j] = cost;
                    parens[i][j] = k;
                }
                
            }
        }
    }
    return memo[1][n-1];
}

string optimumParens(int i, int j, vector<vector<int>>& parens){
    if(i == j) return "A"+to_string(i);
    else return "("+optimumParens(i, parens[i][j], parens)+" x "+optimumParens(parens[i][j]+1, j,parens)+")";
}

int main(){
    int n = 4;
    vector<int> arr(n);
    arr = { 2,1,3,4} ;
    vector<vector<int>> parens(n, vector<int>(n, -1));

    cout << matrixChainOrder(arr, n, parens) << endl;
    cout << optimumParens(1, n-1, parens) << endl;
}
