#include<bits/stdc++.h>
using namespace std;

int matrixChainMemo(vector<int>& arr, int i, int j, vector<vector<int>>& memo, vector<vector<int>>& parenthesis){
    if(i == j) return 0;
    if(memo[i][j] != -1) return memo[i][j];

    memo[i][j] = INT_MAX;
    for(int k = i; k < j; k++){
        int res = matrixChainMemo(arr, i, k, memo, parenthesis)
                + matrixChainMemo(arr, k+1, j, memo, parenthesis)
                + arr[i-1]*arr[k]*arr[j];

        if(res < memo[i][j]){
            memo[i][j] = res;
            parenthesis[i][j] = k;
        }
    }
    return memo[i][j];
}

string optimumParenthesis(int i, int j, vector<vector<int>>& parenthesis){
    if(i == j) return "A"+to_string(i);
    else return "("+optimumParenthesis(i, parenthesis[i][j], parenthesis)+" x "+optimumParenthesis(parenthesis[i][j]+1, j, parenthesis)+")";
}

int main(){
    int n; cin >> n;
    vector<int>arr(n);
    vector<vector<int>>memo(n, vector<int>(n, -1));
    vector<vector<int>>parenthesis(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        memo[i][i] = 0;
        parenthesis[i][i] = -1;
    }

    int minCost = matrixChainMemo(arr, 1, n-1, memo, parenthesis);
    string order = optimumParenthesis(1, n-1, parenthesis);

    cout << "minimum multiplication : " << minCost << endl;
    cout << "optimum parenthesization : " << order << endl;

    for(int i =0 ; i<n;i++){for(int j=0;j<n;j++)cout << memo[i][j]<<" ";cout<<endl;}
}
