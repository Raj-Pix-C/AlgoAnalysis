#include<bits/stdc++.h>
using namespace std;

int knap(vector<int>&vals, vector<int>&wt, vector<vector<int>> dp, int w, int n){
    if(w <= 0 || n <= 0) return 0;
    if(dp[n][w] != -1) return dp[n][w];

    if(wt[n-1] <= w){
        return dp[n][w] = max(vals[n-1]+knap(vals, wt, dp, w-wt[n-1], n-1), knap(vals, wt, dp, w, n-1));
    }else {
        return dp[n][w] = knap(vals, wt, dp, w, n-1);
    }
}

int main(){
    vector<int>vals = /*{2,2,6,5};*/ {5,6,4,6,5,2};
    vector<int>wt = /*{1,3,8,4};*/{6,5,6,6,3,7};
    int n, w = 15;
    n = vals.size();
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));

    cout << knap(vals, wt, dp, w, n) << endl;

}