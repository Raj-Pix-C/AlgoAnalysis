#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main(){
    int n = 4;
    vector<int>dp(n+1);
    dp[0] = 0;

    vector<int> prices(n);
    prices = {1, 5, 8, 9};

    for (int i = 1; i <= n; i++)
    {
        int ans = INT_MIN;
        for(int j = 1; j <= i; j++){
            ans = max(ans, prices[j-1]+dp[i-j]);
        
        }
        dp[i] = ans;
        
    }
    cout << dp[n] << endl;
     
}