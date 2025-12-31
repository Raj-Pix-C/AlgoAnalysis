#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>vals = /*{5,6,4,6,5,2}*/ {1, 2, 4};
    vector<int>wt = /*{6,5,6,6,3,7}*/{3, 1, 2};
    int N, W = 4;
    N = vals.size();
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

    for(int n = 1; n <= N; n++){
        for(int w = 1; w <= W; w++){
            if(wt[n-1] <= w){
                dp[n][w] = max(dp[n-1][w], vals[n-1]+dp[n-1][w-wt[n-1]]);
            } else {
                dp[n][w] = dp[n-1][w];
            }
            
        }
    }

    cout << dp[N][W] << endl;
    for(int n = 0; n <= N; n++){
        for(int w = 0; w <= W; w++){
            cout << dp[n][w] << " ";
        }cout << endl;
    }
}
